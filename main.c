#include "fdf.h"

void    draw(t_ptr *ptr, t_map *map)
{
    char *line;

    line = NULL;
    while (get_next_line(0, &line))
        fill_map(map, ft_strsplit(line, ' '));
}

int main(void)
{
    t_map   *map;
    t_ptr   *ptr;

    ptr = make_ptr_list();
    map = make_map_list();
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, SIZE_X, SIZE_Y, "fdf");
    ptr->image = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
    ptr->image_ptr = mlx_get_data_addr(ptr->image, &ptr->bpp, &ptr->line_size, &ptr->ex);

    //mlx_new_image();
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->image, 0, 0);
    //draw(ptr, map);

    mlx_loop(ptr->mlx);
}
