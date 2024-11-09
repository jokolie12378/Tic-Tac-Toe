cmake_minimum_required(VERSION 3.27)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tic_Tac_Toe
        game.cpp
        game.h
        main.cpp)
