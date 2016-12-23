/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 10:52:40 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/02 11:54:52 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int count;
	int x;

	count = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (count++ < nb / 2)
	{
		x = count * count;
		if (count != 0 && x / count != count)
			return (0);
		else if (x == nb)
			return (count);
	}
	return (0);
}
