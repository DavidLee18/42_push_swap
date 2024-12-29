/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:12:37 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 15:39:53 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	hlen(t_min_heap h)
{
	size_t	res;
	size_t	i;

	if (hpat(h) == 0)
		return (0);
	i = h.offset;
	res = 0;
	while (i < h.cap)
	{
		res += (h.root[i] != 0);
		i++;
	}
	return (res);
}

_Bool	hcomplete(t_min_heap h)
{
	return (hpat(h) == 1 && h.root[h.offset] == -1);
}

void	print_heap(t_min_heap h)
{
	size_t	i;

	i = 0;
	ft_printf("heap[");
	while (i + h.offset < h.cap)
	{
		ft_printf("%d", h.root[i + h.offset]);
		if (i + h.offset + 1 < h.cap)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}
