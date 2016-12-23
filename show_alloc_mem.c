/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					print_t_malloc_zone_sectors(t_malloc_t *cur_m,
													int extra)
{
	cur_m->i = -1;
	while (++(cur_m->i) < SECTOR_SIZE)
	{
		if (!cur_m->ptr_slot[cur_m->i])
			continue;
		ptr_addr_to_str(cur_m->ptr_sect[cur_m->i], 1, 0);
		ft_putstr(" - ");
		ptr_addr_to_str((cur_m->ptr_sect[cur_m->i]
						+ cur_m->ptr_sizes[cur_m->i] - 1), 1, 0);
		ft_putstr(" : ");
		ft_putnbr(cur_m->ptr_sizes[cur_m->i]);
		ft_putstr(" octets");
		if (!extra)
			ft_putchar('\n');
		if (!extra)
			continue ;
		ft_putstr(" - ");
		ft_putstr(ctime(&(cur_m->ptr_times[cur_m->i])));
	}
}

void					print_t_malloc_whole(t_malloc_t *cur_m, int extra)
{
	ptr_addr_to_str(cur_m->ptr, 1, 0);
	ft_putstr(" - ");
	ptr_addr_to_str(cur_m->ptr + cur_m->size - 1, 1, 0);
	ft_putstr(" : ");
	ft_putnbr(cur_m->size);
	ft_putstr(" octets");
	if (!extra)
		ft_putchar('\n');
	if (!extra)
		return ;
	ft_putstr(" - ");
	ft_putstr(ctime(&(cur_m->ptr_times[0])));
}

void					print_tree_t_malloc(t_malloc_t **root, t_malloc_type t,
											int in_zone, int extra)
{
	if ((*root) == NULL)
		return ;
	print_tree_t_malloc(&(*root)->back, t, in_zone, extra);
	if ((in_zone) && ((*root)->type == t))
		print_t_malloc_zone_sectors((*root), extra);
	else if ((*root)->type == t)
		print_t_malloc_whole((*root), extra);
	print_tree_t_malloc(&(*root)->front, t, in_zone, extra);
}

void					show_alloc_mem_large(int extra)
{
	ft_putstr(LARGE_STR);
	ft_putstr(" : ");
	if (g_malloc.list_large)
		ptr_addr_to_str(findmin_tree_t_malloc(g_malloc.list_large)->ptr, 1, 0);
	ft_putchar('\n');
	print_tree_t_malloc(&(g_malloc.list_large), T_LARGE, 0, extra);
}

void					show_alloc_mem(void)
{
	if (!init_malloc())
		return ;
	ft_putstr(TINY_STR);
	ft_putstr(" : ");
	if (g_malloc.list_tiny)
		ptr_addr_to_str(findmin_tree_t_malloc(g_malloc.list_tiny)->ptr, 1, 0);
	ft_putchar('\n');
	print_tree_t_malloc(&(g_malloc.list_tiny), T_TINY, 1, 0);
	ft_putstr(SMALL_STR);
	ft_putstr(" : ");
	if (g_malloc.list_small)
		ptr_addr_to_str(findmin_tree_t_malloc(g_malloc.list_small)->ptr, 1, 0);
	ft_putchar('\n');
	print_tree_t_malloc(&(g_malloc.list_small), T_SMALL, 1, 0);
	show_alloc_mem_large(0);
}
