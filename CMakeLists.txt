cmake_minimum_required(VERSION 3.13)

set(DVERSION "6.0.21" CACHE STRING "define project version")
set(BUILD_DOCS ON CACHE BOOL "Generate doxygen-based documentation")

set(PROJECT_NAME dde-control-center)
project(${PROJECT_NAME}
    VERSION ${DVERSION}
    DESCRIPTION "Deepin Control Center"
    HOMEPAGE_URL "https://github.com/linuxdeepin/dde-control-center"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
option(ENABLE_ASAN "Enable asan" OFF)

# INFO:
# plugins can be disabled and their options
# plugin-authentication : DISABLE_AUTHENTICATION
# plugin-update : DISABLE_UPDATE
# plugin-keyboard: DISABLE_LANGUAGE to disable language panel

option(DISABLE_AUTHENTICATION "disable build authentication plugins" OFF)
option(DISABLE_UPDATE "disable build update plugins" OFF)
option(DISABLE_LANGUAGE "disable lanugage settings in control center" OFF)

# asan 自己有内存泄露，暂不使用
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(UNITTEST ON)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror=return-type -fno-omit-frame-pointer -Wextra")
    if(ENABLE_ASAN)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
        add_definitions(-DUSE_ASAN)
    endif()
else()
    # generate qm
    execute_process(COMMAND bash "misc/translate_generation.sh"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    # generate desktop translate
    execute_process(COMMAND bash "misc/translate_ts2desktop.sh"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()
set(BUILD_PLUDIN ON)

if (NOT BUILD_PLUDIN)
    set(UNITTEST OFF)
endif()
# GNU 默认

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(UT_COMPILER -fprofile-arcs -ftest-coverage)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(UT_COMPILER -fprofile-instr-generate -ftest-coverage)
endif()

# 增加安全编译参数
ADD_DEFINITIONS(${SAFE_COMPILER})

# Install settings
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr)
endif ()
include(GNUInstallDirs)

set(TRANSLATE_INSTALL_DIR "${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/translations" CACHE STRING "Install dir for dde-control-center translate files")

add_definitions(-DTRANSLATE_READ_DIR="${CMAKE_INSTALL_PREFIX}/${TRANSLATE_INSTALL_DIR}")
set(MODULE_INSTALL_DIR "${CMAKE_INSTALL_FULL_LIBDIR}/dde-control-center/modules" CACHE STRING "Install dir for dde-control-center modules")

set(MODULE_READ_DIR "${MODULE_INSTALL_DIR}" CACHE STRING "Dir to find dde-control-center modules")
add_definitions(-DDefaultModuleDirectory="${MODULE_READ_DIR}")

set(LOCALSTATE_READ_DIR "${CMAKE_INSTALL_FULL_LOCALSTATEDIR}" CACHE STRING "Dir to find modifiable single-machine data")
add_definitions(-DVARDIRECTORY="${LOCALSTATE_READ_DIR}")
# Find the library
find_package(PkgConfig REQUIRED)
find_package(DtkCore REQUIRED)
find_package(DtkWidget REQUIRED)
find_package(Qt5 COMPONENTS Widgets Network DBus Concurrent Multimedia Svg Test REQUIRED)
find_package(DdeControlCenter REQUIRED)

# pkg_check_modules(DFrameworkDBus REQUIRED dframeworkdbus)

if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "sw_64")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mieee")
endif()

# dconfig
# file(GLOB DCONFIG_FILES "misc/configs/*.json")
# dconfig_meta_files(APPID org.deepin.dde.control-center BASE misc/configs FILES ${DCONFIG_FILES})

include_directories(
    include
)

set(Test_Libraries
    -lpthread
    -lgcov
    -lgtest
    Qt5::Test
)

#--------------------------interface--------------------------
set(Interface_Name dcc-interface)
file(GLOB_RECURSE Interface_SRCS
    "include/interface/*.h"
    "src/interface/*.cpp"
)
add_library(${Interface_Name} SHARED
    ${Interface_SRCS}
)

set(Interface_Includes
    Qt5::Widgets
    include/interface
)
set(Interface_Libraries
    Qt5::Widgets
    ${DtkWidget_LIBRARIES}
)
target_include_directories(${Interface_Name} PUBLIC
    ${Interface_Includes}
)

target_link_libraries(${Interface_Name} PRIVATE
    ${Interface_Libraries}
)

set_target_properties(${Interface_Name} PROPERTIES
    VERSION ${CMAKE_PROJECT_VERSION}
    SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
)

# so
install(TARGETS ${Interface_Name} DESTINATION ${CMAKE_INSTALL_LIBDIR})


#--------------------------dccwidgets library----------------------------
set(Dcc_Widgets_Name dcc-widgets)
file(GLOB_RECURSE Dcc_Widgets_SRCS
    "include/widgets/*.h"
    "src/widgets/*.cpp"
)
add_library(${Dcc_Widgets_Name} SHARED
    ${Dcc_Widgets_SRCS}
)
set(Dcc_Widgets_Includes
    ${DtkWidget_INCLUDE_DIRS}
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
    include/widgets
)
set(Dcc_Widgets_Libraries
    ${DtkWidget_LIBRARIES}
    Qt5::Widgets
    Qt5::Svg
    Qt5::DBus
    ${Interface_Name}
)
target_include_directories(${Dcc_Widgets_Name} PUBLIC
    ${Dcc_Widgets_Includes}
)
target_link_libraries(${Dcc_Widgets_Name} PRIVATE
    ${Dcc_Widgets_Libraries}
)

set_target_properties(${Dcc_Widgets_Name} PROPERTIES
    VERSION ${CMAKE_PROJECT_VERSION}
    SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
)
# message(STATUS "dccwidgets success")

# so
install(TARGETS ${Dcc_Widgets_Name} DESTINATION ${CMAKE_INSTALL_LIBDIR})

#------------------------dccwidgets library test--------------------------
if (UNITTEST)
    set(UT_Dcc_Widgets_Name ut-dcc-widgets)
    file(GLOB_RECURSE UT_Dcc_Widgets_SRCS
        "tests/widgets/*.cpp"
    )
    add_executable(${UT_Dcc_Widgets_Name}
        ${Dcc_Widgets_SRCS}
        ${UT_Dcc_Widgets_SRCS}
    )
    # 用于测试覆盖率的编译条件
    target_compile_options(${UT_Dcc_Widgets_Name} PRIVATE ${UT_COMPILER})
    target_include_directories(${UT_Dcc_Widgets_Name} PUBLIC
        ${Dcc_Widgets_Includes}
    )
    target_link_libraries(${UT_Dcc_Widgets_Name} PRIVATE
        ${Dcc_Widgets_Libraries}
        ${Test_Libraries}
    )
endif()
# message(STATUS "dccwidgets test success")

#--------------------------dde-control-center--------------------------
set(Control_Center_Name dde-control-center)
file(GLOB_RECURSE Control_Center_SRCS
    "src/frame/*.h"
    "src/frame/*.cpp"
)
list(REMOVE_ITEM Control_Center_SRCS "${CMAKE_SOURCE_DIR}/src/frame/main.cpp")

add_executable(${Control_Center_Name}
    ${Control_Center_SRCS}
    src/frame/main.cpp
)

target_compile_definitions(${Control_Center_Name} PRIVATE CVERSION="${CVERSION}")

set(Control_Center_Includes
    ${DtkWidget_INCLUDE_DIRS}
    Qt5::Widgets
    Qt5::DBus
    Qt5::Concurrent
)
set(Control_Center_Libraries
    ${Dcc_Widgets_Name}
    ${Interface_Name}
    ${DtkWidget_LIBRARIES}
    Qt5::Widgets
    Qt5::DBus
    Qt5::Concurrent
)
target_include_directories(${Control_Center_Name} PUBLIC
    ${Control_Center_Includes}
)

target_link_libraries(${Control_Center_Name} PRIVATE
    ${Control_Center_Libraries}
)

# bin
install(TARGETS ${Control_Center_Name} DESTINATION ${CMAKE_INSTALL_BINDIR})

# message(STATUS "dde-control-centre success")

#----------------------------install config------------------------------
# qm files
file(GLOB QM_FILES "translations/*.qm")
install(FILES ${QM_FILES} DESTINATION ${TRANSLATE_INSTALL_DIR})

#desktop
# install(FILES misc/dde-control-center.desktop DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/applications)

#service
# install(FILES misc/org.deepin.dde.ControlCenter1.service DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/dbus-1/services)

# dev files
file(GLOB HEADERS "include/*")
set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR}/dde-control-center)
install(DIRECTORY ${HEADERS} DESTINATION ${INCLUDE_INSTALL_DIR})

