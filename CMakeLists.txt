cmake_minimum_required(VERSION 3.23)
project(TP02 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(TP02
        src/file.c
        src/file.h
        src/main.c
        src/travel.c
        src/travel.h src/matrix.c src/matrix.h)