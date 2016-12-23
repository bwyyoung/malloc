/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 17:57:08 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/14 02:10:59 by sessaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**create2dchararray(char **strings, int *elements, int l1)
{
	int		i;

	i = 0;
	if (!(strings = (char **)malloc((l1 + 1) * sizeof(char *))))
		return (NULL);
	while (i < l1)
	{
		if (!(strings[i] = ft_strnew(elements[i])))
			return (NULL);
		i++;
	}
	strings[i] = NULL;
	free(elements);
	return (strings);
}

static char		**populate2darray(char **strings, char const *s, char c, int i)
{
	int		j;
	char	lastchar;

	j = 0;
	lastchar = *s;
	while (*s != '\0')
	{
		if (lastchar != c && *s == c)
		{
			strings[i][j] = '\0';
			i++;
			j = 0;
		}
		else if (*s != c)
		{
			strings[i][j] = *s;
			j++;
		}
		lastchar = *s;
		s++;
	}
	return (strings);
}

static void		getlengthsubelements(int *elements,
char const *s, char c, int i)
{
	int		curelement;
	char	lastchar;

	curelement = 0;
	lastchar = s[i];
	if (lastchar != c)
		elements[curelement]++;
	while (s[i] != '\0')
	{
		if (i > 0)
		{
			if (lastchar != c && s[i] == c)
			{
				elements[curelement]++;
				curelement++;
			}
			else if (lastchar != c && s[i] != c)
			{
				elements[curelement]++;
			}
		}
		lastchar = s[i];
		i++;
	}
}

static int		getnumelements(char const *s, char c)
{
	char	lastchar;
	int		length1;
	int		i;

	i = 0;
	length1 = 0;
	lastchar = s[i];
	if (lastchar != c && lastchar != '\0')
		length1++;
	while (s[i] != '\0')
	{
		if (i > 0)
			if (lastchar == c && s[i] != c)
				length1++;
		lastchar = s[i];
		i++;
	}
	return (length1);
}

char			**ft_strsplit(char const *s, char c)
{
	int			*elements;
	int			l1;
	int			i;
	char const	*s2;
	char		**strings;

	if (!s || !c)
		return (NULL);
	i = 0;
	strings = NULL;
	s2 = s;
	l1 = getnumelements(s, c);
	if (!(elements = (int *)malloc(sizeof(int) * l1)))
		return (NULL);
	while (i < l1)
	{
		elements[i] = 0;
		i++;
	}
	i = 0;
	getlengthsubelements(elements, s, c, i);
	if (!(strings = create2dchararray(strings, elements, l1)))
		return (NULL);
	return (populate2darray(strings, s2, c, i));
}