include(CMakePackageConfigHelpers)
configure_package_config_file(misc/DdeControlCenterConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/DdeControlCenterConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DdeControlCenter
    PATH_VARS INCLUDE_INSTALL_DIR
    INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/DdeControlCenterConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/DdeControlCenter)

# message(STATUS "install config success")


#-------------------------ut-dcc-interface-------------------------
if (UNITTEST)
    set(UT_Interface_Name ut-dcc-interface)
    file(GLOB_RECURSE UT_Interface_SRCS
        "tests/interface/*.cpp"
    )

    add_executable(${UT_Interface_Name}
        ${Interface_SRCS}
        ${UT_Interface_SRCS}
    )

    # 用于测试覆盖率的编译条件
    target_compile_options(${UT_Interface_Name} PRIVATE ${UT_COMPILER})

    target_include_directories(${UT_Interface_Name} PUBLIC
        ${Interface_Includes}
    )

    target_link_libraries(${UT_Interface_Name} PRIVATE
        ${Interface_Libraries}
        ${Test_Libraries}
    )
endif()
#-------------------------ut-dcc-frame-------------------------
if (UNITTEST)
    set(UT_Frame_Name ut-dcc-frame)
    file(GLOB_RECURSE UT_Frame_SRCS
        "tests/frame/*.cpp"
    )

    add_executable(${UT_Frame_Name}
        ${Control_Center_SRCS}
        ${UT_Frame_SRCS}
    )

    # 用于测试覆盖率的编译条件
    target_compile_options(${UT_Frame_Name} PRIVATE ${UT_COMPILER})

    target_include_directories(${UT_Frame_Name} PUBLIC
        ${Control_Center_Includes}
    )

    target_link_libraries(${UT_Frame_Name} PRIVATE
        ${Control_Center_Libraries}
        ${Test_Libraries}
    )
