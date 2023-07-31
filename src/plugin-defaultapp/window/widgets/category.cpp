//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#include "category.h"
#include <QDebug>
#include <QDir>
#include <dirent.h>
Category::Category(QObject *parent)
    : QObject(parent)
{
}

QPair<QString, bool> readfiles(QString filename){
   qDebug() << filename;
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return QPair<QString, bool>("InvalidFile", 0);
    }
    QTextStream in(&file);
    QString line;
    QPair<QString, bool> ret;
    ret.second = false;
//    qDebug() << in.atEnd();
    int nm=1;
    while(!in.atEnd()){
        line = in.readLine();
        // qDebug() << " line is " << line;
        if(line.left(5) == "Name=" && nm==1){
            ret.first = line.mid(5);
            
            nm=0;
        }else if(line.left(7) == "Hidden="){
            ret.second = (line.mid(7) != "false");
//            break;
        }
    }
    qDebug() << "Name is " << ret.first<<Qt::endl;
    return ret;
}

QList<App> Category::getappItem(){
    qDebug()<<"getappItem go"<< Qt::endl;
    if(m_category != QString("SelfSetUp")){
        m_category = QString("SelfSetUp");
    }

    DIR *pDir;
    struct dirent* ptr;
    if(!(pDir = opendir((QDir::homePath() + QString("/.config/autostart")).toStdString().c_str()))){
        qDebug()<<"Folder doesn't Exist!"<<Qt::endl;
        return QList<App>();
    }
    while((ptr = readdir(pDir))!=0) {
        if(ptr->d_name[0] == '.'){
            continue;
        }
        qDebug() << "filename is "<<ptr->d_name << Qt::endl;
        QPair<QString, bool> ans= readfiles(QDir::homePath() +  QString("/.config/autostart/") + QString(ptr->d_name));
        
        if(ans.first == "InvalidFile"){
            continue;
        }
        
        App app;
        app.Name = ans.first;
        app.Id =  QString(ptr->d_name);
        app.Hidden = ans.second;
        if(!m_appList.contains(app)) 
            m_appList.push_back(app);
        qDebug() << app.Name<<Qt::endl;
        // Q_EMIT addedUserItem(app);
    }
    closedir(pDir);
    qDebug() << m_appList.size();
    
    return m_appList;
}

void Category::setDefault(const App &def)
{
    if (m_default.Id != def.Id) {
        m_default = def;
        Q_EMIT defaultChanged(def);
    }
}

void Category::setCategory(const QString &category)
{
    if (m_category == category)
        return;

    m_category = category;
    Q_EMIT categoryNameChanged(category);
}

void Category::clear()
{
    bool clearFlag = !m_appList.isEmpty();

    m_appList.clear();
    if (clearFlag)
        Q_EMIT clearAll();
}

void Category::addUserItem(const App &value)
{

    if (m_appList.contains(value)) return;
    
    m_appList << value;


    
    Q_EMIT addedUserItem(value);

}

void Category::delUserItem(const App &value)
{
    if(!m_appList.contains(value)) return;

    bool isRemove = m_appList.removeOne(value);
    if(isRemove) Q_EMIT removedUserItem(value);
    
}

void Category::reverseUserItem(const App &value){
    qDebug() << "reverse in category"<<Qt::endl;
    int idx = m_appList.indexOf(value);
    if (idx == -1) return;
    m_appList[idx].Hidden = !m_appList[idx].Hidden;
    
    Q_EMIT reversedUserItem(m_appList[idx]);
}