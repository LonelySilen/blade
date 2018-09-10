project(examples)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)

include_directories(../src)

set(LINK_LIBS
    Qt5::Core
    blade
    )

add_executable(blade-demo blade_demo.cpp)
target_link_libraries(blade-demo ${LINK_LIBS})