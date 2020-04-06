cmake_minimum_required(VERSION 3.15)
project(Project4_CRM)

set(CMAKE_CXX_STANDARD 14)

include_directories(grading/helper_files)
include_directories(Project4_starter_files)

add_executable(Project4_CRM
        grading/helper_files/Invent.h
        grading/helper_files/main.cpp
        grading/helper_files/MyString.cpp
        grading/helper_files/MyString.h
        grading/helper_files/valgrind_main.cpp
        grading/submissions/compile_error.cpp
        grading/submissions/infinite_loop.cpp
        grading/submissions/link_error.cpp
        grading/submissions/memory_leak.cpp
        grading/submissions/runtime_error.cpp
        grading/submissions/some_credit.cpp
        Project4_starter_files/Invent.h
        Project4_starter_files/main.cpp
        Project4_starter_files/MyString.cpp
        Project4_starter_files/MyString.h
        Project4_starter_files/Project4.cpp)
