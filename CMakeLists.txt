cmake_minimum_required(VERSION 3.2)
project(blade)

add_subdirectory(src)

option(BUILD_EXAMPLE "Build example programs" FALSE)
if (BUILD_EXAMPLE)
  add_subdirectory(example)
endif ()