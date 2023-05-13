cmake_minimum_required(VERSION 3.17)
project(Turing)

set(CMAKE_CXX_STANDARD 14)

add_executable(Turing main.cpp operations.cpp state.cpp transition.cpp turing.cpp tape.cpp)