cmake_minimum_required(VERSION 3.17)
project(acceptNFA_DFA)

set(CMAKE_CXX_STANDARD 14)

add_executable(acceptNFA_DFA main.cpp NFA.cpp State.cpp Transition.cpp operations.cpp)