/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	int		i;
	int		j;

	strnew = NULL;
	if (s1 && s2)
	{
		if (!(strnew = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			strnew[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			strnew[i] = s2[j];
			i++;
			j++;
		}
	}
	return (strnew);
}
