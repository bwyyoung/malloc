/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlimit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		print_rlimit(struct rlimit *r, const char *name)
{
	int64_t cur;
	int64_t max;

	cur = r->rlim_cur;
	max = r->rlim_max;
	ft_putstr("RLIMIT_");
	ft_putstr(name);
	ft_putstr(" :rlim_cur => ");
	ptr_addr_to_str((void *)r->rlim_cur, 1, 0);
	ft_putstr(" :rlim_max => ");
	ptr_addr_to_str((void *)r->rlim_max, 1, 0);
	ft_putstr("\n");
}

void		print_rlimits(void)
{
	struct rlimit	rlim;
	int				i;

	ft_putstr("-------RLIMIT_DATA-------\n");
	i = 0;
	while (i < 4)
	{
		getrlimit(L1[i], &rlim);
		print_rlimit(&rlim, L2[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		getrlimit(L3[i], &rlim);
		print_rlimit(&rlim, L4[i]);
		i++;
	}
	getrlimit(RLIMIT_STACK, &rlim);
	print_rlimit(&rlim, "STACK");
	ft_putstr("-------RLIMIT_DATA_END---\n");
	return ;
}
