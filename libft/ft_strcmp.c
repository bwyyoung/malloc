/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:05:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/03 17:05:17 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	char const	*temp1;
	char const	*temp2;

	temp1 = s1;
	temp2 = s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	while (*temp1 == *temp2++)
	{
		if (*temp1 == 0)
			return (0);
		temp1++;
	}
	return (*(unsigned char *)temp1 - *(unsigned char *)--temp2);
}
