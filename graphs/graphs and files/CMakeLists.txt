cmake_minimum_required(VERSION 3.20)
project(graphs_and_files C)

set(CMAKE_C_STANDARD 99)

add_executable(graphs_and_files ../graph.h ../graph.c main.c)
