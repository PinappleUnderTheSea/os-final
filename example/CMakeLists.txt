cmake_minimum_required(VERSION 3.7)

project(example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH $ENV{Qt5_DIR})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(DdeControlCenter REQUIRED)
find_package(PkgConfig REQUIRED)

add_executable(example main.cpp)

find_package(Qt5 COMPONENTS Core DBus Concurrent Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(KF5NetworkManagerQt REQUIRED)
find_package(DtkWidget REQUIRED)

get_target_property(KF5_QT_INCLUDE_DIRS KF5::NetworkManagerQt INTERFACE_INCLUDE_DIRECTORIES)

foreach(LETTER ${TRY_KF5_LIBRARIES})
    if (NOT KF5_QT_LIBRARIES)
        get_target_property(KF5_QT_LIBRARIES KF5::NetworkManagerQt ${LETTER})
    endif()
endforeach()

if (NOT KF5_QT_LIBRARIES)
    find_library(KF5_QT_LIBRARIES libKF5NetworkManagerQt.so)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
    ${DdeControlCenter_INCLUDE_DIR}
    ${DtkWidget_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5DBus_INCLUDE_DIRS}
    ${Qt5Widget_INCLUDE_DIRS}
    Qt5::Concurrent
    ${QGSettings_INCLUDE_DIRS}
    #${LibNM_INCLUDE_DIRS}
    ${Qt5Network_INCLUDE_DIRS}
    ${KF5_QT_INCLUDE_DIRS}
    ${DDE-Network-Core_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${DdeControlCenter_LIBRARIES}
    ${DCC_INTERFACE_LIBRARIES}
    ${DCC_WIDGETS_LIBRARIES}
    ${DtkWidget_LIBRARIES}
    ${Qt5Core_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
    Qt5::Concurrent
    #${LibNM_LIBRARIES}
    ${Qt5DBus_LIBRARIES}
    ${Qt5Network_LIBRARIES}
    ${QGSettings_LIBRARIES}
    ${KF5_QT_LIBRARIES}
    ${DDE-Network-Core_LIBRARIES}
)

#add_custom_command(
#    OUTPUT path.pb.cc path.pb.h
#    COMMAND protoc
#    ARGS --cpp_out . ${CMAKE_CURRENT_SOURCE_DIR}/path.proto -I ${CMAKE_CURRENT_SOURCE_DIR}
#    DEPENDS path.proto)
