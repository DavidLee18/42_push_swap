/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:24:14 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/03 04:57:22 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	insert(t_list **dyn, t_min_heap *h, t_rel_dist dist)
{
	_Bool	alloced;

	if (h == NULL)
		return (0);
	if (hpat(*h) == 0)
	{
		while (h->cap <= h->offset)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[h->offset] = (t_rel_dist *)gc_calloc(dyn, 1, sizeof(t_rel_dist));
		if (h->root[h->offset] == NULL)
			return (-1);
		*h->root[h->offset] = dist;
		h->len++;
		return ((ssize_t)h->cap);
	}
	return (insert1(dyn, h, dist));
}

ssize_t	insert2(t_list **dyn, t_min_heap *h, t_rel_dist dist)
{
	_Bool	alloced;
	_Bool	swapped;

	if (hpat(*h) == 2)
	{
		while (h->cap <= 2 * h->offset + 2)
			alloced = halloc(dyn, h);
		if (!alloced)
			return (-1);
		h->root[2 * h->offset + 2] = (t_rel_dist *)gc_calloc(dyn, 1,
				sizeof(t_rel_dist));
		if (h->root[2 * h->offset + 2] == NULL)
			return (-1);
		*h->root[2 * h->offset + 2] = dist;
		if (abs_isize(absol_dist(*h->root[h->offset])) > abs_isize(absol_dist(dist)))
		{
			swapped = hswap(h, 0, 2);
			if (!swapped)
				return (-1);
		}
		h->len = 2 * h->offset + 2;
		return ((ssize_t)h->cap);
	}
	return (insert3(dyn, h, dist));
}

t_rel_dist	*extract(t_min_heap *h)
{
	t_rel_dist	*res;
	t_min_heap	next;

	if (!h || hpat(*h) == 0)
		return (NULL);
	res = h->root[h->offset];
	if (hpat(*h) == 1)
		h->root[h->offset] = NULL;
	else if (hpat(*h) == 2)
	{
		h->root[h->offset] = h->root[1 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 1 + 2
			* h->offset, .len = h->len - 1 - h->offset};
		extract(&next);
	}
	else if (hpat(*h) == 3)
	{
		h->root[h->offset] = h->root[2 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 2 + 2
			* h->offset, .len = h->len - 2 - h->offset};
		extract(&next);
	}
	else
		extract2(h);
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

size_t	max_balanced_depth(t_min_heap h)
{
	if (hpat(h) <= 1)
		return (0);
	else if (hpat(h) <= 3)
		return (1);
	else
		return (1 + min_usize(max_balanced_depth(
					(t_min_heap){.root = h.root, .cap = h.cap, .len = h.len
					- h.offset - 1, .offset = 2 * h.offset + 1}),
			max_balanced_depth((t_min_heap){.root = h.root, .cap = h.cap,
				.len = h.len - h.offset - 2, .offset = 2 * h.offset + 2})));
}
