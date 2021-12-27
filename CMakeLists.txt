cmake_minimum_required(VERSION 3.19)
project(boolean_utilities C)

set(CMAKE_C_STANDARD 99)

add_executable(boolean_utilities main.c data.c expr.c scope.c solve.c truthtable.c)