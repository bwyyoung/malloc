/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					show_alloc_mem_ex(void)
{
	if (!init_malloc())
		return ;
	ft_putstr(TINY_STR);
	ft_putstr(" : ");
	if (g_malloc.list_tiny)
		ptr_addr_to_str(findmin_tree_t_malloc(g_malloc.list_tiny)->ptr, 1, 0);
	ft_putchar('\n');
	print_tree_t_malloc(&(g_malloc.list_tiny), T_TINY, 1, 1);
	ft_putstr(SMALL_STR);
	ft_putstr(" : ");
	if (g_malloc.list_small)
		ptr_addr_to_str(findmin_tree_t_malloc(g_malloc.list_small)->ptr, 1, 0);
	ft_putchar('\n');
	print_tree_t_malloc(&(g_malloc.list_small), T_SMALL, 1, 1);
	show_alloc_mem_large(1);
	print_rlimits();
}
