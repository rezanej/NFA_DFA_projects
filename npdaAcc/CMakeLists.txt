cmake_minimum_required(VERSION 3.17)
project(npdaAcc)

set(CMAKE_CXX_STANDARD 14)

add_executable(npdaAcc main.cpp NPDA.cpp state.cpp operations.cpp transition.cpp stack.cpp)