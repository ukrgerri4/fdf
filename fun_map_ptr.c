#include "fdf.h"

t_ptr *make_ptr_list(void)
{
    t_ptr *tmp;

    if (!(tmp = (t_ptr *)malloc(sizeof(t_ptr))))
        exit (1);
    tmp->mlx = NULL;
    tmp->win = NULL;
    return (tmp);
}

t_map *make_map_list(void)
{
	t_map *tmp;

	if (!(tmp = (t_map *)malloc(sizeof(t_map))))
		exit (1);
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->size = 0;
	return (tmp);
}

/*
void	del_list(t_map **list) // rewrite hen pix_fun will be wrote
{
	t_pix	*tmp;
	t_pix	*next;

	tmp = (*list)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	*list = NULL;
}
*/