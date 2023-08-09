# DDE控制中心自启动插件 项目文档

队员：复旦大学 朱元依、沈扬、朱俊杰
指导老师：张亮、陈辰
企业导师：王子冲

[toc]



## 1 摘要

`Deepin`(原名`Linux Deepin`)致力于为全球用户提供美观易用，安全可靠的`Linux`发行版。该系统由深度科技自主开发，提供了美观易用、极简操作的桌面环境，主要由桌面、启动器、任务栏、控制中心、窗口管理器等组成。其中，控制中心是`Deepin`桌面环境的核心组件之一，它是用于管理和配置操作系统各种设置的集成工具。然而，在该控制中心中，并未对用户提供自启动项提供的便捷管理界面。在本项目中，我们为`Deepin`操作系统中自启动项的修改功能编写了简洁易用的控制中心插件，将自启动管理的系统功能集成到了控制中心中。该插件以单独的仓库提供，并能够单独构建，一键植入`Deepin`控制中心中。

## 2 需求分析

最终用户对自启动权限的管理目前只能通过`dde-launcher`（启动器/“开始菜单”）的右键菜单进行管理，而控制中心作为控制系统的门户应用反而缺少此功能。

**用户需求**

在官方发布的deepin23-Beta版本中，对于用户程序与系统程序的自启动管理方法为：找到应用的可执行程序（通常为.desktop）类型的文件，通过右键打开功能菜单的方式设置为开机自启动。但由于操作系统自带的应用程序界面中所有程序都会被展示到，所以当操作系统中应用程序过多的时候用户很难统计到那些程序被设置成了开机自启动，同时对于用户不想参与管理的应用也会展示在应用菜单中。因此我们对于本项目开发所面向的需求是在控制中心（deepin-control-center）中在不影响原有插件所提供的设置服务的基础上，为用户提供一个额外的插件用于管理开机自启动软件，同时插件可以满足用户自行选择需要手动维护的自启动程序，对于用户希望自己管理是否自启动的软件显示在面板上可以对是否自启动进行开关，用户不希望管理的软件默认不自启动不显示到面板；面板也可以提供添加和删除的功能让用户挑选出自己想要在面板上操作的应用。

**功能需求**

deepin作为国产开源的深度Linux桌面系统，不仅为用户提供了人性化、个性化以及对于中文等语言有良好支持的操作系统体验，也为Linux的开发者与学习者提供了控制中心（dde-control-center）与任务栏（dde-dock）等桌面控件的开发者接口与插件注入接口。除了可以不断的扩展完善用户需求与用户体验外，deepin深度桌面在操作系统学科的教学与深入理解方面也带来了很多的可能性与创造性。因此作为OS大赛的参与团队，我们不仅是在希望我们的开发会对deepin项目的完整性、deepin用户的体验感上带来一些帮助，同时也想通过我们自己的努力在学生的视角让操作系统的教学与后续学习有一个优秀的案例和一些开发相关的经验总结，使得我们理论层面的操作系统教学可以有更大的实践空间。

### 2.1 当前方案

目前已有的自启动管理方法是在开始菜单中对菜单中所展示应用软件单独进行自启动的设置。具体的方法是对所希望设置自启动项的应用软件选中后右键，点击“设置开机自启动”即可在每次开机时自动打开该应用软件。

// **TODO**: 把开始菜单贴图进去

然而，这种方法有两大明显的缺陷：（1）无法向用户展示所有的自启动项设置（2）大批量的自启动项修改极其不便。由此，催生了控制中心自启动管理插件的需求。

### 2.2 插件需求

为了完成控制中心插件，我们对需求进行了更细致的刻画。经过总结后，插件的需求主要分为三条：

1、完成一个控制中心插件，能够展示当前所有开机启动项的列表；
2、能够在插件中，通过用户界面的交互来管理（添加、删除、启用、禁用）开机启动项；
3、插件以单独的仓库提供，并能够单独构建，不需要合并入 dde-control-center 项目。

