/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_malloc_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_malloc_t		*alloc_t_malloc_zone(void)
{
	t_malloc_z		*cur_z;

	if ((g_malloc.cur_tmalloc = search_t_malloc_z(&g_malloc.list_zone)))
		return (g_malloc.cur_tmalloc);
	if ((cur_z = mmap_anon(SIZE_TMZ, "list zone failed")))
		return (ins_get_t_t_malloc_z(&g_malloc.list_zone, cur_z, ptr_compare));
	return (NULL);
}

t_malloc_t		*create_t_malloc(size_t size, t_malloc_type type)
{
	t_malloc_t	*m;

	if (!(m = alloc_t_malloc_zone()))
		return (NULL);
	m->size = size;
	m->type = type;
	if (!(m->ptr = mmap_anon(size, "failed to create t_malloc->ptr")))
		return (NULL);
	m->ptr_times[0] = time(0);
	m->back = NULL;
	m->front = NULL;
	return (m);
}

void			count_zone_ptr_alloc(t_malloc_z **root, t_malloc_type t, int *c)
{
	int		i;

	if (!(*root))
		return ;
	count_zone_ptr_alloc(&(*root)->prev, t, c);
	i = -1;
	while (++(i) < T_MALLOC_Z_STORAGE_SIZE)
	{
		g_malloc.cur_tmalloc = &(*root)->storage[i];
		if ((g_malloc.cur_tmalloc->type == t) &&
			(g_malloc.cur_tmalloc->ptr != NULL))
			(*c)++;
	}
	count_zone_ptr_alloc(&(*root)->next, t, c);
}

int				delete_t_malloc(t_malloc_t *themalloc)
{
	int			c;

	c = 0;
	count_zone_ptr_alloc(&g_malloc.list_zone, (themalloc)->type, &c);
	if (c <= 1)
		return (0);
	munmap(themalloc->ptr, themalloc->size);
	themalloc->ptr = NULL;
	themalloc->back = NULL;
	themalloc->front = NULL;
	themalloc->size = 0;
	themalloc->i = 0;
	delete_t_malloc_z(&(g_malloc.list_zone), themalloc, ptr_compare);
	themalloc = NULL;
	return (1);
}

int				t_malloc_check_gap(t_malloc_t *current,
									t_malloc_t *front, size_t size)
{
	void		*ref;

	ref = (current->ptr + current->size + 1);
	if (ptr_inside(front->ptr, front->size, ref) ||
			ptr_inside(front->ptr, front->size, (ref + size)))
		return (0);
	if ((ref < front->ptr) && ((ref + size) < front->ptr))
		return (1);
	return (0);
}
