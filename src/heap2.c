/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/03 04:57:41 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	hswap(t_min_heap *h, size_t a, size_t b)
{
	ssize_t	*temp;

	if (h == NULL)
		return (0);
	if (hpat(*h) <= 1 || a == b || a > 2 || b > 2 || (a != 0 && b != 0))
		return (0);
	if (a == 1 || a == 2)
		a += 2 * h->offset;
	else if (b == 1 || b == 2)
		b += 2 * h->offset;
	temp = h->root[a];
	h->root[a] = h->root[b];
	h->root[b] = temp;
	return (1);
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
	if (h.root == NULL || h.cap <= h.offset || h.root[h.offset] == NULL)
		return (0);
	if (h.cap <= 1 + 2 * h.offset)
		return (h.root[h.offset] != NULL);
	if (h.cap <= 2 + 2 * h.offset)
	{
		if (h.root[h.offset] == NULL)
			return (0);
		if (h.root[1 + 2 * h.offset] != NULL)
			return (2);
		return (1);
	}
	return (hpat2(h));
}

ssize_t	insert3(t_list **dyn, t_min_heap *h, ssize_t dist)
{
	_Bool	swapped;

	if (hpat(*h) == 3)
	{
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
		h->len = 2 * h->offset + 2;
		return ((ssize_t)h->cap);
	}
	return (insert4(dyn, h, dist));
}

void	extract2(t_min_heap *h)
{
	t_min_heap	next;

	if (h->root[1 + 2 * h->offset] <= h->root[2 + 2 * h->offset])
	{
		h->root[h->offset] = h->root[1 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 1 + 2
			* h->offset, .len = h->len - 1 - h->offset};
	}
	else
	{
		h->root[h->offset] = h->root[2 + 2 * h->offset];
		next = (t_min_heap){.root = h->root, .cap = h->cap, .offset = 2 + 2
			* h->offset, .len = h->len - 2 - h->offset};
	}
	extract(&next);
}
