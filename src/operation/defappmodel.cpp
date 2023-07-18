//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
#include "defappmodel.h"

DefAppModel::DefAppModel(QObject *parent)
    :QObject(parent)
{
    m_modSelfSetUp = new Category(this);

}

DefAppModel::~DefAppModel()
{
    m_modSelfSetUp->deleteLater();

}


