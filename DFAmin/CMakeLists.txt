cmake_minimum_required(VERSION 3.17)
project(DFAmin)

set(CMAKE_CXX_STANDARD 14)

add_executable(DFAmin main.cpp NFA.cpp State.cpp Transition.cpp operations.cpp)