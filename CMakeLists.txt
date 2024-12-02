cmake_minimum_required(VERSION 3.30)
project(ColorTheWorld C)

set(CMAKE_C_STANDARD 99)

add_executable(ColorTheWorld main.c
        color.h
        color.c
        image.h
        image.c
        gif.h
        gif.c)

target_compile_options(ColorTheWorld PRIVATE -Wall -Wextra -Werror -pedantic)