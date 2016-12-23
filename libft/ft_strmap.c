/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		sp;
	int		j;
	char	*snew;

	snew = NULL;
	if (s != NULL && (*f) != NULL)
	{
		j = 0;
		snew = ft_strnew(ft_strlen((char const *)s));
		sp = 0;
		while (s[sp] != '\0')
		{
			snew[j] = (*f)(s[sp]);
			j++;
			sp++;
		}
	}
	return (snew);
}
