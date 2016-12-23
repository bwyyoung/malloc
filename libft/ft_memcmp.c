/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*p1;
	const char	*p2;

	p1 = s1;
	p2 = s2;
	if (n > 0)
		while (n > 0)
		{
			if (*p1++ != *p2++)
				return ((unsigned char)*--p1 - (unsigned char)*--p2);
			n--;
		}
	return (0);
}
