cmake_minimum_required(VERSION 3.15)
project(Dijkstra_sPath C)

set(CMAKE_C_STANDARD 11)

add_executable(Dijkstra_sPath main.c Dijkstra.c Dijkstra.h General.c General.h)