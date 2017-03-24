#include "fdf.h"

int     count_elem(char **line)
{
    int count;

    count = 0;
    if (line)
        while (line[count])
            count++;
    return (count);
}

void	ft_error(char *str)
{
    ft_putstr(str);
    exit(0);
}

void    coefficient(t_map *map, int k)
{
    t_pix *tmp;
    t_pix *tmp_start;

    tmp = map->head;
    tmp_start = map->head;
    while (tmp)
    {
        tmp->x *= k;
        tmp->y *= k;
        tmp->z *= k;
        tmp = tmp->right;
        if (tmp == 0)
        {
            tmp = tmp_start->down;
            tmp_start = tmp_start->down;
        }
    }
}

void    my_put_pixel(t_ptr *ptr, int x, int y, int color)
{
    int a;


    a = (y * ptr->line_size + (x * (ptr->bpp)));
    ptr->image_ptr[a] = (unsigned char)(color << 8 >> 24);
    ptr->image_ptr[a + 1] = (unsigned char)(color << 16 >> 24);;
    ptr->image_ptr[a + 2] = (unsigned char)(color << 24 >> 24);;
}

int     set_color(t_pix *pix, t_pix *pix_next)
{
    if (pix->color == pix_next->color)
        return (pix_next->color);
    else
        return (pix->color);
}

void    write_map(t_ptr *ptr, t_map *map)
{
    t_pix   *tmp;
    t_pix   *tmp_start;

//    coefficient(map, 1);
    tmp = map->head;
    tmp_start = map->head;
    while (tmp)
    {
        if (tmp->right)
            drawLine(ptr, tmp, tmp->right, set_color(tmp, tmp->right));
        if (tmp->down)
            drawLine(ptr, tmp, tmp->down, set_color(tmp, tmp->down));
        tmp = tmp->right;
        if (tmp == 0)
        {
            tmp = tmp_start->down;
            tmp_start = tmp_start->down;
        }
    }
}