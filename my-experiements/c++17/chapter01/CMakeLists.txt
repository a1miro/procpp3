cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)

set(CMAKE_BUILD_TYPE Debug)

#add_executable(initialize_list initialize_list.cpp)
#set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
#add_dependencies(initialize_list uniform_initialization)
add_definitions(-Wall)

add_executable(basics basics.cpp)
set_property(TARGET basics PROPERTY CXX_STANDARD 17)

add_executable(c_style_arrays c_style_arrays.cpp)
set_property(TARGET c_style_arrays PROPERTY CXX_STANDARD 17)

add_executable(initializer_list initializer_list.cpp)
set_property(TARGET initializer_list PROPERTY CXX_STANDARD 17)






