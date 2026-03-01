cmake_minimum_required(VERSION 3.14)

project(joystick_CTRL LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(joystick_CTRL SHARED
  joystick_CTRL_global.h
  joystick_ctrl.cpp
  joystick_ctrl.h
)

target_link_libraries(joystick_CTRL PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(joystick_CTRL PRIVATE JOYSTICK_CTRL_LIBRARY)
