cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CMAKE_CXX_STANDARD 11)
#set(MACOS_FLAGS "-lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FLAGS "-lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c fdf.h)
add_executable(fdf ${SOURCE_FILES})