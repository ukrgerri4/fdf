cmake_minimum_required(VERSION 3.6)
project(fdf)

include_directories(inc libft ft_printf minilibx) # part to include headers (or it may be included in your .h file)
link_directories(libft ft_printf minilibx) # part to include libraries

set(CMAKE_CXX_STANDARD 11)

set(UBUNTU_FLAGS "-L minilibx -I minilibx -lmlx_Linux -lXext -lX11 -lm")
set(MAC_FLAGS "-lmlx -framework OpenGL -framework AppKit")

set(CMAKE_C_FLAGS)

set(SOURCE_FILES
        bresenham.c
        fdf.h
        fun_map_ptr.c
        fun_pix.c
        fill_map.c
        fun_general.c
        Debugging.c)

add_executable(fdf ${SOURCE_FILES} main.c)

target_link_libraries(fdf libft.a libftprintf.a libmlx.a X11 Xext m) # linkage