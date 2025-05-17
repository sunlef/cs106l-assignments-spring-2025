cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(HW5)

set(SOURCES main.cpp user.cpp)

add_executable(main ${SOURCES})

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

