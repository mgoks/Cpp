cmake_minimum_required(VERSION 3.8)
project(Linked_list)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Node.cpp Node.h)
add_executable(Linked_list ${SOURCE_FILES})
