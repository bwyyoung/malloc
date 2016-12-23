/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_large.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_large(size_t size)
{
	t_malloc_t		*new_m;

	if (!(new_m = create_t_malloc(size, T_LARGE)))
		return (NULL);
	malloc_tree(&(g_malloc.list_large), new_m);
	return (new_m->ptr);
}
