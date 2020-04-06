cmake_minimum_required(VERSION 3.15)
project(Project5_Set)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project5_starter_files)

add_executable(Project5_Set
        Project5_starter_files/main.cpp
        Project5_starter_files/Project5.cpp
        Project5_starter_files/Set.h)
