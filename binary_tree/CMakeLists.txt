cmake_minimum_required(VERSION 3.6)
project(lab07test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c tree.c tree.h)
add_executable(lab07test ${SOURCE_FILES} tree.c tree.h)