cmake_minimum_required(VERSION 3.3)
project(ImplApp)

include_directories("${PROJECT_SOURCE_DIR}")

#option (USE_WIDGET1 "Use Widget1" ON)
#option (USE_WIDGET2 "Use Widget2" OFF)


add_executable(uniform_initialization uniform_initialization.cpp)
set_property(TARGET uniform_initialization PROPERTY CXX_STANDARD 14)

add_executable(initialize_list initialize_list.cpp)
set_property(TARGET initialize_list PROPERTY CXX_STANDARD 14)
add_dependencies(initialize_list uniform_initialization)

add_executable(explicit_conversation explicit_conversation.cpp)
set_property(TARGET explicit_conversation PROPERTY CXX_STANDARD 14)

add_executable(va_list_example va_list_example.cpp)
set_property(TARGET va_list_example PROPERTY CXX_STANDARD 14)



