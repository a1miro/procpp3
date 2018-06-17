cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)

set(CMAKE_BUILD_TYPE Debug)

#add_executable(initialize_list initialize_list.cpp)
#set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
#add_dependencies(initialize_list uniform_initialization)

add_executable(stream_iterators stream_iterators.cpp)
set_property(TARGET stream_iterators PROPERTY CXX_STANDARD 14)

add_executable(find_duplicates find_duplicates.cpp)
set_property(TARGET find_duplicates PROPERTY CXX_STANDARD 14)



