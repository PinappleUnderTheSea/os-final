//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#ifndef CATEGORY_H
#define CATEGORY_H

#include "include/interface/namespace.h"

#include <QObject>
#include <QList>

struct App {
    QString Id;
    QString Name;
    QString DisplayName;
    QString Description;
    QString Icon;
    QString Exec;
    bool Hidden;
    bool isUser;
    bool CanDelete;
    bool MimeTypeFit;
    
    App() : isUser(true), CanDelete(false), MimeTypeFit(false),Hidden(false) {}

    bool operator ==(const App &app) const {
        return app.Id == Id || app.Name == Name;
    }

    bool operator !=(const App &app) const {
        return app.Id != Id && app.Name != Name;
    }
};

class Category : public QObject
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = 0);

    void setDefault(const App &def);

    const QString getName() const { return m_category;}
    void setCategory(const QString &category);
    QList<App> getappItem() ;//TODO: read from disk

    inline const App getDefault() { return m_default;}
    void clear();
    void addUserItem(const App &value);
    void delUserItem(const App &value);
    void reverseUserItem(const App &value);

Q_SIGNALS:
    void defaultChanged(const App &id);
    void addedUserItem(const App &app);
    void removedUserItem(const App &app);
    void reversedUserItem(const App &app);

    void categoryNameChanged(const QString &name);
    void clearAll();

private:
    QList<App> m_appList;
    QString m_category;
    App m_default;
};
#endif // CATEGORY_H