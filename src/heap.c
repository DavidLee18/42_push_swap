/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:24:14 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/08 12:23:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	insert(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	_Bool	alloced;

	if (h == NULL)
		return (0);
	if (hpat(*h, offset) == 0)
	{
		alloced = 1;
		while (h->cap <= offset)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[offset] = (t_rel_dist *)gc_calloc(dyn, 1,
				sizeof(t_rel_dist));
		if (h->root[offset] == NULL)
			return (-1);
		*h->root[offset] = dist;
		h->len++;
		return ((ssize_t)h->cap);
	}
	return (insert1(dyn, h, dist, offset));
}

ssize_t	insert2(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	_Bool	alloced;

	if (hpat(*h, offset) == 2)
	{
		alloced = 1;
		while (h->cap <= 2 * offset + 2)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[2 * offset + 2] = (t_rel_dist *)gc_calloc(dyn, 1,
				sizeof(t_rel_dist));
		if (h->root[2 * offset + 2] == NULL)
			return (-1);
		*h->root[2 * offset + 2] = dist;
		if (h->root[offset]->value > dist.value)
			if (!hswap(h, offset, 2 * offset + 2, offset))
				return (-1);
		h->len = 2 * offset + 2;
		return ((ssize_t)h->cap);
	}
	return (insert3(dyn, h, dist, offset));
}

t_rel_dist	*extract(t_min_heap *h, size_t offset)
{
	t_rel_dist	*res;

	if (!h || hpat(*h, offset) == 0)
		return (NULL);
	res = h->root[offset];
	if (hpat(*h, offset) == 1)
		h->root[offset] = NULL;
	else if (hpat(*h, offset) == 2)
	{
		h->root[offset] = h->root[1 + 2 * offset];
		extract(h, 1 + 2 * offset);
	}
	else if (hpat(*h, offset) == 3)
	{
		h->root[offset] = h->root[2 + 2 * offset];
		extract(h, 2 + 2 * offset);
	}
	else
		extract2(h, offset);
	return (res);
}

_Bool	halloc(t_list **dyn, t_min_heap *h)
{
	_Bool	alloced;

	if (!h)
		return (0);
	if (h->cap == 0)
	{
		h->root = (t_rel_dist **)gc_calloc(dyn, 1, sizeof(t_rel_dist *));
		alloced = h->root != NULL;
	}
	else
		alloced = gc_realloc(dyn, (void **)&(h->root), h->cap
				* sizeof(t_rel_dist *), h->cap * 2 * sizeof(t_rel_dist *));
	if (!alloced)
		return (0);
	if (h->cap == 0)
		h->cap = 1;
	else
		h->cap *= 2;
	return (1);
}

size_t	max_balanced_depth(t_min_heap h, size_t offset)
{
	if (hpat(h, offset) <= 1)
		return (0);
	else if (hpat(h, offset) <= 3)
		return (1);
	else
		return (1 + min_usize(max_balanced_depth(h, 2 * offset + 1),
				max_balanced_depth(h, 2 * offset + 2)));
}
