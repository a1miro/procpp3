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

add_executable(references references.cpp)
set_property(TARGET references PROPERTY CXX_STANDARD 17)

add_executable(constexpr_example constexpr_example.cpp)
set_property(TARGET constexpr_example PROPERTY CXX_STANDARD 17)

add_executable(casts casts.cpp)
set_property(TARGET casts PROPERTY CXX_STANDARD 17)

add_executable(attributes attributes.cpp)
set_property(TARGET attributes  PROPERTY CXX_STANDARD 17)



