//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#ifndef DEFAPPMODEL_H
#define DEFAPPMODEL_H

#include "interface/namespace.h"
#include "category.h"

class Category;
class DefAppModel : public QObject
{
    Q_OBJECT
public:
    explicit DefAppModel(QObject *parent = 0);
    ~DefAppModel();

    Category *getModSelfSetUp()     {return m_modSelfSetUp;}


private:
    Category *m_modSelfSetUp;

};
#endif // DEFAPPMODEL_H