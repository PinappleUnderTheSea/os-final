//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later

#include <interface/moduleobject.h>
#include "widgets/dcclistview.h"

#include "selfstartupdetailwidget.h"
#include "defappmodel.h"
#include "defappworker.h"

#include <DFloatingButton>
#include <DListView>
#include <DStyle>

#include <QVBoxLayout>
#include <QDebug>
#include <QStandardItemModel>
#include <QIcon>
#include <QMimeDatabase>
#include <QPointer>

DWIDGET_USE_NAMESPACE

SelfStartupDetailWidget::SelfStartupDetailWidget(QWidget *parent)
    : QWidget(parent)
    , m_centralLayout(new QVBoxLayout)
    , m_selfApps(new DCC_NAMESPACE::DCCListView)
    , m_model(new QStandardItemModel(this))
    , m_appCnt(0)
{
    m_selfApps->setAccessibleName("List_selfapplist");
    m_selfApps->setEditTriggers(QListView::NoEditTriggers); //Qlistview 双击默认是编辑条目，即使doubleclicked已经connect了别的函数。此时只需setEditTriggers 属性设置成NoEditTriggers 即可
    m_selfApps->setIconSize(QSize(32, 32));
    m_selfApps->setMovement(QListView::Static);
    m_selfApps->setSelectionMode(QListView::NoSelection);
    m_selfApps->setFrameShape(QFrame::NoFrame);
    m_selfApps->setModel(m_model); // 和下面的setmodel不是同一个
    m_selfApps->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //!!maybe change：此时设置为不能滑动
    m_selfApps->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //!!maybe change

    m_centralLayout->setContentsMargins(0, 0, 20, 0); //设置左侧、顶部、右侧和底部边距，以便在布局周围使用
    m_centralLayout->addWidget(m_selfApps, 1); // 将给定的小部件添加到单元格网格的行、列。
    setLayout(m_centralLayout);
}

SelfStartupDetailWidget::~SelfStartupDetailWidget()
{
}

void SelfStartupDetailWidget::setModel(DefAppModel *const model)//设置分类（需要删除分类）
{
    setCategory(model->getModSelfSetUp());
}

/**
 * Sets the category for the SelfStartupDetailWidget.
 *
 * @param category a pointer to the Category object
 *
 * @throws ErrorType description of error
 */
void SelfStartupDetailWidget::setCategory(Category *const category) //!!to_see
{
    m_category = category;

    connect(m_category, &Category::reversedUserItem, this, &SelfStartupDetailWidget::onReverseItem);
    connect(m_category, &Category::addedUserItem, this, &SelfStartupDetailWidget::addItem);
    connect(m_category, &Category::removedUserItem, this, &SelfStartupDetailWidget::removeItem);
    // connect(m_category, &Category::clearAll, this, &SelfStartupDetailWidget::onClearAll);

    AppsItemChanged(m_category->getappItem());

    onReverseItem();
}

/**
 * Retrieves the application icon with the specified size.
 *
 * @param appIcon the path or name of the application icon
 * @param size the desired size of the icon
 *
 * @return the application icon as a QIcon object
 *
 * @throws None
 */