endif()
#--------------------------plugin-test1--------------------------
if (UNITTEST)
    set(Plugin_Test1_Name plugin-test1)
    file(GLOB_RECURSE Plugin_Test1_SRCS
        "tests/plugin-test1/*.h"
        "tests/plugin-test1/*.cpp"
    )

    add_library(${Plugin_Test1_Name} MODULE
        ${Plugin_Test1_SRCS}
    )

    set(Plugin_Test1_Includes
        Qt5::Widgets
        Qt5::DBus
        Dtk::Widget
    )
    set(Plugin_Test1_Libraries
        ${Interface_Name}
        Qt5::Widgets
        Qt5::DBus
        Dtk::Widget
    )
    target_include_directories(${Plugin_Test1_Name} PUBLIC
        ${Plugin_Test1_Includes}
    )

    target_link_libraries(${Plugin_Test1_Name} PRIVATE
        ${Plugin_Test1_Libraries}
    )
endif()

#--------------------------plugin-test2--------------------------
if (UNITTEST)
    set(Plugin_Test2_Name plugin-test2)
    file(GLOB_RECURSE Plugin_Test2_SRCS
        "tests/plugin-test2/*.h"
        "tests/plugin-test2/*.cpp"
    )

    add_library(${Plugin_Test2_Name} MODULE
        ${Plugin_Test2_SRCS}
    )

    set(Plugin_Test2_Includes
        Qt5::Widgets
        Qt5::DBus
    )
    set(Plugin_Test2_Libraries
        ${Interface_Name}
        Qt5::Widgets
        Qt5::DBus
    )
    target_include_directories(${Plugin_Test2_Name} PUBLIC
        ${Plugin_Test2_Includes}
    )

    target_link_libraries(${Plugin_Test2_Name} PRIVATE
        ${Plugin_Test2_Libraries}
    )
endif()

#--------------------------dcc-defaultapp-plugin--------------------------
if (BUILD_PLUDIN)
    set(DefaultApp_Name dcc-defaultapp-plugin)
    file(GLOB_RECURSE DefaultApp_SRCS
        "src/plugin-defaultapp/window/*.cpp"
        "src/plugin-defaultapp/window/widgets/*.cpp"
        "src/plugin-defaultapp/operation/*.cpp"
        "src/plugin-defaultapp/operation/qrc/*.qrc"
    )

    add_library(${DefaultApp_Name} MODULE
        ${DefaultApp_SRCS}
    )

    set(DefaultApp_Includes
        ${DtkWidget_INCLUDE_DIRS}
        Qt5::Widgets
        Qt5::DBus
        Qt5::Concurrent
        src/plugin-defaultapp/window/widgets
        src/plugin-defaultapp/operation
    )
    set(DefaultApp_Libraries
        ${Dcc_Widgets_Name}
        ${DtkWidget_LIBRARIES}
        Qt5::Widgets
        Qt5::DBus
        Qt5::Concurrent
        ${Dcc_Widgets_Name}
    )
    target_include_directories(${DefaultApp_Name} PUBLIC
        ${DefaultApp_Includes}
    )

    target_link_libraries(${DefaultApp_Name} PRIVATE
        ${DefaultApp_Libraries}
    )

    install(TARGETS ${DefaultApp_Name} DESTINATION ${MODULE_INSTALL_DIR})
endif()

message(STATUS "all success")