cmake_minimum_required(VERSION 3.20)
project(bipartite_graph C)

set(CMAKE_C_STANDARD 99)

add_executable(bipartite_graph ../graph.h ../graph.c main.c)
