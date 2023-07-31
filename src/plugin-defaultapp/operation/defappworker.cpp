//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#include "defappworker.h"
#include "defappmodel.h"
#include <QDBusPendingCall>
#include <QStringList>
#include <QList>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

DefAppWorker::DefAppWorker(DefAppModel *model, QObject *parent) :
    QObject(parent),
    m_defAppModel(model),
    m_dbusManager(new MimeDBusProxy(this))
{

    m_stringToCategory.insert("SelfSetUp",     SelfSetUp);


    connect(m_dbusManager, &MimeDBusProxy::Change, this, &DefAppWorker::onGetListApps);

    m_userLocalPath = QDir::homePath() + ".config/autostart";

}

void DefAppWorker::active()
{
    m_dbusManager->blockSignals(false);
}

void DefAppWorker::deactive()
{
    m_dbusManager->blockSignals(true);
}

void DefAppWorker::onReverseUserApp(const QString &mime, const App &item)
{
    Category *category  = getCategory(mime);

    

    QFile file(m_userLocalPath + item.Id);
    QFile outfile(m_userLocalPath + item.Id);
    
//    qDebug() << path;
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << QString("can not change") ;
        return ;
    }
    QTextStream in(&file);
    QVector<QString> contents;
    QString line;
    while(!in.atEnd()){
        line = in.readLine();
        if(line.left(7) == "Hidden="){
            qDebug() << line;
            if(line.right(4) != "true" ){
                line = line.left(7) + QString("true");
            }else{
                line = line.left(7) + QString("false");
            }
            qDebug() << QString("change");
        }
        contents.push_back(line);
    }

    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << QString("can not change") ;
        return ;
    }
    QTextStream out(&outfile);
    for(int i=0; i<contents.size();i++){
        out << contents[i] << QString("\n");
    }

    category->reverseUserItem(item);
    
    return;

}

void DefAppWorker::onGetListApps(){
    //TODO: unknown usage 
    return ;
}


void DefAppWorker::onDelUserApp(const QString &mime, const App &item)
{
    Category *category = getCategory(mime);

    category->delUserItem(item);
    
    QFile file(m_userLocalPath + item.Id);
    file.remove();
    

}

void DefAppWorker::onAddUserFile(const QString &mime, const QFileInfo &info)
{
    const bool isDesktop = info.suffix() == "desktop";
    Category *category = getCategory(mime);
    if (isDesktop) {
        QFile file(info.filePath());
        QString newfile = m_userLocalPath + info.fileName();
        file.copy(newfile);
        QTextStream out(&file);

        out << "Hidden=false"<<Qt::endl;
        out.flush();

        file.close();

        
        QFileInfo fileInfo(info.filePath());

        const QString &filename =  fileInfo.completeBaseName() + ".desktop";


        App app;
        app.Id = filename;
        app.Name = fileInfo.baseName();
        app.DisplayName = fileInfo.baseName();
        app.Icon = "application-default-icon";
        app.Description = "";
        app.Exec = info.filePath();
        app.isUser = true;
        app.Hidden = false;

        category->addUserItem(app);

        onGetListApps();
    } else {
        QFile file(m_userLocalPath + info.baseName() + ".desktop");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }

        QTextStream out(&file);
        out << "[Desktop Entry]\n"
            "Type=Application\n"
            "Version=1.0\n"
            "Name=" + info.baseName() + "\n"
            "Path=" + info.path() + "\n"
            "Exec=" +  info.filePath() + "\n"
            "Icon=application-default-icon\n"
            "Terminal=false\n"
            "Hidden=false"
#if (QT_VERSION < QT_VERSION_CHECK(5,15,0))
            << endl;
#else
            << Qt::endl;
#endif
        out.flush();
        file.close();


        QFileInfo fileInfo(info.filePath());

        App app;
        app.Id = m_userLocalPath + fileInfo.baseName() + ".desktop";
        app.Name = fileInfo.baseName();
        app.DisplayName = fileInfo.baseName();
        app.Icon = "application-default-icon";
        app.Description = "";
        app.Exec = info.filePath();
        app.isUser = true;
        app.Hidden = false;

        category->addUserItem(app);

        onGetListApps();
    }

}



Category *DefAppWorker::getCategory(const QString &mime) const
{
    switch (m_stringToCategory[mime]) {
    case SelfSetUp:
        return m_defAppModel->getModSelfSetUp();
    }
    return nullptr;
}