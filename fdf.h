#ifndef FDF_FDF_H
#define FDF_FDF_H

# define SIZE_X 800
# define SIZE_Y 800

//# include "minilibx/mlx.h"
# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct  s_ptr
{
    void    *mlx;
    void    *win;
    void    *image;
    void    *image_ptr;
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
void	push_back_node(t_map *map, int color, int z);

// draw function
void    draw(t_ptr *ptr, t_map *map);
void    drawLine(t_ptr *ptr, int x1, int y1, int x2, int y2);
void    drawCircle(t_ptr *ptr, int x0, int y0, int radius);

// general function
void    fill_map(t_map * map, char **line);
void	ft_error(char *str);

#endif
