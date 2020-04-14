cmake_minimum_required(VERSION 3.15)
project(project6_recursion)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project6_starter_files)

add_executable(project6_recursion
        Project6_starter_files/main.cpp
        Project6_starter_files/MazeParams.h
        Project6_starter_files/Project6.cpp
        Project6_starter_files/Recursion.h)
