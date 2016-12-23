/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_malloc_t		*search_t_malloc(t_malloc_t **root, void *ptr,
											int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		return (*root);
	else if (cmpf((*root)->ptr, ptr) < 0)
		(*root)->back = search_t_malloc(&(*root)->back, ptr, cmpf);
	else if (cmpf((*root)->ptr + (*root)->size, ptr) > 0)
		(*root)->front = search_t_malloc(&(*root)->front, ptr, cmpf);
	else if (ptr_inside((*root)->ptr, (*root)->size, ptr))
		return ((*root));
	return (NULL);
}

void			*resolve_realloc(void *ptr, t_malloc_t *m, size_t size)
{
	if (m->type != T_LARGE)
	{
		if ((ptr - m->ptr) % GET_SECT_DIV_LEN(m->type))
			return (NULL);
		m->i = (ptr - m->ptr) / GET_SECT_DIV_LEN(m->type);
		if (m->type == get_malloc_type(size))
		{
			m->ptr_sizes[m->i] = size;
			m->ptr_times[m->i] = time(0);
			return (ptr);
		}
	}
	if ((m->type == T_LARGE) && ptr != m->ptr)
		return (NULL);
	g_malloc.cur_ptr = malloc(size);
	if (m->type != T_LARGE)
		ft_memcpy(g_malloc.cur_ptr, m->ptr_sect[m->i],
				MIN(m->ptr_sizes[m->i], (int)size));
	else
		ft_memcpy(g_malloc.cur_ptr, m->ptr, MIN(m->size, size));
	free(ptr);
	return (g_malloc.cur_ptr);
}

void			*realloc(void *ptr, size_t size)
{
	if (!init_malloc())
		return (malloc_error("Initialisation Failed"));
	if (!ptr)
		return (malloc(size));
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!(g_malloc.cur_tmalloc =
				search_t_malloc(&g_malloc.list_tiny, ptr, ptr_compare)))
		if (!(g_malloc.cur_tmalloc =
					search_t_malloc(&g_malloc.list_small, ptr, ptr_compare)))
			if (!(g_malloc.cur_tmalloc =
				search_t_malloc(&g_malloc.list_large, ptr, ptr_compare)))
				return (NULL);
	return (resolve_realloc(ptr, g_malloc.cur_tmalloc, size));
}
