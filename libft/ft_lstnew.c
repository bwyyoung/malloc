/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 09:50:50 by byoung-w          #+#    #+#             */
/*   Updated: 2014/11/06 22:47:08 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*mlist;

	mlist = (t_list *)malloc(sizeof(t_list));
	if (mlist == NULL)
		return (NULL);
	mlist->next = NULL;
	mlist->content = NULL;
	mlist->content_size = 0;
	if (content != NULL)
	{
		mlist->content = malloc(sizeof(content));
		if (mlist->content == NULL)
			return (NULL);
		ft_memcpy(mlist->content, content, sizeof(content));
		mlist->content_size = content_size;
	}
	return (mlist);
}
