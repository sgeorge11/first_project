cmake_minimum_required(VERSION 3.19)
project(first_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(A1)

add_executable(first_project
        A1/contacts.cpp
        A1/contacts.h
        A1/m1.cpp
        read_input.cpp
        read_input.h)
