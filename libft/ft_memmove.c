/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s < d)
	{
		d += len;
		s += len;
		while (len > 0)
		{
			len--;
			*--d = *--s;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			*d++ = *s++;
		}
	}
	return (dst);
}
