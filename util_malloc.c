/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		format_hex(char *p)
{
	int		i;
	int		j;

	p[HEX_LEN - 1] = '\0';
	i = ft_strlen(p) - 1;
	j = ft_strlen(p) - 1;
	while (i >= 0)
	{
		if (p[i] == '0')
			j = i;
		else
			break ;
		i--;
	}
	p[i + 3] = '\0';
	p = ft_strrev(p);
	if (ft_strlen(p) > 2)
		p[1] = 'x';
	else
		p[1] = '\0';
}

char		*ptr_addr_to_str(void *ptr_address, int print, char *p)
{
	uint32_t	h;
	int			i;
	uintptr_t	j;

	j = (uintptr_t)ptr_address;
	i = 0;
	if (!p)
		p = g_malloc.ptr_str_1;
	ft_bzero(p, HEX_LEN);
	while (i < (int)(HEX_LEN - 1))
	{
		h = (unsigned int)(unsigned char)(j & 0xff);
		p[i] = HEX_STR[h % 16];
		p[i + 1] = HEX_STR[h / 16 % 16];
		j >>= 8;
		i += 2;
	}
	format_hex(p);
	if (print)
		ft_putstr(p);
	return (p);
}

int			ptr_inside(void *array, size_t size, void *other_pointer)
{
	return ((other_pointer >= array) && (other_pointer < array + size));
}

int			ptr_compare(void *p1, void *p2)
{
	if (p1 > p2)
		return (-1);
	else if (p1 < p2)
		return (1);
	return (0);
}
