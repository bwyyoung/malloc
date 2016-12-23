/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*strnew;
	unsigned int		i;
	unsigned int		j;

	strnew = NULL;
	if (s == NULL)
		return (NULL);
	if (!(strnew = ft_strnew(len)))
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len && s[i] != '\0')
	{
		strnew[j] = s[i];
		i++;
		j++;
	}
	return (strnew);
}
