/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 14:30:12 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char		c;
	int			len;
	char		sc;
	int			originlen;
	const char	*strptr;

	if (str == NULL || to_find == NULL)
		return (NULL);
	c = (*to_find);
	len = ft_strlen(to_find);
	sc = (*str);
	originlen = ft_strlen(str);
	if (!c)
		return ((char *)str);
	else if (!sc)
		return ((char *)0);
	strptr = str;
	while (ft_strncmp(strptr, to_find, len) != 0 && *strptr != '\0')
	{
		strptr++;
		originlen--;
	}
	if (originlen > 0)
		return ((char *)strptr);
	return (NULL);
}
