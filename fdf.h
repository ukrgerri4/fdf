#ifndef FDF_FDF_H
#define FDF_FDF_H

# define SIZE_X 800
# define SIZE_Y 800
# define BASIC_COLOR 0xFFFFFF

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct  s_coord
{
    int x;
    int y;
    int z;
}               t_coord;

typedef struct  s_ptr
{
    void    *mlx;
    void    *win;
    void    *image;
    char    *image_ptr;
    int     bpp;
    int     line_size;
    int     ex;
}               t_ptr;

typedef struct  s_pix
{
    int             x;
    int             y;
    int             z;
    int             color;
    struct s_pix    *right;
    struct s_pix    *down;
}               t_pix;

typedef struct  s_map
{
    t_pix	*head;
    t_pix	*tail;
    int		size;
}               t_map;

// t_ptr & t_map function
t_map *make_map_list(void);
t_ptr *make_ptr_list(void);

// t_pix function
void    push_back_node(t_map *map, int x, int y, t_pix **start_line);

// draw function
void    draw(t_ptr *ptr, t_map *map, char *file_name);
void    drawLine(t_ptr *ptr, t_pix *p1, t_pix *p2, int color);
void    drawCircle(t_ptr *ptr, int x0, int y0, int radius);

// general function
void    coefficient(t_map *map, int k);
void    write_map(t_ptr *ptr, t_map *map);
int     count_elem(char **line);
void    my_put_pixel(t_ptr *ptr, int x, int y, int color);
void    fill_map(t_map * map, char **line);
void	ft_error(char *str);

// debugging
void    put_map(t_map *map);

#endif
