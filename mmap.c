/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*mmap_anon(size_t size, char *fail_string)
{
	void	*ptr;

	ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
	MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!check_nmap(ptr, size, fail_string))
		return (NULL);
	return (ptr);
}

void		*mmap_anon_shared(size_t size, char *fail_string)
{
	void	*ptr;

	ptr = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	if (!check_nmap(ptr, size, fail_string))
		return (NULL);
	return (ptr);
}