其中，第一条需求是该插件的基础。自启动项的列表一方面为用户提供了清晰的展示界面，另一方面也是程序与用户交互，获取修改操作信息的基础。
第二条需求总结了该插件需要支持的功能，即添加、删除、启用、禁用，这些功能需要在前端设计对应的交互界面，同时在后端设计对应的操作接口，调用系统接口以修改自启动设置。
第三条需求与系统发布相关。目前最新的稳定发布版本是`Deepin V23 Beta`，而官方版本已经在发布，若修改源码统一编译控制中心，会需要对当前已发行的操作系统版本进行修改，较为不便。故需要单独编译该插件，并将其装载到系统中的插件接口中。

## 3 相关资料调研

### 3.1 Deepin开机自启动系统设置

`Deepin`系统通过检测固定的目录，检测自启动项。通过放置应用程序的`.desktop`文件在其中一个自动启动目录中，系统可以检测到该应用程序的自启动设置。通过修改`.desktop`文件中的对应字段，可以修改对应应用程序的自启动设置。

#### 3.1.1 自启动目录

在["desktop base directory specification"](http://standards.freedesktop.org/basedir-spec/)中的["Referencing this specification"](http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html#referencing) 部分进行定义了自动启动目录是 `$XDG_CONFIG_DIRS/autostart`。

如果同一文件名位于多个自动启动目录下，只应使用最重要目录下的文件。

示例：
如果未设置`$XDG_CONFIG_HOME`，用户主目录中的自动启动目录为`~/.config/autostart/`。

如果未设置`$XDG_CONFIG_DIRS`，系统范围的自动启动目录为`/etc/xdg/autostart/`。

如果未设置`$XDG_CONFIG_HOME`和`$XDG_CONFIG_DIRS`，并且两个文件`/etc/xdg/autostart/foo.desktop`和 `~/.config/autostart/foo.desktop`存在，那么只有文件`~/.config/autostart/foo.desktop`将被使用，因为`~/.config/autostart/`比`/etc/xdg/autostart/`更重要。

#### 3.1.2 应用程序的`.desktop `文件

一个应用程序的`.desktop`文件必须符合"桌面入口规范"中定义的格式。所有关键字应按照定义进行解释，但以下情况除外，以便考虑到位于自动启动目录中的`.desktop`文件不会显示在菜单中。

##### `Hidden`关键字

当`.desktop`文件的`Hidden`关键字设置为`true`时，该`.desktop`文件必须被忽略。当多个具有相同名称的`.desktop`文件存在于多个目录中时，仅应考虑最重要的`.desktop`文件中的`Hidden`关键字：如果其设置为`true`，则其他目录中具有相同名称的所有`.desktop`文件也必须被忽略。

##### `OnlyShowIn`和`NotShowIn`关键字

`OnlyShowIn`项可以包含一个字符串列表，用于标识必须自动启动此应用程序的桌面环境，其他桌面环境不得自动启动此应用程序。

`NotShowIn`项可以包含一个字符串列表，用于标识不得自动启动此应用程序的桌面环境，其他桌面环境必须自动启动此应用程序。

这两个关键字中的一个，要么是`OnlyShowIn`，要么是`NotShowIn`，可以出现在单个`.desktop`文件中。

##### `TryExec`关键字 

带有非空`TryExec`字段的`.desktop`文件如果`TryExec`关键字的值与已安装的可执行程序不匹配，则不得自动启动。`TryExec`字段的值可以是绝对路径，也可以是没有任何路径组件的可执行文件名。如果指定了没有任何路径组件的可执行文件名，则会搜索`$PATH`环境以找到匹配的可执行程序。

##### 注意事项 

如果通过在系统范围的自动启动目录中安装`.desktop`文件来自动启动应用程序，则个人用户可以通过在其个人自动启动目录中放置具有相同名称的`.desktop`文件来禁用此应用程序的自动启动，并在其中包含`Hidden=true`关键字。

### 3.2 控制中心插件开发

##### V23控制中心特性

1、V23控制中心只负责框架设计，具体功能全部由插件实现；
2、V23控制中心支持多级插件系统，支持插件插入到任意位置中；
3、高度可定制，可定制任意插件是否显示，若插件支持，可定制任意插件内容是否显示。

##### V23控制中心插件安装路径说明

1、控制中心会自动加载翻译，翻译目录需要严格放置在`/${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/dde-control-center/translations`下，控制中心会自动加载，同时，插件的翻译和名称也有要求，命名为`${Plugin_name}_{locale}.ts`，`locale`就是多语言的翻译，翻译文件必须控制和插件名称相同；
2、控制中心的so应该放置在`/${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTA；LL_LIBDIR}/dde-control-center/modules`下，请使用构建系统的提供的`gnuinstall`路径，上面举的例子是`cmake`，`mesonbuild`也有自己的逻辑。

##### V23控制中心开发接口说明

1、`ModuleObject`类用于构建每个页面元素，其是插件的核心；
2、`PluginInterface`类用于规范插件信息，每个插件必须提供一个`ModuleObject对象。

##### 标准开发流程示例

1、继承`PluginInterface`，实现其虚函数；
2、实例化一个根模块，根模块在初始化时不允许有耗时操作，若有耗时操作，应继承`ModuleObject`然后实现`active`方法，将耗时操作放入其中；
3、若根模块的子项是横向菜单列表，则可使用`List`储存其基础信息，继承或使用`HListModule`类，然后循环使用`appendChild`方法将菜单添加到根模块中；
4、若根模块的子项是纵向菜单列表，则可使用`List`储存其基础信息，继承或使用`VListModule`类，然后循环使用`appendChild`方法将菜单添加到根模块中；
5、以此类推，具体的某个子项菜单同样再次添加菜单列表，直到菜单列表的子项为`PageModule`时为止；
6、准备一个以上的`Module`继承自`ModuleObject`，并实现其`page()`方法，然后添加到`PageModule`中，注意，`page()`方法中需返回新的`QWidget`对象；
7、当某个菜单为`PageModule`时，使用其`appendChild`方法将上方的`Module`添加到其子项中，此时，控制中心会根据`page`的大小添加滚动条，并将多个`page`进行垂直排列进行显示。`PageModule`持支嵌套，并且其有默认边距，如果嵌套使用，嵌套的`PageModule`边距建议设置为0；
8、若某个`VListModule`或`PageModule`页面需要附加按钮时，可调其子项`ModuleObject`的`setExtra`，该`ModuleObject`的`page`提供按钮，这样该`ModuleObject`将显示在`VListModule`或`PageModule`页面的最下方。

## 4 系统框架设计

**项目文件组织**

```bash
.
├── CMakeLists.txt
├── include
│   ├── interface
│   │   ├── hlistmodule.h
│   │   ├── moduleobject.h
│   │   ├── namespace.h
│   │   ├── pagemodule.h
│   │   ├── plugininterface.h
│   │   └── vlistmodule.h
│   └── widgets
│       ├── accessibleinterface.h
│       ├── buttontuple.h
│       ├── comboxwidget.h
│       ├── dccdbusinterface.h
│       ├── dcclistview.h
│       ├── dccslider.h
│       ├── detailinfoitem.h
│       ├── horizontalmodule.h
│       ├── itemmodule.h
│       ├── lineeditwidget.h
│       ├── listviewmodule.h
│       ├── modulelistmodel.h
│       ├── moduleobjectitem.h
│       ├── settingsgroup.h
│       ├── settingsgroupmodule.h
│       ├── settingshead.h
│       ├── settingsheaderitem.h
│       ├── settingsitem.h
│       ├── switchwidget.h
│       ├── titledslideritem.h
│       ├── titlelabel.h
│       ├── titlevalueitem.h
│       ├── utils.h
│       └── widgetmodule.h
├── misc
│   ├── DdeControlCenterConfig.cmake.in
│   ├── configs
│   │   ├── org.deepin.dde.control-center.accounts.json
│   │   ├── org.deepin.dde.control-center.display.json
│   │   ├── org.deepin.dde.control-center.json
│   │   └── org.deepin.dde.control-center.update.json
│   ├── dde-control-center.desktop
│   ├── developdocument.html
│   ├── gen_report.sh
│   ├── lupdate.sh
│   ├── org.deepin.dde.ControlCenter1.service
│   ├── translate_desktop2ts.sh
│   ├── translate_generation.sh
│   └── translate_ts2desktop.sh
├── shell.sh
├── src
│   ├── frame
│   │   ├── accessible.h
│   │   ├── controlcenterdbusadaptor.cpp
│   │   ├── controlcenterdbusadaptor.h
│   │   ├── listitemdelegate.cpp
│   │   ├── listitemdelegate.h
│   │   ├── listview.cpp
│   │   ├── listview.h
│   │   ├── main.cpp
│   │   ├── mainmodule.cpp
│   │   ├── mainmodule.h
│   │   ├── mainwindow.cpp
│   │   ├── mainwindow.h
│   │   ├── pluginmanager.cpp
│   │   ├── pluginmanager.h
│   │   ├── searchwidget.cpp
│   │   ├── searchwidget.h
│   │   ├── utils.cpp
│   │   └── utils.h
│   ├── interface
│   │   ├── hlistmodule.cpp
│   │   ├── moduledatamodel.cpp
│   │   ├── moduledatamodel.h
│   │   ├── moduleobject.cpp
│   │   ├── pagemodule.cpp
│   │   ├── tabitemdelegate.cpp
│   │   ├── tabitemdelegate.h
│   │   ├── tabview.cpp
│   │   ├── tabview.h
│   │   └── vlistmodule.cpp
│   ├── plugin-selfstartup
│   │   ├── operation
│   │   │   ├── defappmodel.cpp
│   │   │   ├── defappmodel.h
│   │   │   ├── defappworker.cpp
│   │   │   ├── defappworker.h
│   │   │   ├── mimedbusproxy.cpp
│   │   │   ├── mimedbusproxy.h
│   │   │   └── qrc
│   │   │       ├── icons
│   │   │       │   ├── dcc_nav_selfstartup_42px.svg
│   │   │       │   └── dcc_nav_selfstartup_84px.svg
│   │   │       ├── selfstartup.qrc
│   │   │       └── themes
│   │   │           └── dark
│   │   │               └── icons
│   │   │                   ├── nav_selfstartup.svg
│   │   │                   └── nav_selfstartup_normal.svg
│   │   └── window
│   │       ├── selfstartup.json
│   │       ├── selfstartupdetailwidget.cpp
│   │       ├── selfstartupdetailwidget.h
│   │       ├── selfstartupplugin.cpp
│   │       ├── selfstartupplugin.h
│   │       └── widgets
│   │           ├── addbuttonwidget.cpp
│   │           ├── addbuttonwidget.h
│   │           ├── category.cpp
│   │           └── category.h
│   └── widgets
│       ├── accessiblefactoryinterface.h
│       ├── accessibleinterface.cpp
│       ├── buttontuple.cpp
│       ├── comboxwidget.cpp
│       ├── dccdbusinterface.cpp
│       ├── dccdbusinterface_p.h
│       ├── dcclistview.cpp
│       ├── dccslider.cpp
│       ├── detailinfoitem.cpp
│       ├── horizontalmodule.cpp
│       ├── itemmodule.cpp
│       ├── lineeditwidget.cpp
│       ├── listviewmodule.cpp
│       ├── modulelistmodel.cpp
│       ├── moduleobjectitem.cpp
│       ├── settingsgroup.cpp
│       ├── settingsgroupmodule.cpp
│       ├── settingshead.cpp
│       ├── settingsheaderitem.cpp
│       ├── settingsitem.cpp
│       ├── switchwidget.cpp
│       ├── titledslideritem.cpp
│       ├── titlelabel.cpp
│       └── titlevalueitem.cpp
└── translations
    ├── dde-control-center_ady.ts
    ├── dde-control-center_af.ts
    ├── dde-control-center_ak.ts
    ├── dde-control-center_am_ET.ts
    ├── dde-control-center_ar.ts
    ├── dde-control-center_ar_EG.ts
    ├── dde-control-center_ast.ts
    ├── dde-control-center_az.ts
    ├── dde-control-center_bg.ts
    ├── dde-control-center_bn.ts
    ├── dde-control-center_bo.ts
    ├── dde-control-center_br.ts
    ├── dde-control-center_ca.ts
    ├── dde-control-center_cgg.ts
    ├── dde-control-center_cs.ts
    ├── dde-control-center_da.ts
    ├── dde-control-center_de.ts
    ├── dde-control-center_de_CH.ts
    ├── dde-control-center_el.ts
    ├── dde-control-center_en.ts
    ├── dde-control-center_en_AU.ts
    ├── dde-control-center_en_GB.ts
    ├── dde-control-center_en_US.ts
    ├── dde-control-center_eo.ts
    ├── dde-control-center_es.ts
    ├── dde-control-center_es_MX.ts
    ├── dde-control-center_et.ts
    ├── dde-control-center_eu.ts
    ├── dde-control-center_fa.ts
    ├── dde-control-center_fi.ts
    ├── dde-control-center_fil.ts
    ├── dde-control-center_fr.ts
    ├── dde-control-center_gl_ES.ts
    ├── dde-control-center_he.ts
    ├── dde-control-center_hi_IN.ts
    ├── dde-control-center_hr.ts
    ├── dde-control-center_hu.ts
    ├── dde-control-center_hy.ts
    ├── dde-control-center_id.ts
    ├── dde-control-center_it.ts
    ├── dde-control-center_ja.ts
    ├── dde-control-center_ka.ts
    ├── dde-control-center_kab.ts
    ├── dde-control-center_kk.ts
    ├── dde-control-center_km_KH.ts
    ├── dde-control-center_kn_IN.ts
    ├── dde-control-center_ko.ts
    ├── dde-control-center_ku.ts
    ├── dde-control-center_ku_IQ.ts
    ├── dde-control-center_ky.ts
    ├── dde-control-center_ky@Arab.ts
    ├── dde-control-center_la.ts
    ├── dde-control-center_lo.ts
    ├── dde-control-center_lt.ts
    ├── dde-control-center_lv.ts
    ├── dde-control-center_ml.ts
    ├── dde-control-center_mn.ts
    ├── dde-control-center_mr.ts
    ├── dde-control-center_ms.ts
    ├── dde-control-center_nb.ts
    ├── dde-control-center_ne.ts
    ├── dde-control-center_nl.ts
    ├── dde-control-center_pa.ts
    ├── dde-control-center_pam.ts
    ├── dde-control-center_pl.ts
    ├── dde-control-center_ps.ts
    ├── dde-control-center_pt.ts
    ├── dde-control-center_pt_BR.ts
    ├── dde-control-center_ro.ts
    ├── dde-control-center_ru.ts
    ├── dde-control-center_sc.ts
    ├── dde-control-center_si.ts
    ├── dde-control-center_sk.ts
    ├── dde-control-center_sl.ts
    ├── dde-control-center_sq.ts
    ├── dde-control-center_sr.ts
    ├── dde-control-center_sv.ts
    ├── dde-control-center_sw.ts
    ├── dde-control-center_ta.ts
    ├── dde-control-center_te.ts
    ├── dde-control-center_th.ts
    ├── dde-control-center_tr.ts
    ├── dde-control-center_tzm.ts
    ├── dde-control-center_ug.ts
    ├── dde-control-center_uk.ts
    ├── dde-control-center_ur.ts
    ├── dde-control-center_uz.ts
    ├── dde-control-center_vi.ts
    ├── dde-control-center_zh_CN.ts
    ├── dde-control-center_zh_HK.ts
    ├── dde-control-center_zh_TW.ts
    ├── desktop
    │   ├── desktop.ts
    │   ├── desktop_ady.ts
    │   ├── desktop_af.ts
    │   ├── desktop_ak.ts
    │   ├── desktop_am_ET.ts
    │   ├── desktop_ar.ts
    │   ├── desktop_ar_EG.ts
    │   ├── desktop_ast.ts
    │   ├── desktop_az.ts
    │   ├── desktop_bg.ts
    │   ├── desktop_bn.ts
    │   ├── desktop_bo.ts
    │   ├── desktop_br.ts
    │   ├── desktop_ca.ts
    │   ├── desktop_cgg.ts
    │   ├── desktop_cs.ts
    │   ├── desktop_da.ts
    │   ├── desktop_de.ts
    │   ├── desktop_de_CH.ts
    │   ├── desktop_el.ts
    │   ├── desktop_en.ts
    │   ├── desktop_en_AU.ts
    │   ├── desktop_en_GB.ts
    │   ├── desktop_en_US.ts
    │   ├── desktop_eo.ts
    │   ├── desktop_es.ts
    │   ├── desktop_es_419.ts
    │   ├── desktop_es_MX.ts
    │   ├── desktop_et.ts
    │   ├── desktop_fa.ts
    │   ├── desktop_fi.ts
    │   ├── desktop_fil.ts
    │   ├── desktop_fr.ts
    │   ├── desktop_gl_ES.ts
    │   ├── desktop_he.ts
    │   ├── desktop_hi_IN.ts
    │   ├── desktop_hr.ts
    │   ├── desktop_hu.ts
    │   ├── desktop_hy.ts
    │   ├── desktop_id.ts
    │   ├── desktop_it.ts
    │   ├── desktop_ja.ts
    │   ├── desktop_ka.ts
    │   ├── desktop_kab.ts
    │   ├── desktop_kk.ts
    │   ├── desktop_km_KH.ts
    │   ├── desktop_kn_IN.ts
    │   ├── desktop_ko.ts
    │   ├── desktop_ku.ts
    │   ├── desktop_ku_IQ.ts
    │   ├── desktop_ky.ts
    │   ├── desktop_ky@Arab.ts
    │   ├── desktop_la.ts
    │   ├── desktop_lo.ts
    │   ├── desktop_lt.ts
    │   ├── desktop_lv.ts
    │   ├── desktop_ml.ts
    │   ├── desktop_mn.ts
    │   ├── desktop_mr.ts
    │   ├── desktop_ms.ts
    │   ├── desktop_nb.ts
    │   ├── desktop_ne.ts
    │   ├── desktop_nl.ts
    │   ├── desktop_pa.ts
    │   ├── desktop_pam.ts
    │   ├── desktop_pl.ts
    │   ├── desktop_ps.ts
    │   ├── desktop_pt.ts
    │   ├── desktop_pt_BR.ts
    │   ├── desktop_ro.ts
    │   ├── desktop_ru.ts
    │   ├── desktop_sc.ts
    │   ├── desktop_si.ts
    │   ├── desktop_sk.ts
    │   ├── desktop_sl.ts
    │   ├── desktop_sq.ts
    │   ├── desktop_sr.ts
    │   ├── desktop_sv.ts
    │   ├── desktop_sw.ts
    │   ├── desktop_ta.ts
    │   ├── desktop_te.ts
    │   ├── desktop_th.ts
    │   ├── desktop_tr.ts
    │   ├── desktop_tzm.ts
    │   ├── desktop_ug.ts
    │   ├── desktop_uk.ts
    │   ├── desktop_ur.ts
    │   ├── desktop_uz.ts
    │   ├── desktop_vi.ts
    │   ├── desktop_zh_CN.ts
    │   ├── desktop_zh_HK.ts
    │   └── desktop_zh_TW.ts
    ├── keyboard_language_az.ts
    ├── keyboard_language_bo.ts
    ├── keyboard_language_ca.ts
    ├── keyboard_language_cs.ts
    ├── keyboard_language_el.ts
    ├── keyboard_language_en.ts
    ├── keyboard_language_en_US.ts
    ├── keyboard_language_es.ts
    ├── keyboard_language_fi.ts
    ├── keyboard_language_fr.ts
    ├── keyboard_language_hu.ts
    ├── keyboard_language_it.ts
    ├── keyboard_language_ms.ts
    ├── keyboard_language_nl.ts
    ├── keyboard_language_pl.ts
    ├── keyboard_language_pt.ts
    ├── keyboard_language_pt_BR.ts
    ├── keyboard_language_ru.ts
    ├── keyboard_language_sl.ts
    ├── keyboard_language_sq.ts
    ├── keyboard_language_sr.ts
    ├── keyboard_language_tr.ts
    ├── keyboard_language_ug.ts
    ├── keyboard_language_uk.ts
    ├── keyboard_language_zh_CN.ts
    ├── keyboard_language_zh_HK.ts
    └── keyboard_language_zh_TW.ts
```

### 4.1 总体思路与系统框架

#### 4.1.1文件框架思路

通过阅读dde-control-center的源代码，src部分为插件的实现以及实现代码复用所存在的框架代码，代码的插件部分在src/plugin-selfstartup目录，分为operation和window部分，其中windows部分主要负责控制中心自启动项目的界面构成，operation部分负责参与控制中心对系统文件与配置的控制。translation文件夹为控制中心（dde-control-center）提供了不同语言环境下的支持，通过识别系统的语言环境选择展示到面板不同的语言。include与misc为项目注册到控制中心所必须包含的编译依赖文件。

#### 4.1.2 设计思路

我们在初赛中已经完成了通过注册到dde-dock实现的自启动插件，对于插件的界面以及界面上按钮对应的功能已经有了一个大致的构想，但由于dde-dock的插件是一个较为独立的结构，而dde-control-center里面的每一个插件都需要往控制中心里注册一个module并且通过rpc方法与dde-application-manager进行远程服务的交流，因此在实现细节上dde-control-center插件和dde-dock插件有着很大的区别。

##### operation部分

```
├── defappmodel.cpp
├── defappmodel.h
├── defappworker.cpp
├── defappworker.h
├── mimedbusproxy.cpp
├── mimedbusproxy.h
└── qrc
```

operation部分是插件的后端部分，对于控制中心的每个插件都有Model，Worker和DBusProxy三个部分：

- Model：Model部分通过继承QObject注册到QT的项目中，私有变量Category实现了自启动信息在内存中的一个副本用于前端的交互
- Worker：Worker部分提供了插件对文件系统的操作。由于操作系统对于开机自启动的支持在于把对应的.desktop文件拷贝到/home/user/.config/autostart中并设置Hidden=false，因此对于自启动应用管理的插件必须要对文件的读写提供支持，该支持由Woker部分实现
- DBusProxy：由于插件要注册到控制中心并且对应用进行管理，因此需要向运行中的应用程序管理服务（dde-application-manager）进行交互，管理服务提供了rpc的调用接口，插件通过DBusProxy部分向管理服务发起远程请求



### 4.2 类功能说明

 



### 4.3 实现描述

#### 4.2.1 DefAppModel

| 名称            | 功能 |
| --------------- | ---- |
| DefAppModel     |      |
| ~DefAppModel    |      |
| getModSelfSetUp |      |

#### 4.2.2 DefAppWorker

| 名称                | 功能 |
| ------------------- | ---- |
| DefAppWorker        |      |
| DefaultAppsCategory |      |
| active              |      |
| deactive            |      |
| onReverseUserApp    |      |
| onGetListApps       |      |
| onDelUserApp        |      |
| onAddUserFile       |      |
| getCategory         |      |

#### 4.2.3 MimeDBusProxy

| 名称          | 功能 |
| ------------- | ---- |
| MimeDBusProxy |      |
| SetDefaultApp |      |
| DeleteApp     |      |
| DeleteUserApp |      |
| AddUserApp    |      |
| GetDefaultApp |      |
| ListApps      |      |
| ListUserApps  |      |
| Change        |      |

#### 4.2.4 SelfStartupDetailWidget

| 名称                     | 功能                                                         |
| ------------------------ | ------------------------------------------------------------ |
| SelfStartupDetailWidget  | 创建自启动软件条目窗口。初始化条目窗口中的文字不可编辑、icon大小、条目形状、条目不可移动，初始化存储软件列表的QStandardItemModel，初始化软件条目的布局。 |
| ~SelfStartupDetailWidget | 删除自启动软件条目窗口。                                     |
| setModel                 | 设置自启动软件条目窗口的当前模式。根据当前窗口的分类，设置不同的窗口模式（由于本插件目前只有一个分类，因此setModel功能相当于直接调用setCategory功能）。 |
| setCategory              | 设置自启动软件条目窗口的当前分类。将分类的增、删、改的信号和对应的自启动软件条目窗口的槽函数连接，将分类中的软件放入存储软件列表的QStandardItemModel中，并更新自启动软件条目窗口。 |
| updateListView           | 更新自启动软件条目窗口。依次读取自启动软件条目窗口的当前模式中的每一个软件状态，依照软件状态，更新窗口显示（显示是否自启动、软件名称、软件icon、删除按键）。 |
| getAppIcon               | 获取软件的icon。从系统中获取软件的icon，并统一调整为32*32大小。 |
| getAppById               |                                                              |
| appendItemData           |                                                              |
| isDesktopOrBinaryFile    |                                                              |
| isValid                  |                                                              |
| reverseItem              |                                                              |
| requestDelUserApp        |                                                              |
| onListViewClicked        |                                                              |
| onDelBtnClicked          |                                                              |
| onClearAll               |                                                              |
| getAppListview           |                                                              |
| AppsItemChanged          |                                                              |
| onReverseApp             |                                                              |
| addItem                  |                                                              |
| removeItem               |                                                              |
| showInvalidText          |                                                              |

#### 4.2.5 DefAppModel

| 名称              | 功能 |
| ----------------- | ---- |
| SelfStartupPlugin |      |
| name              |      |
| module            |      |
| location          |      |

#### 4.2.6 SelfStartupModule

| 名称               | 功能 |
| ------------------ | ---- |
| SelfStartupModule  |      |
| ~SelfStartupModule |      |
| work               |      |
| model              |      |
| active             |      |

#### 4.2.7 SelfStartupDetailModule

| 名称                    | 功能 |
| ----------------------- | ---- |
| SelfStartupDetailModule |      |
| page                    |      |

 



## 5 系统测试情况

### 5.1前端测试



### 5.2 自启动管理功能测试


//TODO: 扩展性

## 附录A 插件安装

### 1、开发环境配置

#### （1）、配置 Deepin 操作系统

开发环境：Deepin V23Beta版

系统架构：x86

镜像下载链接：https://mirrors.ustc.edu.cn/deepin-cd/releases/23-Beta/

虚拟机平台：WMware Workstation 16Pro

操作系统环境搭建参考博客：https://blog.csdn.net/qq_44133136/article/details/105887560



**TODO**

#### （2）、配置 Deepin 插件开发环境

##### 安装基本开发环境：

安装包 `build-essential`、`git`、`g++`、`cmake`、`dde`、`dtk`

```shell
sudo apt install build-essential git g++ cmake
sudo apt install dde-dock-dev libdtkwidget-dev
```

##### 安装 QT 开发环境：

安装 `qt5-default`、`qt5-doc`、`qtcreator`

```shell
sudo apt install qt5-default qt5-doc qtcreator
```

依照上述方法，可在虚拟机中运行`qtcreator`，并在`qtcreator`中对插件进行测试

![image-20230513155011159](/Users/shenyang/Desktop/操作系统大赛/中期&结题/提交文档/images/QT_IDE.png)

#### （3）、插件安装测试

为了测试所配置的虚拟机环境可用于 DDE 插件的开发，在环境配置中，本小组选取了`Github`仓库中的插件`dde-sys-monitor-plugin`（项目地址：https://github.com/q77190858/dde-sys-monitor-plugin）进行试运行。

根据上述方法配置插件开发环境后，可按照`dde-sys-monitor-plugin`中的提示信息顺利运行该插件。这表明开发环境配置已完成。





## 附录B 开发过程问题记录

### 1 开发环境配置问题

### 2 图标展示问题

### 3 翻译问题

### 4 文字颜色异常问题

### 5 开机启动项处理思路问题

为了实现插件可视化管理软件的开机自启动，了解`Deepin`系统开机自启动的功能实现是至关重要的。

通过查阅资料与实践，我们了解到`Deepin`系统包含自启动文件夹`~/.config/autostart`，该文件夹类似于 Windows 下的启动文件夹，系统开机时会执行该文件夹下的每个 desktop 文件 Exec 参数指向的脚本或可执行文件。

为了确认可行性，小组进行了该方法的验证。首先，通过`Deepin`系统自带的修改开机自启动设置的方法，修改开机启动项（图中修改`终端`的自启动项）：

**TODO**

![deepin自启动修改](./images/deepin自启动修改.png)

随后检查自启动文件夹`~/.config/autostart`：

```shell
yang@yang-PC:~/.config/autostart$ ls
deepin-terminal.desktop org.deepin.browser.desktop
```

发现`deepin-terminal.desktop`文件被添加入了该自启动文件夹中，并且会在开机时自启动。

而取消终端的自启动时，`~/.config/autostart`中已有的`deepin-terminal.desktop`文件并不会被移除，而是其中的`Hidden`的字段会被修改为`false`，表示取消开机自启动设置。

由此，可以通过在插件中检查所有`~/.config/autostart`文件夹中`.desktop`文件的`Hidden`字段来搜索系统所有的自启动软件；也可以通过添加`.desktop`文件、修改`Hidden`字段的方式进行开机自启动设置的修改。

### 6 rpc远程通信问题


## 附录C 开发计划





