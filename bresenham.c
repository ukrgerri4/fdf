#include "fdf.h"

int		mod(int a, int y)
{
    int val;

    val = 0;
    if (a - y < 0)
        val = (a - y) * -1;
    else
        val = (a - y);
    return (val);
}

void drawLine(t_ptr *ptr, int x1, int y1, int x2, int y2)
{
    const int deltaX = mod(x2, x1);
    const int deltaY = mod(y2, y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    int error = deltaX - deltaY;
    my_put_pixel(ptr, x2, y2, 0xFFFFFF);
    while(x1 != x2 || y1 != y2)
    {
        my_put_pixel(ptr, x1, y1, 0xFFFFFF);
        const int error2 = error * 2;
        if(error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }
}

void drawCircle(t_ptr *ptr, int x0, int y0, int radius)
{
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;
    while(y >= 0) {
        mlx_pixel_put(ptr->mlx, ptr->win, x0 + x, y0 + y, 0xFFFFFF);
        mlx_pixel_put(ptr->mlx, ptr->win, x0 + x, y0 - y, 0xFFFFFF);
        mlx_pixel_put(ptr->mlx, ptr->win, x0 - x, y0 + y, 0xFFFFFF);
        mlx_pixel_put(ptr->mlx, ptr->win, x0 - x, y0 - y, 0xFFFFFF);
        error = 2 * (delta + y) - 1;
        if(delta < 0 && error <= 0) {
            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if(delta > 0 && error > 0) {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}
