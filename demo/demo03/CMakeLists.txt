project(cv03)

cmake_minimum_required(VERSION 3.6)

set(CMAKE_C_STANDARD 99)

add_executable(cv3-demo demo.c)
add_executable(cv3-play play.c)
add_executable(cv3-err errors.c)

