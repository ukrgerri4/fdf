# include "fdf.h"

int main(void)
{
    void *mlx;

    mlx = mlx_init();
    mlx_new_window(mlx, 400, 400, "fdf");

    mlx_loop(mlx);
}
