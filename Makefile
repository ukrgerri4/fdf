NAME = fdf

WWW = -pipe

FLAGS = -lmlx -framework OpenGL -framework AppKit

#-L/usr/include/../lib -lXext -lX11 -lm

LIB_PATH = libft/
LIBFT = $(LIB_PATH)libft.a

LIBPATH = minilibx
LIBX = $(LIBPATH)/libmlx_Linux.a

FT_PRINTF_PATH = ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

OBJECTS = main.o \
            fun_map_ptr.o \
            fun_pix.o \
            fun_general.o \
            fill_map.o \
            bresenham.o \

all: $(NAME)

libmk:
	make -C $(LIB_PATH)

ft_printfmk:
	make -C $(FT_PRINTF_PATH)

$(NAME): $(OBJECTS)
	gcc $(WWW) -o $(NAME) $(OBJECTS) $(LIBX) $(LIBFT) $(FT_PRINTF) $(FLAGS)

%.o: %.c
	gcc  $(WWW) -o $@ -c $<

clean:
	#make -C $(LIB_PATH) clean
	#make -C $(FT_PRINTF_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	#rm -f $(LIBFT)
	#rm -f $(FT_PRINTF)
	rm -f $(NAME)

re: fclean all
