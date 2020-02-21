cmake_minimum_required(VERSION 3.15)
project(Project2_starter_files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project2_starter_files
        header.c
        main.cpp
        Makefile
        MatrixMultiply.h
        Project2.cpp)
