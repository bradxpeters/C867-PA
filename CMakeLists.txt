cmake_minimum_required(VERSION 3.16)
project(C867_PA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867_PA
        degree.h
        main.cpp
        roster.cpp
        roster.h
        student.cpp
        student.h)
