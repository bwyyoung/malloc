/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findn(int num)
{
	int		n;

	n = 0;
	while (num)
	{
		num /= 10;
		n++;
	}
	return (n);
}

static char	*calcmore0(int n, char *p)
{
	while (n != 0)
	{
		*--p = '0' + (n % 10);
		n /= 10;
	}
	return (p);
}

static char	*calcless0(int n, char *p)
{
	while (n != 0)
	{
		*--p = '0' - (n % 10);
		n /= 10;
	}
	*--p = '-';
	return (p);
}

char		*ft_itoa(int n)
{
	char		*p;
	int			add;

	if (n == 0)
	{
		if (!(p = ft_strnew(1)))
			return (NULL);
		*p = '0';
		return (p);
	}
	else if (n > 0)
		add = 0;
	else
		add = 1;
	if (!(p = ft_strnew(findn(n) + add)))
		return (NULL);
	p = p + findn(n) + add;
	*p = '\0';
	if (n > 0)
		return (calcmore0(n, p));
	else
		return (calcless0(n, p));
}
