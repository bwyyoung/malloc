/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	delete_tree_t_malloc_zone(&(g_malloc.list_tiny), ptr, ptr_compare);
	delete_tree_t_malloc_zone(&(g_malloc.list_small), ptr, ptr_compare);
	delete_tree_t_malloc(&(g_malloc.list_large), ptr, ptr_compare);
	ptr = NULL;
}
