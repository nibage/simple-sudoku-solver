cmake_minimum_required(VERSION 2.6)
project(sudoku)

add_executable(sudoku main.cpp)

install(TARGETS sudoku RUNTIME DESTINATION bin)
