/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			insert_tree_t_malloc(t_malloc_t **root, t_malloc_t *new_m,
									int (*cmpf)(void *, void *))
{
	if (cmpf((*root)->ptr, new_m->ptr) < 0)
	{
		if ((*root)->back == NULL)
			(*root)->back = new_m;
		else
			insert_tree_t_malloc(&(*root)->back, new_m, cmpf);
	}
	else
	{
		if ((*root)->front == NULL)
			(*root)->front = new_m;
		else
			insert_tree_t_malloc(&(*root)->front, new_m, cmpf);
	}
}

t_malloc_t		*findmin_tree_t_malloc(t_malloc_t *root)
{
	t_malloc_t	*node;

	node = root;
	while (node->back != NULL)
		node = node->back;
	return (node);
}

t_malloc_t		*resolve_tree_t_malloc(t_malloc_t **root)
{
	g_malloc.cur_tmalloc = (*root);
	if ((*root)->back == NULL && (*root)->front == NULL)
	{
		if (delete_t_malloc(g_malloc.cur_tmalloc))
			return (NULL);
		return ((*root));
	}
	else if ((*root)->back == NULL)
		(*root) = (*root)->front;
	else if ((*root)->front == NULL)
		(*root) = (*root)->back;
	else
	{
		g_malloc.cur_tmalloc = findmin_tree_t_malloc((*root)->front);
		g_malloc.cur_tmalloc->back = (*root)->back;
		g_malloc.cur_tmalloc = (*root);
		(*root) = (*root)->front;
	}
	delete_t_malloc(g_malloc.cur_tmalloc);
	return (*root);
}

t_malloc_t		*delete_tree_t_malloc(t_malloc_t **root, void *ptr,
										int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		return (*root);
	else if (cmpf((*root)->ptr, ptr) < 0)
		(*root)->back = delete_tree_t_malloc(&(*root)->back, ptr, cmpf);
	else if (cmpf((*root)->ptr, ptr) > 0)
		(*root)->front = delete_tree_t_malloc(&(*root)->front, ptr, cmpf);
	else
		(*root) = resolve_tree_t_malloc(root);
	return (*root);
}

void			*malloc_tree(t_malloc_t **root, t_malloc_t *new_m)
{
	if (!(*root))
	{
		(*root) = new_m;
		return (new_m->ptr);
	}
	insert_tree_t_malloc(root, new_m, ptr_compare);
	return (new_m->ptr);
}
