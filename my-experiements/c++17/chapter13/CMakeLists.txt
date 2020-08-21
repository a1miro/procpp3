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

add_executable(output_stream output_stream.cpp)
set_property(TARGET output_stream PROPERTY CXX_STANDARD 17)

add_executable(stream_manipulators stream_manipulators.cpp)
set_property(TARGET stream_manipulators PROPERTY CXX_STANDARD 17)

add_executable(input_stream input_stream.cpp)
set_property(TARGET input_stream PROPERTY CXX_STANDARD 17)

add_executable(read_name read_name.cpp)
set_property(TARGET read_name PROPERTY CXX_STANDARD 17)

add_executable(file_stream file_stream.cpp)
set_property(TARGET file_stream PROPERTY CXX_STANDARD 17)
