cmake_minimum_required(VERSION 3.20)
project(oop_exercise_03)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_exercise_03 main.cpp Point.cpp Point.h Figure.h Triangle.cpp Triangle.h Square.cpp Square.h)
