cmake_minimum_required(VERSION 3.14)
project(TP2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP2 main.c "prompt.c" "prompt.h" echo.c echo.h invocation.c invocation.h)