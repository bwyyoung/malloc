/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 17:57:22 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		do_strlcat_l(int delta, int nb, char *destcopy,
const char *src)
{
	const char	*srccopy;

	srccopy = src;
	while (*srccopy != '\0')
	{
		if (nb != 1)
		{
			*destcopy = *srccopy;
			destcopy++;
			nb--;
		}
		srccopy++;
	}
	*destcopy = '\0';
	return ((srccopy - src) + delta);
}

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*destcopy;
	int		nb;
	int		delta;

	destcopy = dest;
	nb = size;
	while (*destcopy != '\0' && nb-- != 0)
		destcopy++;
	delta = (destcopy - dest);
	nb = size - delta;
	if (nb == 0)
		return (delta + ft_strlen(src));
	return (do_strlcat_l(delta, nb, destcopy, src));
}
