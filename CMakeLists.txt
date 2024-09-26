cmake_minimum_required(VERSION 3.14)

project(MyQtProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(MyQtProject
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/calendarTask.h
    src/calendarTask.cpp
    src/calendarEvent.h
    src/calendarEvent.cpp
)

target_link_libraries(MyQtProject Qt6::Core Qt6::Gui Qt6::Widgets)

