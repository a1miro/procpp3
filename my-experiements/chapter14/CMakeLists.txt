cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)

set(CMAKE_BUILD_TYPE Debug)

#add_executable(initialize_list initialize_list.cpp)
#set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
#add_dependencies(initialize_list uniform_initialization)

add_executable(operator_overloading operator_overloading.cpp)
set_property(TARGET operator_overloading PROPERTY CXX_STANDARD 14)

add_executable(bitwise_operators bitwise_operators.cpp)
set_property(TARGET bitwise_operators PROPERTY CXX_STANDARD 14)




