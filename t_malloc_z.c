/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_malloc_z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_malloc_t		*check_t_malloc_z_slot(t_malloc_z *cur_zone, int checknull)
{
	g_malloc.i = -1;
	while (++g_malloc.i < T_MALLOC_Z_STORAGE_SIZE)
	{
		g_malloc.cur_tmalloc = &cur_zone->storage[g_malloc.i];
		if (g_malloc.cur_tmalloc->ptr == NULL && checknull)
			return (&cur_zone->storage[g_malloc.i]);
		else if (g_malloc.cur_tmalloc->ptr != NULL && !checknull)
			return (&cur_zone->storage[g_malloc.i]);
	}
	return (NULL);
}

t_malloc_t		*ins_get_t_t_malloc_z(t_malloc_z **root, t_malloc_z *new_m,
									int (*cmpf)(void *, void *))
{
	if (!(*root) && (*root = new_m))
		return (check_t_malloc_z_slot(new_m, 1));
	if (cmpf((*root), new_m) < 0)
	{
		if ((*root)->prev == NULL && ((*root)->prev = new_m))
			return (check_t_malloc_z_slot(new_m, 1));
		else
			return (ins_get_t_t_malloc_z(&(*root)->prev, new_m, cmpf));
	}
	else if ((*root)->next == NULL && ((*root)->next = new_m))
		return (check_t_malloc_z_slot(new_m, 1));
	else
		return (ins_get_t_t_malloc_z(&(*root)->next, new_m, cmpf));
}

t_malloc_z		*resolve_t_malloc_z(t_malloc_z **root)
{
	g_malloc.cur_zone = (*root);
	if ((*root)->prev == NULL && (*root)->next == NULL)
	{
		if (g_malloc.cur_zone == g_malloc.list_zone)
			return (g_malloc.cur_zone);
		munmap(g_malloc.cur_zone, SIZE_TMZ);
		return (NULL);
	}
	else if ((*root)->prev == NULL)
		(*root) = (*root)->next;
	else if ((*root)->next == NULL)
		(*root) = (*root)->prev;
	else
	{
		g_malloc.cur_zone = findmin_tree_t_malloc_z((*root)->next);
		g_malloc.cur_zone->prev = (*root)->prev;
		g_malloc.cur_zone = (*root);
		(*root) = (*root)->next;
	}
	munmap(g_malloc.cur_zone, SIZE_TMZ);
	return (*root);
}

t_malloc_z		*delete_t_malloc_z(t_malloc_z **root, t_malloc_t *ptr,
									int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		return (*root);
	else if (cmpf((*root), ptr) < 0)
		(*root)->prev = delete_t_malloc_z(&(*root)->prev, ptr, cmpf);
	else if (cmpf((*root) + SIZE_TMZ, ptr) > 0)
		(*root)->next = delete_t_malloc_z(&(*root)->next, ptr, cmpf);
	else if (ptr_inside((*root), SIZE_TMZ, ptr)
			&& !check_t_malloc_z_slot((*root), 0))
		(*root) = resolve_t_malloc_z(root);
	return (*root);
}

t_malloc_t		*search_t_malloc_z(t_malloc_z **root)
{
	if (!(*root))
		return (NULL);
	if ((g_malloc.cur_tmalloc = check_t_malloc_z_slot(*root, 1)))
		return (g_malloc.cur_tmalloc);
	if ((*root)->prev != NULL)
		return (search_t_malloc_z(&(*root)->prev));
	else if ((*root)->next != NULL)
		return (search_t_malloc_z(&(*root)->next));
	return (NULL);
}
