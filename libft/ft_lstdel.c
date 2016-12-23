/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/11/06 22:47:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		**mlist;
	t_list		*thenext;

	if (alst == NULL)
		return ;
	else if (*alst == NULL)
		return ;
	mlist = alst;
	while ((*mlist)->next != NULL)
	{
		thenext = (*mlist)->next;
		ft_lstdelone(mlist, del);
		*mlist = NULL;
		*mlist = thenext;
	}
	ft_lstdelone(mlist, del);
	mlist = NULL;
	*alst = NULL;
}