QIcon SelfStartupDetailWidget::getAppIcon(const QString &appIcon, const QSize &size)
{
    QIcon icon(appIcon);
    if (icon.pixmap(size).isNull())
        icon = QIcon::fromTheme(appIcon, QIcon::fromTheme("application-x-desktop"));

    const qreal ratio = devicePixelRatioF();
    QPixmap pixmap = icon.pixmap(size * ratio).scaled(size * ratio, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixmap.setDevicePixelRatio(ratio);

    return pixmap;
}

/**
 * Adds an item to the SelfStartupDetailWidget.
 *
 * @param item The App object to add.
 *
 * @throws ErrorType description of error
 */
void SelfStartupDetailWidget::addItem(const App &item)
{
    qDebug() << Q_FUNC_INFO << item.Id << ", isUser :" << item.isUser;
    appendItemData(item);
    updateListView();
}

void SelfStartupDetailWidget::removeItem(const App &item)
{
    qDebug() << "SelfStartupDetailWidget::removeItem id " << item.Id;
    //update model
    int cnt = m_model->rowCount();
    for (int row = 0; row < cnt; row++) {
        QString id = m_model->data(m_model->index(row, 0), DefAppIdRole).toString();
        if (id == item.Id) {
            m_model->removeRow(row);
            m_appCnt--;
            break;
        }
    }

    updateListView();
}

/**
 * Shows icons in the SelfStartupDetailWidget.
 *
 * @param modelItem a pointer to DStandardItem
 * @param name the name of the item
 * @param iconName the name of the icon
 *
 * @throws None
 */
void SelfStartupDetailWidget::showInvalidText(DStandardItem *modelItem, const QString &name, const QString &iconName)
{
    if (name.isEmpty())
        return;

    DViewItemActionList actions;
    QPointer<DViewItemAction> act(new DViewItemAction(Qt::AlignVCenter | Qt::AlignLeft, QSize(32, 32), QSize(), false));
    QIcon icon = getAppIcon(iconName, QSize(32, 32));
    act->setIcon(icon);
    act->setTextColorRole(DPalette::TextWarning);
    act->setIconText(name);
    actions << act;
    modelItem->setActionList(Qt::LeftEdge, actions);
}


/**
 * Updates the list view with the given default app.
 *
 * @param defaultApp the default app to update the list view with
 *
 * @throws None
 */
void SelfStartupDetailWidget::updateListView()
{
    int cnt = m_model->rowCount();
    for (int row = 0; row < cnt; row++) {
        DStandardItem *modelItem = dynamic_cast<DStandardItem *>(m_model->item(row));
        QString id = modelItem->data(DefAppIdRole).toString();
        bool isUser = modelItem->data(DefAppIsUserRole).toBool();
        bool canDelete = modelItem->data(DefAppCanDeleteRole).toBool();
        QString name = modelItem->data(DefAppNameRole).toString();
        QString iconName = modelItem->data(DefAppIconRole).toString();
        bool Hidden = modelItem->data(DefAppHiddenRole).toBool();

        if (Hidden == false) { 
            modelItem->setCheckState(Qt::Checked);
        } else {
            modelItem->setCheckState(Qt::Unchecked);
        }
        
        //add user clear button
        // if (!isUser && !canDelete)
        //     continue;

        DViewItemActionList btnActList; //!!change delete btn location
        QPointer<DViewItemAction> delAction(new DViewItemAction(Qt::AlignVCenter | Qt::AlignHCenter , QSize(21, 21), QSize(19, 19), true));
        
        delAction->setIcon(DStyleHelper(style()).standardIcon(DStyle::SP_CloseButton, nullptr, this));
        connect(delAction, &QAction::triggered, this, &SelfStartupDetailWidget::onDelBtnClicked);
        btnActList << delAction;
        modelItem->setActionList(Qt::RightEdge, btnActList);
        m_actionMap.insert(delAction, id);
        showInvalidText(modelItem, name, iconName);
    }
}


/**
 * Handles the action of reversing an item.
 *
 * @throws ErrorType description of error
 */
void SelfStartupDetailWidget::onReverseItem()
{
    // qDebug() << Q_FUNC_INFO << app.Name;
    updateListView();
}


/**
 * Updates the AppsItem widget with the given list of App objects.
 *
 * @param list A QList of App objects representing the list of apps to be updated.
 *
 * @return void
 *
 * @throws None
 */
void SelfStartupDetailWidget::AppsItemChanged(const QList<App> &list)
{
    for (const App &app : list) {
        appendItemData(app);
    }

    connect(m_selfApps, &DListView::clicked, this, &SelfStartupDetailWidget::onListViewClicked);
    connect(m_selfApps, &DListView::activated, m_selfApps, &QListView::clicked);
}

/**
 * The function handles the click event of the list view in the `SelfStartupDetailWidget`.
 *
 * @param index The index of the clicked item in the list view.
 *
 * @throws None
 */
void SelfStartupDetailWidget::onListViewClicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    QString id = m_selfApps->model()->data(m_selfApps->currentIndex(), DefAppIdRole).toString();
    App app = getAppById(id);
    if (!isValid(app))
        return;

    qDebug()  <<  "set default app "  << app.Name;
    updateListView();
    //set default app
    Q_EMIT reverseItem(m_category->getName(), app);
}

