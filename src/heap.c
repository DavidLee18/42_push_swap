/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:24:14 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/27 06:50:28 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	insert(t_min_heap *h, ssize_t dist)
{
	if (h == NULL)
		return (0);
	if (dist == 0)
		return (h->cap);
	if (hpat(*h) == 0)
	{
		while (h->cap <= h->offset)
			halloc(h);
		h->root[h->offset] = dist;
		return (h->cap);
	}
	if (hpat(*h) == 1)
	{
		while (h->cap <= 2 * h->offset + 1)
			halloc(h);
		h->root[2 * h->offset + 1] = dist;
		if (abs_isize(h->root[h->offset]) > abs_isize(dist))
			bubble_down(h, 0, 1);
		return (h->cap);
	}
	return (insert2(h, dist));
}

size_t	insert2(t_min_heap *h, ssize_t dist)
{
	if (hpat(*h) == 2)
	{
		while (h->cap <= 2 * h->offset + 2)
			halloc(h);
		h->root[2 * h->offset + 2] = dist;
		if (abs_isize(h->root[h->offset]) > abs_isize(dist))
			h->cap = bubble_down(h, 0, 2);
		return (h->cap);
	}
	else if (hpat(*h) == 3)
	{
		h->root[2 * h->offset + 1] = dist;
		if (abs_isize(h->root[h->offset]) > abs_isize(dist))
			h->cap = bubble_down(h, 0, 1);
		return (h->cap);
	}
	return (insert3(h, dist));
}

ssize_t	extract(t_min_heap *h)
{
	ssize_t	res;

	if (!h || hpat(*h) == 0)
		return (0);
	res = h->root[h->offset];
	// TODO: bubble down
	return (res);
}

void	halloc(t_min_heap *h)
{
	if (!h)
		return ;
	if (h->cap == 0)
		h->root = (ssize_t *)ft_calloc(1, sizeof(ssize_t));
	else
		ft_realloc((void **)&h->root, h->cap * sizeof(ssize_t),
			h->cap * 2 * sizeof(ssize_t));
	if (!h->root)
		return ;
	if (h->cap == 0)
		h->cap = 1;
	else
		h->cap *= 2;
}

size_t	max_balanced_depth(t_min_heap h)
{
	if (hpat(h) <= 1)
		return (0);
	else if (hpat(h) <= 3)
		return (1);
	else
		return (1 + min_usize(max_balanced_depth(
					(t_min_heap){.root = h.root, .cap = h.cap,
					.offset = 2 * h.offset + 1}),
			max_balanced_depth((t_min_heap){.root = h.root, .cap = h.cap,
				.offset = 2 * h.offset + 2})));
}
