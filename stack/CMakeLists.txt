cmake_minimum_required(VERSION 3.20)
project(stack C)

set(CMAKE_C_STANDARD 11)

add_executable(stack solve_rpn.h euclid.h src/euclid.c src/solve_rpn.c main.c)
