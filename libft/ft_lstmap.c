/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/11/06 22:47:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list_ptr;
	t_list		*mlist;
	t_list		*mlistptr;
	t_list		*mlistnext;

	mlist = NULL;
	if (lst == NULL)
		return (NULL);
	list_ptr = lst;
	while (list_ptr->next != NULL)
	{
		if (!(mlistnext = (*f)(list_ptr)))
			return (NULL);
		if (mlist == NULL)
			mlist = mlistnext;
		else
			mlistptr->next = mlistnext;
		mlistptr = mlistnext;
		while (mlistptr->next != NULL)
			mlistptr = mlistptr->next;
		list_ptr = list_ptr->next;
	}
	mlistptr->next = (*f)(list_ptr);
	return (mlist);
}
