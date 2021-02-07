cmake_minimum_required(VERSION 3.15)
project(SeparateChaining C)

set(CMAKE_C_STANDARD 11)

add_executable(SeparateChaining main.c General.c General.h Singly_Linked_List.c Singly_Linked_List.h Hash_Student_Style.c Hash_Student_Style.h)