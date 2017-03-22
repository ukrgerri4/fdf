#include "fdf.h"

void validation_char(char *str)
{
    static char base[19] = "0123456789ABCDEFx,";
    int         i;

    i = 0;
    while (str[i])
        if (!ft_strchr(base, str[i++]))
            ft_error("Are you BLIND??? It's not valid!\n");
}

int    calculate_color(char *str)
{
    static char base[7] = "ABCDEF";
    int color;
    int i;

    i = 0;
    color = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
        {
            str[i] = (char) (str[i] - 48);
            color |= str[i];
            color <<= 4;
        }
        else if (ft_strchr(base, str[i]))
        {
            str[i] = (char) (str[i] - 55);
            color |= str[i];
            color <<= 4;
        }
        else
            ft_error("It's not funny anymore! Can you watch what you print?\n");
        i++;
    }
    return (color);
}

void    check_right_count(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    if (i != 9)
        ft_error("N-n-nope!Try ones more!\n");
}

void    validation_value(char *str)
{
    int         i;
    int         color;
    int         z;

    i = 0;
    !ft_isdigit(str[i]) ? ft_error("It was easy. Try harder!\n") : 0;
    z = ft_atoi(str);
    while (ft_isdigit(str[i]))
        i++;
    if (str[i] == '\0')
        return ;
    else if (str[i] && (str[i + 1] && (str[i + 2] && str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')))
    {
        check_right_count(&str[i]);
        i += 3;
        color = calculate_color(&str[i]);
        while (!(color & 1))
            color >>= 1;
        ft_printf("Z = %d, Color = %d\n", z, color);
    }
    else
        ft_error("Hahaha, good try...kh-kh I foresaw it...\n");
}

void    fill_map(t_map * map, char **line)
{
    int         i;
    static int  count;

    i = 0;
    while (line[i])
    {
        validation_char(line[i]);
        validation_value(line[i]);
        i++;
    }
    ft_printf("%d\n", i);
    if (!count)
        count = i;
    if (count != i)
        ft_error("Ups! Look like count of elements is not the same, right? Well, don't worry.\n");
    ft_putarr(line); // delete
}
