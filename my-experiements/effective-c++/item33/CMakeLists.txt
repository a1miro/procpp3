cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)


add_executable(decltype_auto_lambda decltype_auto_lambda.cpp)
set_property(TARGET decltype_auto_lambda PROPERTY CXX_STANDARD 14)

