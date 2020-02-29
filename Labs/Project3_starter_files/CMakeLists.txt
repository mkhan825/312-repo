cmake_minimum_required(VERSION 3.15)
project(Project3_starter_files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project3_starter_files
        header.c
        main.cpp
        Makefile
        Project3.cpp
        String.h)
