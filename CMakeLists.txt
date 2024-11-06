cmake_minimum_required(VERSION 3.15)
project(saphy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CURSES_NEED_WIDE TRUE)

set(SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${SRC_FILES})

find_package(Curses REQUIRED)
include_directories(saphy ${INCLUDE_DIRS} ${CURSES_INCLUDE_DIRS})

add_executable(saphy ${SRC_FILES})

target_link_libraries(saphy Curses)
