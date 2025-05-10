cmake_minimum_required(VERSION 3.13)
project(HW3)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
  main.cpp
)

add_executable(main
  ${SOURCES}
)

set_target_properties(main PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)