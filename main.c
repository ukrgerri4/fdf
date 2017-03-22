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
    //ptr->mlx = mlx_init();
    //ptr->win = mlx_new_window(ptr->mlx, 800, 800, "fdf");

    draw(ptr, map);

    //mlx_loop(ptr->mlx);
}
