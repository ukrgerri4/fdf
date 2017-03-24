#include "fdf.h"

void	ft_error(char *str)
{
    ft_putstr(str);
    exit(0);
}

void    my_put_pixel(t_ptr *ptr, int x, int y, int color)
{
    int a;


    a = (y * ptr->line_size + (x * (ptr->bpp)));
    ptr->image_ptr[a] = (unsigned char)(color << 8 >> 24);
    ptr->image_ptr[a + 1] = (unsigned char)(color << 16 >> 24);;
    ptr->image_ptr[a + 2] = (unsigned char)(color << 24 >> 24);;
}
