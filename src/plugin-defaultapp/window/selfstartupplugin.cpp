#include "selfstartupplugin.h"

#include "addbuttonwidget.h"
#include "selfstartupdetailwidget.h"
#include "defappmodel.h"
#include "defappworker.h"
#include "widgets/widgetmodule.h"

#include <DFloatingButton>
#include <DStyle>

#include <QApplication>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE
using namespace DCC_NAMESPACE;

struct DATE
{
    QString name;
    QString displayName;
    QString icon;

    DATE(const QString &_name,
         const QString &_displayName,
         const QString &_icon)
        : name(_name)
        , displayName(_displayName)
        , icon(_icon)
    {
    }
};

QString SelfStartupPlugin::name() const
{
    return QStringLiteral("Self Startup");
}

ModuleObject *SelfStartupPlugin::module()
{
    // 一级页面
    SelfStartupModule *moduleRoot = new SelfStartupModule;

    // 三级页面
    SelfStartupDetailModule *selfstartupDetail = new SelfStartupDetailModule(moduleRoot->model(), moduleRoot->work());
    moduleRoot->appendChild(selfstartupDetail);

    // 加号键
    ModuleObject *addButton =
            new WidgetModule<AddButtonWidget>("selfstartuplistAddbtn",
                                              "addSelfStartupApp",
                                              [moduleRoot](AddButtonWidget *button) {
                                                  button->setModel(moduleRoot->model());
                                                  connect(button,
                                                          &AddButtonWidget::requestCreateFile,
                                                          moduleRoot->work(),
                                                          &DefAppWorker::onAddUserFile);
                                              });
    addButton->setExtra();
    moduleRoot->appendChild(addButton);

    return moduleRoot;
}

//|location()|插件位置索引或前一个ModuleObject的name，相同索引则按加载顺序进行排序，先加载的往后顺延，默认追加到最后|
QString SelfStartupPlugin::location() const
{
    return "4";
}


SelfStartupModule::SelfStartupModule(QObject *parent)
    : VListModule("selfstartup", tr("Self Start-up"), QIcon::fromTheme("dcc_nav_selfstartup"), parent)
    , m_model(new DefAppModel(this))
    , m_work(new DefAppWorker(m_model, this))
    , m_defApps(nullptr)
{
}

SelfStartupModule::~SelfStartupModule()
{
    m_model->deleteLater();
    m_work->deleteLater();
}

void SelfStartupModule::active()
{
    m_work->onGetListApps();
}

// 三级页面
SelfStartupDetailModule::SelfStartupDetailModule(DefAppWorker::DefaultAppsCategory category,
                                                DefAppModel *model,
                                                DefAppWorker *work)
    : ModuleObject("SelfStartupApplist")
    , m_category(category)
    , m_model(model)
    , m_work(work)
{
}

QWidget *SelfStartupDetailModule::page()
{
    SelfStartupDetailWidget *selfDetail = new SelfStartupDetailWidget();
    selfDetail->setModel(m_model);
    
    // 设置默认程序 change to 设置初始是否自启动
    connect(selfDetail,
            &SelfStartupDetailWidget::reverseItem,
            m_work,
            &DefAppWorker::onReverseUserApp);

    connect(selfDetail, &SelfStartupDetailWidget::requestDelUserApp, m_work, &DefAppWorker::onDelUserApp);
    
    return selfDetail;
}