#include "fdf.h"

void	push_back_node(t_map *map, int n)
{
    t_pix *tmp;

    if (!(tmp = (t_pix *)malloc(sizeof(t_pix))))
        exit(1);
    tmp->x = 0;
    tmp->y = 0;
    tmp->z = n;
    tmp->color = 0xFFFFFF;
    tmp->down = NULL;
    if (map->tail)
        map->tail->right = tmp;
    map->tail = tmp;
    if (map->head == NULL)
        map->head = tmp;
    map->size++;
}



/*
void	push_front_pix(t_map *map, int n)
{
    t_pix *tmp;

    if (!(tmp = (t_pix *)malloc(sizeof(t_pix))))
        exit(1);
    tmp->x = 0;
    tmp->y = 0;
    tmp->z = 0;
    tmp->color = 0xFFFFFF;
    if (map->head)
        map->head-> = tmp;
    map->head = tmp;
    if (map->tail == NULL)
        map->tail = tmp;
    map->size++;
}

int		pop_front_pix(t_map *map)
{
    t_pix *prev;
    int		tmp;

    if (map->head == NULL)
        exit(3);
    prev = map->head;
    map->head = map->head->next;
    if (map->head)
        map->head->prev = NULL;
    if (prev == map->tail)
        map->tail = NULL;
    tmp = prev->nb;
    free(prev);
    map->size--;
    return (tmp);
}
*/
