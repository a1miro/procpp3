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

add_executable(c_strings c_strings.cpp)
set_property(TARGET c_strings PROPERTY CXX_STANDARD 17)

add_executable(c++_string c++_string.cpp)
set_property(TARGET c++_string PROPERTY CXX_STANDARD 17)

#add_executable(charconv_low_level charconv_low_level.cpp)
#set_property(TARGET charconv_low_level PROPERTY CXX_STANDARD 17)

add_executable(string_view string_view.cpp)
set_property(TARGET string_view PROPERTY CXX_STANDARD 17)





