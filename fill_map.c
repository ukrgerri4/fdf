#include "fdf.h"

void validation_char(char *str)
{
    static char base[26] = "-0123456789abcdefABCDEFx,";
    int         i;

    i = 0;
    while (str[i])
        if (!ft_strchr(base, str[i++]))
            ft_error("Are you BLIND??? It's not valid!\n");
}

int    calculate_color(char *str)
{
    static char baseu[7] = "ABCDEF";
    static char basel[7] = "abcdef";
    int color;
    int i;

    i = 0;
    color = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]))
        {
            str[i] = (unsigned char) (str[i] - 48);
            color |= str[i];
            color <<= 4;
        }
        else if (ft_strchr(baseu, str[i]))
        {
            str[i] = (unsigned char) (str[i] - 55);
            color |= str[i];
            color <<= 4;
        }
        else if (ft_strchr(basel, str[i]))
        {
            str[i] = (unsigned char) (str[i] - 87);
            color |= str[i];
            color <<= 4;
        }
        else
            ft_error("It's not funny anymore! Can you watch what you print?\n");
        i++;
    }
    return (color >>= 4);
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

void    validation_value(t_map *map, char *str)
{
    int         i;
    int         color;

    i = 0;
    color = 0;
    (!ft_isdigit(str[i]) && str[i] != '-') ? ft_error("It was easy. Try harder!\n") : 0;
    map->tail->z = ft_atoi(str);
    if (str[i] == '-')
        i++;
    while (ft_isdigit(str[i]))
        i++;
    if (str[i] == '\0')
        return ;
    else if (str[i] && (str[i + 1] && (str[i + 2] && str[i] == ',' && str[i + 1] == '0' && str[i + 2] == 'x')))
    {
        check_right_count(&str[i]);
        i += 3;
        color = calculate_color(&str[i]);
        map->tail->color = color;
    }
    else
        ft_error("Hahaha, good try...kh-kh I foresaw it...\n");
}

void    fill_map(t_map * map, char **line)
{
    int             x;
    static t_pix    *start_line;
    t_pix           *tmp;

    x = 0;
    map->size = count_elem(line);
    if (!map->string_lenght)
        map->string_lenght = map->size;
    if (map->size != map->string_lenght)
        ft_error("Ups! Look like count of elements is not the same, right? Well, don't worry.\n");
    tmp = start_line;
    while (line[x])
    {
        push_back_node(map, x, map->height, &tmp);
        if (x == 0)
            start_line = map->tail;
        validation_char(line[x]);
        validation_value(map, line[x++]);
        if (map->tail->color == BASIC_COLOR && map->tail->z != 0)
            map->tail->color = BASIC_COLOR / 7;
    }
    map->height++;
    free(*line);
    free(line);
}
