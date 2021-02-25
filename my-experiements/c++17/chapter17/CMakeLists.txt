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

add_executable(queue_example queue_example.cpp)
set_property(TARGET queue_example PROPERTY CXX_STANDARD 17)

add_executable(enum_example enum_example.cpp)
set_property(TARGET enum_example PROPERTY CXX_STANDARD 17)

add_executable(vector_ex vector_ex.cpp)
set_property(TARGET vector_ex PROPERTY CXX_STANDARD 17)






