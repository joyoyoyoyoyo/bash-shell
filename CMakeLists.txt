cmake_minimum_required(VERSION 3.5)
project(proj00_bash_shell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    simpleshell/simple_shell.c
    commandline.c)

add_executable(proj00_bash_shell ${SOURCE_FILES})