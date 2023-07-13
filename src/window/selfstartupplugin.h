// SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef SelfStartupPlugin_H
#define SelfStartupPlugin_H

#include "defappworker.h"
#include "interface/pagemodule.h" //to_add!!(below3)
#include "interface/plugininterface.h"
#include "interface/vlistmodule.h"

class DefAppModel;

// 默认程序插件
class SelfStartupPlugin : public DCC_NAMESPACE::PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.deepin.dde.ControlCenter.SelfSartup" FILE "selfstartup.json")
    Q_INTERFACES(DCC_NAMESPACE::PluginInterface)
public:
    explicit SelfStartupPlugin() { }

    virtual QString name() const override;
    virtual DCC_NAMESPACE::ModuleObject *module() override;
    virtual QString location() const override;
};

// 一级菜单
class SelfStartupModule : public DCC_NAMESPACE::VListModule
{
    Q_OBJECT
public:
    explicit SelfStartupModule(QObject *parent = nullptr);
    ~SelfStartupModule() override;

    DefAppWorker *work() { return m_work; }

    DefAppModel *model() { return m_model; }

protected:
    virtual void active() override;

private:
    DefAppModel *m_model;
    DefAppWorker *m_work;
    ModuleObject *m_defApps;
};

// 三级菜单
class SelfStartupDetailModule : public DCC_NAMESPACE::ModuleObject
{
    Q_OBJECT
public:
    SelfStartupDetailModule(DefAppWorker::DefaultAppsCategory category,
                       DefAppModel *model,
                       DefAppWorker *work);
    virtual QWidget *page() override;

private:
    DefAppModel *m_model;
    DefAppWorker *m_work;
};

#endif // SelfStartupPlugin_H