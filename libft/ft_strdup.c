/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:05:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:12:01 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_bcopy(const char *src, char *dest, int len)
{
	const char	*lasts;
	char		*lastd;

	if (dest < src)
		while (len--)
			*dest++ = *src++;
	else
	{
		lasts = src + (len - 1);
		lastd = dest + (len - 1);
		while (len--)
			*(char *)lastd-- = *(char *)lasts--;
	}
}

char			*ft_strdup(const char *str)
{
	int		siz;
	char	*copy;

	siz = ft_strlen(str) + 1;
	if ((copy = malloc(siz)) == NULL)
		return (NULL);
	ft_bcopy(str, copy, siz);
	return (copy);
}
