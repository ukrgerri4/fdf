#include "fdf.h"

void    put_map(t_map *map)
{
    t_pix *tmp;
    t_pix *tmp_start;

    tmp = map->head;
    tmp_start = map->head;
    while (tmp)
    {
        ft_printf("x = %d, y = %d, z = %d, color = %X\n", tmp->x, tmp->y, tmp->z, tmp->color);
        tmp = tmp->right;
        if (tmp == 0)
        {
            tmp = tmp_start->down;
            tmp_start = tmp_start->down;
        }
    }
}