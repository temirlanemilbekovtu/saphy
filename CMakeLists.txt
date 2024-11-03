cmake_minimum_required(VERSION 3.15)
project(saphy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Curses REQUIRED)
include_directories(saphy ${CURSES_INCLUDE_DIRS})

add_executable(saphy
        main.cpp
)

target_link_libraries(saphy Curses)
