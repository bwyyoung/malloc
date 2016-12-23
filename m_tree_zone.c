/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tree_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_malloc_t		*resolve_tree_t_malloc_zone(t_malloc_t **root, void *ptr)
{
	if ((ptr - (*root)->ptr) % GET_SECT_DIV_LEN((*root)->type))
		return (*root);
	(*root)->i = (ptr - (*root)->ptr) / GET_SECT_DIV_LEN((*root)->type);
	ft_bzero((*root)->ptr_sect[(*root)->i], (*root)->ptr_sizes[(*root)->i]);
	(*root)->ptr_slot[(*root)->i] = 0;
	(*root)->ptr_sect[(*root)->i] = NULL;
	(*root)->i = -1;
	while (++((*root)->i) < SECTOR_SIZE)
		if ((*root)->ptr_slot[(*root)->i])
			return (*root);
	if (CLEAR_MT_MZ_ON_FREE)
		*root = resolve_tree_t_malloc(root);
	return (*root);
}

t_malloc_t		*delete_tree_t_malloc_zone(t_malloc_t **root, void *ptr,
										int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		return (*root);
	else if (cmpf((*root)->ptr, ptr) < 0)
		(*root)->back = delete_tree_t_malloc_zone(&(*root)->back, ptr, cmpf);
	else if (cmpf((*root)->ptr + (*root)->size, ptr) > 0)
		(*root)->front = delete_tree_t_malloc_zone(&(*root)->front, ptr, cmpf);
	else if (ptr_inside((*root)->ptr, (*root)->size, ptr))
		(*root) = resolve_tree_t_malloc_zone(root, ptr);
	return (*root);
}

void			*check_tree_zone_slot(size_t size, t_malloc_t **root,
									size_t block_size, int i)
{
	while (++i < SECTOR_SIZE)
	{
		if ((*root)->ptr_slot[i])
			continue;
		(*root)->ptr_slot[i] = 1;
		(*root)->ptr_sizes[i] = size;
		(*root)->ptr_times[i] = time(0);
		(*root)->ptr_sect[i] = ((*root)->ptr + i * block_size);
		return ((*root)->ptr_sect[i]);
	}
	return (NULL);
}

void			*insert_tree_zone_slot(size_t size, t_malloc_t **root,
									size_t block_size)
{
	void	*ptr;

	if (!(*root))
		return (NULL);
	if ((ptr = check_tree_zone_slot(size, &(*root), block_size, -1)))
		return (ptr);
	if ((*root)->back != NULL)
		return (insert_tree_zone_slot(size, &(*root)->back, block_size));
	else if ((*root)->front != NULL)
		return (insert_tree_zone_slot(size, &(*root)->front, block_size));
	return (NULL);
}

t_malloc_z		*findmin_tree_t_malloc_z(t_malloc_z *root)
{
	t_malloc_z	*node;

	node = root;
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}