/**
 * Handles the click event of the delete button in the SelfStartupDetailWidget.
 * 
 * @throws ErrorType if the action is not found in the action map.
 */
void  SelfStartupDetailWidget::onDelBtnClicked()
{
    DViewItemAction *action = qobject_cast<DViewItemAction *>(sender());
    if (!m_actionMap.contains(action))
        return;

    QString id = m_actionMap[action];

    App app = getAppById(id);
    if (!isValid(app) || !(app.isUser || app.CanDelete))
        return;

    qDebug() << "delete app " << app.Id;
    //delete user app
    Q_EMIT requestDelUserApp(m_category->getName(), app);
}

void SelfStartupDetailWidget::onClearAll()
{
    int cnt = m_model->rowCount();
    m_model->removeRows(0, cnt);
    m_appCnt = 0;
}

App SelfStartupDetailWidget::getAppById(const QString &appId)
{
    auto res = std::find_if(m_category->getappItem().cbegin(), m_category->getappItem().cend(), [ = ](const App & item)->bool{
        return item.Id == appId;
    });

    if (res != m_category->getappItem().cend()) {
        return *res;
    }

    App app;
    app.Id = nullptr;
    return app;
}

/**
 * Appends item data to the SelfStartupDetailWidget.
 *
 * @param app The App object containing the data to be appended.
 *
 * @throws None
 */
void SelfStartupDetailWidget::appendItemData(const App &app) 
{
    qDebug() << "appendItemData=" << app.MimeTypeFit;
    DStandardItem *item = new DStandardItem;
    QString appName = app.Name;
    if (!app.isUser || app.MimeTypeFit) {
        item->setText(appName);
        item->setIcon(getAppIcon(app.Icon, QSize(32, 32)));
    } else {
        item->setData(appName, DefAppNameRole);
        item->setData(app.Icon, DefAppIconRole);
    }

    item->setData(app.Id, DefAppIdRole);
    item->setData(app.isUser, DefAppIsUserRole);
    item->setData(app.CanDelete, DefAppCanDeleteRole);
    item->setData(app.Hidden, DefAppHiddenRole);

    int index = m_appCnt;
    m_appCnt++;

    m_model->insertRow(index, item);
}

/**
 * Determines if the given file name represents a desktop or binary file.
 *
 * @param fileName The name of the file to check.
 *
 * @return True if the file is a desktop file, false otherwise.
 *
 * @throws None.
 */
bool SelfStartupDetailWidget::isDesktopOrBinaryFile(const QString &fileName)
{
    QMimeDatabase mimeDatabase;
    if (mimeDatabase.suffixForFileName(fileName) == "desktop") {
        return true;
    }

    QMimeType mimeType(mimeDatabase.mimeTypeForFile(fileName, QMimeDatabase::MatchExtension));
    return mimeType.name().startsWith("application/octet-stream");
}

/**
 * Check if the given `App` object is valid.
 *
 * @param app The `App` object to be validated.
 *
 * @return `true` if the `App` object is valid, `false` otherwise.
 *
 * @throws None
 */
bool SelfStartupDetailWidget::isValid(const App &app)
{
    return (!app.Id.isNull() && !app.Id.isEmpty());
}