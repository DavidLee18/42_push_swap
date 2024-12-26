/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/27 06:40:50 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	bubble_down(t_min_heap *h, size_t a, size_t b)
{
	ssize_t		temp;
	t_min_heap	next;

	if (h == NULL)
		return (0);
	if (hpat(*h) <= 1 || a == b || a > 2 || b > 2 || (a != 0 && b != 0))
		return (h->cap);
	a += h->offset;
	b += h->offset;
	if (a - h->offset == 1 || a - h->offset == 2)
		a += h->offset;
	else if (b - h->offset == 1 || b - h->offset == 2)
		b += h->offset;
	temp = h->root[a];
	h->root[a] = h->root[b];
	h->root[b] = temp;
	if (a == 2 * h->offset + 1 || a == 2 * h->offset + 2)
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = a};
	else
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = b};
	return (balance(&next));
}

size_t	hpat(t_min_heap h)
{
	if (h.root == NULL || h.cap <= h.offset || h.root[h.offset] == 0)
		return (0);
	else if (h.cap <= 1 + 2 * h.offset)
		return (1);
	else if (h.cap <= 2 + 2 * h.offset)
		return (1 + h.root[1 + 2 * h.offset] != 0);
	else
	{
		if (h.root[1 + 2 * h.offset] != 0
			&& h.root[2 + 2 * h.offset] != 0)
			return (4);
		else if (h.root[1 + 2 * h.offset] == 0
			&& h.root[2 + 2 * h.offset] == 0)
			return (1);
		else if (h.root[1 + 2 * h.offset] == 0
			&& h.root[2 + 2 * h.offset] != 0)
			return (3);
		else
			return (2);
	}
}

size_t	insert3(t_min_heap *h, ssize_t dist)
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
		h->cap = insert(&l, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist < h->root[h->offset])
	{
		h->cap = insert(&r, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist >= h->root[h->offset] && max_balanced_depth(l)
		<= max_balanced_depth(r))
		h->cap = insert(&l, dist);
	else if (dist >= h->root[h->offset])
		h->cap = insert(&r, dist);
	return (h->cap);
}

size_t		balance(t_min_heap *h);
