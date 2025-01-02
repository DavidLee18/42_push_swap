/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:12:37 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/03 03:04:28 by jaehylee         ###   ########.fr       */
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
		res += (h.root[i] != NULL);
		i++;
	}
	return (res);
}

_Bool	hcomplete(t_min_heap h)
{
	return (hpat(h) == 1 && h.root[h.offset] && *h.root[h.offset] == -1);
}

void	print_heap(t_min_heap h)
{
	size_t	i;

	i = 0;
	ft_printf("heap[");
	while (i + h.offset < h.cap)
	{
		if (h.root[i + h.offset] != NULL)
		{
			ft_printf("%d", *h.root[i + h.offset]);
			if (i + h.offset + 1 < h.cap)
				ft_printf(", ");
		}
		i++;
	}
	ft_printf("]\n");
}

size_t	hpat2(t_min_heap h)
{
	if (h.root[h.offset] == NULL)
		return (0);
	if (h.root[1 + 2 * h.offset] != NULL
		&& h.root[2 + 2 * h.offset] != NULL)
		return (4);
	if (h.root[1 + 2 * h.offset] == NULL
		&& h.root[2 + 2 * h.offset] == NULL)
		return (1);
	if (h.root[1 + 2 * h.offset] == NULL
		&& h.root[2 + 2 * h.offset] != NULL)
		return (3);
	return (2);
}

ssize_t	insert1(t_list **dyn, t_min_heap *h, ssize_t dist)
{
	_Bool	alloced;
	_Bool	swapped;

	if (hpat(*h) == 1)
	{
		while (h->cap <= 2 * h->offset + 1)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[2 * h->offset + 1] = (ssize_t *)gc_calloc(dyn, 1,
				sizeof(ssize_t));
		if (h->root[2 * h->offset + 1] == NULL)
			return (-1);
		*h->root[2 * h->offset + 1] = dist;
		if (abs_isize(*h->root[h->offset]) > abs_isize(dist))
		{
			swapped = hswap(h, 0, 1);
			if (!swapped)
				return (-1);
		}
		h->len = 2 * h->offset + 1;
		return (h->cap);
	}
	return (insert2(dyn, h, dist));
}
