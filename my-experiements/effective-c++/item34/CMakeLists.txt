cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)


add_executable(setalarm setalarm.cpp)
set_property(TARGET setalarm PROPERTY CXX_STANDARD 14)
