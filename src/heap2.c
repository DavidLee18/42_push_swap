/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/28 21:59:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hswap(t_min_heap *h, size_t a, size_t b)
{
	ssize_t	temp;

	if (h == NULL)
		return ;
	if (hpat(*h) <= 1 || a == b || a > 2 || b > 2 || (a != 0 && b != 0))
		return ;
	if (a == 1 || a == 2)
		a += 2 * h->offset;
	else if (b == 1 || b == 2)
		b += 2 * h->offset;
	temp = h->root[a];
	h->root[a] = h->root[b];
	h->root[b] = temp;
}

// size_t	bubble_down(t_min_heap *h, size_t a, size_t b)
// {
// 	t_min_heap	next;

// 	if (h == NULL)
// 		return (0);
// 	if (hpat(*h) <= 1 || a == b || a > 2 || b > 2 || (a != 0 && b != 0))
// 		return (h->cap);
// 	hswap(h, a, b);
// 	if (a == 1 || a == 2)
// 		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = a + 2
// 			* h->offset};
// 	else
// 		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = b + 2
// 			* h->offset};
// 	return (balance(&next));
// }

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

size_t	insert3(t_list **dyn, t_min_heap *h, ssize_t dist)
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
		h->cap = insert(dyn, &l, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist < h->root[h->offset])
	{
		h->cap = insert(dyn, &r, h->root[h->offset]);
		h->root[h->offset] = dist;
	}
	else if (dist >= h->root[h->offset] && max_balanced_depth(l)
		<= max_balanced_depth(r))
		h->cap = insert(dyn, &l, dist);
	else if (dist >= h->root[h->offset])
		h->cap = insert(dyn, &r, dist);
	return (h->cap);
}

void	extract2(t_min_heap *h)
{
	t_min_heap	next;

	if (h->root[1 + 2 * h->offset] <= h->root[2 + 2 * h->offset])
	{
		h->root[h->offset] = h->root[1 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 1 + 2
			* h->offset};
	}
	else
	{
		h->root[h->offset] = h->root[2 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 2 + 2
			* h->offset};
	}
	extract(&next);
}
