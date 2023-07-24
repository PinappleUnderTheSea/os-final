//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#include "category.h"
#include <QDebug>

Category::Category(QObject *parent)
    : QObject(parent)
{

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
    bool clearFlag = !m_applist.isEmpty();

    m_applist.clear();
    if (clearFlag)
        Q_EMIT clearAll();
}

void Category::addUserItem(const App &value)
{

    if (m_applist.contains(value)) return;
    
    m_applist << value;


    
    Q_EMIT addedUserItem(value);

}

void Category::delUserItem(const App &value)
{
    if(!m_applist.contain(value)) return

    bool isRemove = m_applist.removeOne(value);
    if(isRemove) Q_EMIT removedUserItem(value);
    
}

void Category::reverseUserItem(const APP &value){
    int idx = m_applist.indexOf(value);
    if (idx == -1) return;
    m_applist[idx].Hidden = !m_applist[idx].Hidden

    Q_EMIT reversedUserItem(value);
}