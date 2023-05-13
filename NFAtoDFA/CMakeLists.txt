cmake_minimum_required(VERSION 3.17)
project(NFAtoDFA)

set(CMAKE_CXX_STANDARD 14)

add_executable(NFAtoDFA main.cpp NFA.cpp State.cpp Transition.cpp Operations.cpp)