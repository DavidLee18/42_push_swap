/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:12:37 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/07 15:08:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	hlen(t_min_heap h, size_t offset)
{
	size_t	res;
	size_t	i;

	if (hpat(h, offset) == 0)
		return (0);
	i = offset;
	res = 0;
	while (i < h.cap)
	{
		res += (h.root[i] != NULL);
		i++;
	}
	return (res);
}

_Bool	hcomplete(t_min_heap h, size_t vlen, size_t offset)
{
	return (hpat(h, offset) == 1 && h.root[offset]
		&& (h.root[offset]->dist == -1
			|| h.root[offset]->dist == (ssize_t)vlen - 1));
}

void	print_heap(t_min_heap h, size_t offset)
{
	size_t	i;

	i = 0;
	ft_printf("heap[");
	while (i + offset < h.cap)
	{
		if (h.root[i + offset] != NULL)
		{
			print_rel_dist(*h.root[i + offset]);
			if (i + offset + 1 < h.cap)
				ft_printf(", ");
		}
		i++;
	}
	ft_printf("]\n");
}

size_t	hpat2(t_min_heap h, size_t offset)
{
	if (h.root[offset] == NULL)
		return (0);
	if (h.root[1 + 2 * offset] != NULL
		&& h.root[2 + 2 * offset] != NULL)
		return (4);
	if (h.root[1 + 2 * offset] == NULL
		&& h.root[2 + 2 * offset] == NULL)
		return (1);
	if (h.root[1 + 2 * offset] == NULL
		&& h.root[2 + 2 * offset] != NULL)
		return (3);
	return (2);
}

ssize_t	insert1(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	_Bool	alloced;

	alloced = 1;
	if (hpat(*h, offset) == 1)
	{
		while (h->cap <= 2 * offset + 1)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[2 * offset + 1] = (t_rel_dist *)gc_calloc(dyn, 1,
				sizeof(t_rel_dist));
		if (h->root[2 * offset + 1] == NULL)
			return (-1);
		*h->root[2 * offset + 1] = dist;
		if (h->root[offset]->value
			> dist.value)
			if (!hswap(h, offset, 1 + 2 * offset, offset))
				return (-1);
		h->len = 2 * offset + 1;
		return ((ssize_t)h->cap);
	}
	return (insert2(dyn, h, dist, offset));
}
