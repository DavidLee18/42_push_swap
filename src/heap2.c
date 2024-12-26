/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/26 22:57:15 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hswap(t_min_heap *h, size_t a, size_t b)
{
	ssize_t	temp;

	if (!h || !h->root || h->cap == 0 || a == b || a > 2 || b > 2)
		return ;
	a += h->offset;
	b += h->offset;
	if (a == 1 || a == 2)
		a += h->offset;
	if (b == 1 || b == 2)
		b += h->offset;
	temp = h->root[a];
	h->root[a] = h->root[b];
	h->root[b] = temp;
}

size_t	hpat(t_min_heap h)
{
	if (h.root == NULL || h.cap < 1 + 2 * h.offset)
		return (0);
	else if (h.cap < 2 + 2 * h.offset)
		return (1 - h.root[1 + 2 * h.offset]);
	else
	{
		if (h.root[1 + 2 * h.offset] != 0
			&& h.root[2 + 2 * h.offset] != 0)
			return (3);
		else if (h.root[1 + 2 * h.offset] == 0
			&& h.root[2 + 2 * h.offset] == 0)
			return (0);
		else if (h.root[1 + 2 * h.offset] == 0
			&& h.root[2 + 2 * h.offset] != 0)
			return (2);
		else
			return (1);
	}
}

void	insert3(t_min_heap *h, ssize_t dist)
{
	t_min_heap	l;
	t_min_heap	r;

	l = (t_min_heap){.root = h->root, .cap = h->cap,
		.offset = h->offset * 2 + 1};
	r = (t_min_heap){.root = h->root, .cap = h->cap,
		.offset = h->offset * 2 + 2};
	if (dist < h->root[h->offset] && max_balanced_depth(l)
		<= max_balanced_depth(r))
	{
		insert(&l, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist < h->root[h->offset])
	{
		insert(&r, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist >= h->root[h->offset] && max_balanced_depth(l)
		<= max_balanced_depth(r))
		insert(&l, dist);
	else if (dist >= h->root[h->offset])
		insert(&r, dist);
}

_Bool	null(t_min_heap h)
{
	return (h.cap == 0 || h.root == NULL);
}
