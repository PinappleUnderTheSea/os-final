//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later


#ifndef DEFAPPWORKER_H
#define DEFAPPWORKER_H

#include <QObject>
#include <QMap>

#include "mimedbusproxy.h"
#include "category.h"

class QFileInfo;

class DefAppModel;
class Category;
class DefAppWorker : public QObject
{
    Q_OBJECT
public:
    explicit DefAppWorker(DefAppModel *m_defAppModel, QObject *parent = 0);

    enum DefaultAppsCategory {
        SelfSetUp
    };

    void active();
    void deactive()

public Q_SLOTS:
    void onReverseUserApp(const QString &category, const App &item);
    void onGetListApps();
    void onDelUserApp(const QString &mine, const App &item);
    void onAddUserFile(const QString &mime, const QFileInfo &info);



private:
    DefAppModel *m_defAppModel;
    MimeDBusProxy  *m_dbusManager;
    QMap<QString, DefaultAppsCategory> m_stringToCategory;
    QString m_userLocalPath;

private:
    Category* getCategory(const QString &mime) const;
};

#endif // DEFAPPWORKER_H
