cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)

set(CMAKE_BUILD_TYPE Debug)

#add_executable(initialize_list initialize_list.cpp)
#set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
#add_dependencies(initialize_list uniform_initialization)


add_executable(problem_5.0 problem_5.0.cpp)
set_property(TARGET problem_5.0 PROPERTY CXX_STANDARD 14)

add_executable(problem_5.1 problem_5.1.cpp)
set_property(TARGET problem_5.1 PROPERTY CXX_STANDARD 14)

add_executable(problem_5.2 problem_5.2.cpp)
set_property(TARGET problem_5.2 PROPERTY CXX_STANDARD 14)


