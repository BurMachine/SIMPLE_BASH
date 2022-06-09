cmake_minimum_required(VERSION 3.21)
project(grep C)

set(CMAKE_C_STANDARD 11)

add_executable(grep lib_grep.c testgrep.c)
