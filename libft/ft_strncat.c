/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 17:57:22 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t nb)
{
	char *destcopy;

	destcopy = dest;
	if (nb != 0)
	{
		while (*destcopy)
			destcopy++;
		while (nb != 0)
		{
			if ((*destcopy = *src) == 0)
			{
				break ;
			}
			src++;
			destcopy++;
			nb--;
		}
		*destcopy = 0;
	}
	return (dest);
}
