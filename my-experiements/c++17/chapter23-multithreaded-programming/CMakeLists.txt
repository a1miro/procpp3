cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)

set(CMAKE_BUILD_TYPE Debug)

#add_executable(initialize_list initialize_list.cpp)
#set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
#add_dependencies(initialize_list uniform_initialization)

add_executable(neighbour_thread_exception neighbour_thread_exception.cpp)
set_property(TARGET neighbour_thread_exception PROPERTY CXX_STANDARD 17)
target_link_libraries(neighbour_thread_exception pthread)

add_executable(atomic_operations atomic_operations.cpp)
set_property(TARGET atomic_operations PROPERTY CXX_STANDARD 17)
target_link_libraries(atomic_operations pthread atomic)


