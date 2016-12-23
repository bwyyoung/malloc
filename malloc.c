/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				init_malloc(void)
{
	if (g_malloc.init == 1)
		return (1);
	g_malloc.list_tiny = NULL;
	g_malloc.list_small = NULL;
	g_malloc.list_large = NULL;
	return (g_malloc.init = 1);
}

int				check_nmap(void *ptr, size_t size, char *error)
{
	if (!ptr || ptr == MAP_FAILED || size == 0)
	{
		malloc_error(error);
		return (0);
	}
	return (1);
}

void			*malloc_error(char *error)
{
	void	*p;

	p = NULL;
	ft_putstr("ERROR:");
	ft_putstr(error);
	ft_putchar('\n');
	return (p);
}

t_malloc_type	get_malloc_type(size_t size)
{
	if (size >= 1 && size <= N)
		return (T_TINY);
	else if (size > N && size <= M)
		return (T_SMALL);
	else
		return (T_LARGE);
}

void			*malloc(size_t size)
{
	if (!init_malloc())
		return (malloc_error("Initialisation Failed"));
	if (size == 0)
		return (NULL);
	if (get_malloc_type(size) == T_TINY)
		return (malloc_tiny(size));
	else if (get_malloc_type(size) == T_SMALL)
		return (malloc_small(size));
	else
		return (malloc_large(size));
}
