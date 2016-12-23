/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_small.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*malloc_small(size_t size)
{
	t_malloc_t		*new_m;
	void			*ptr;

	if ((ptr = insert_tree_zone_slot(size, &(g_malloc.list_small), M)))
		return (ptr);
	if (!(new_m = create_t_malloc(N_ALLOC, T_SMALL)))
		return (NULL);
	if ((ptr = check_tree_zone_slot(size, &(new_m), N, -1)))
		if (malloc_tree(&(g_malloc.list_small), new_m))
			return (ptr);
	return (NULL);
}
