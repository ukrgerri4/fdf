#include "fdf.h"

void    draw(t_ptr *ptr, t_map *map, char *file_name)
{
    char    *line;
    int     fd;

    if ((fd = open(file_name, O_RDONLY)) == -1)
        ft_error("Open file error!\n");
    line = NULL;
    while (get_next_line(fd, &line))
        fill_map(map, ft_strsplit(line, ' '));
}

int main(int argc, char **argv)
{
    t_map   *map;
    t_ptr   *ptr;

    if (argc == 2)
    {
        ptr = make_ptr_list();
        map = make_map_list();
        ptr->mlx = mlx_init();
        ptr->win = mlx_new_window(ptr->mlx, SIZE_X, SIZE_Y, argv[1]);

        ptr->image = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
        ptr->image_ptr = mlx_get_data_addr(ptr->image, &ptr->bpp, &ptr->line_size, &ptr->ex);
        ptr->bpp /= 8;

        draw(ptr, map, argv[1]);
        write_map(ptr, map);

        mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->image, 0, 0);

        mlx_loop(ptr->mlx);
    }
    else
        ft_error("Usage : ./fdf <filename>\n");
    return (0);
}