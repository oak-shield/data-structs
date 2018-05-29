cmake_minimum_required(VERSION 3.6)
project(list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c list.c list.h)
add_executable(list ${SOURCE_FILES} list.c list.h)