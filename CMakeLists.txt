cmake_minimum_required(VERSION 3.6)
project(fdf)

set(LIBFT_PATH libft)
set(FT_PRINTF_PATH ft_printf)
set(MINILIBX_PATH minilibx)


#find_package(XEXT REQUIRED)
find_package(X11 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(UBUNTU_FLAGS "-lmlx -L/usr/include/../lib -lXext -lX11 -lm")
set(MAC_FLAGS "-lmlx -framework OpenGL -framework AppKit")

set(CMAKE_C_FLAGS ${UBUNTU_FLAGS})

set(SOURCE_FILES bresenham.c fdf.h fun_map_ptr.c fun_pix.c fill_map.c fun_general.c Debugging.c)
add_executable(fdf ${SOURCE_FILES} main.c)

file(GLOB SOURCES_LIBFT ${LIBFT_PATH}/*.c)
file(GLOB SOURCES_FT_PRINTF ${FT_PRINTF_PATH}/*.c)
file(GLOB SOURCES_MINILIBX ${MINILIBX_PATH}/*.*)
add_library(ft STATIC ${SOURCES_LIBFT} ${SOURCES_FT_PRINTF} ${SOURCES_MINILIBX})

target_link_libraries(fdf ft ${X11_LIBRARY})