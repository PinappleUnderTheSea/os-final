# 使用 set 命令设置一个变量
set(PLUGIN_NAME "test-plugin")

# 设置项目名称
project(${PLUGIN_NAME})

find_package(Qt5 COMPONENTS REQUIRED Core Widgets)
find_package(PkgConfig REQUIRED)
find_package(DdeControlCenter REQUIRED)

pkg_search_module(Dtk REQUIRED IMPORTED_TARGET dtkwidget)

set(SRCS
    module.h
    module.cpp
)

set(QRCS
  module.qrc
)

add_library(${PROJECT_NAME} SHARED ${SRCS} ${QRCS})
target_include_directories(${PROJECT_NAME}
PUBLIC
    ${DdeControlCenter_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME}
PRIVATE
    Qt5::Core
    Qt5::Widgets
    PkgConfig::Dtk
    ${DdeControlCenter_LIBRARIES}
)

# TODO: should change to ${CMAKE_INSTALL_LIBDIR}
# install(TARGETS ${PROJECT_NAME} DESCRIPTION lib/dde-control-center/modules)
install(TARGETS ${PLUGIN_NAME} DESTINATION lib/dde-control-center/modules)