cmake_minimum_required(VERSION 3.4)
project(implapp)

include_directories("${PROJECT_SOURCE_DIR}")

option (USE_WIDGET1, "Use Widget1" ON)
option (USE_WIDGET2, "Use Widget2" OFF)


if (USE_WIDGET1)
    add_executable(implapp1 implapp.cpp)
    add_library(widget1 widget.cpp impl1.cpp)
    target_link_libraries (implapp1 widget1)
endif (USE_WIDGET1)

if (USE_WIDGET2)
    add_executable(implapp2 implapp.cpp)
    add_library(widget2 widget.cpp impl2.cpp)
    target_link_libraries (implapp2 widget2)
endif (USE_WIDGET2)

