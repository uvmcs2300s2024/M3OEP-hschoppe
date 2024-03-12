cmake_minimum_required(VERSION 3.26)
project(M3OEP_hschoppe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M3OEP_hschoppe
        Connections.cpp
        Connections.h
        main.cpp)
