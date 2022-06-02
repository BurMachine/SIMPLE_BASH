cmake_minimum_required(VERSION 3.22)
project(SIMPLE_BASH C)

set(CMAKE_C_STANDARD 11)

add_executable(SIMPLE_BASH cat_lib.c test.c)
