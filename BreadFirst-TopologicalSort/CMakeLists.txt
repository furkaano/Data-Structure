cmake_minimum_required(VERSION 3.15)
project(BreadFirst_TopologicalSort C)

set(CMAKE_C_STANDARD 11)

add_executable(BreadFirst_TopologicalSort Main.c General.c General.h Queue.c Queue.h Graph.c Graph.h)