/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/06 14:22:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	hswap(t_min_heap *h, size_t a, size_t b, size_t offset)
{
	t_rel_dist	*temp;

	if (h == NULL)
		return (0);
	if (hpat(*h, offset) <= 1 || a == b || a > 2 || b > 2 || (a != 0 && b != 0))
		return (0);
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

size_t	hpat(t_min_heap h, size_t offset)
{
	if (h.root == NULL || h.cap <= offset || h.root[offset] == NULL)
		return (0);
	if (h.cap <= 1 + 2 * offset)
		return (h.root[offset] != NULL);
	if (h.cap <= 2 + 2 * offset)
	{
		if (h.root[offset] == NULL)
			return (0);
		if (h.root[1 + 2 * offset] != NULL)
			return (2);
		return (1);
	}
	return (hpat2(h, offset));
}

ssize_t	insert3(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	_Bool	swapped;

	if (hpat(*h, offset) == 3)
	{
		h->root[2 * offset + 1] = (t_rel_dist *)gc_calloc(dyn, 1,
				sizeof(t_rel_dist));
		if (h->root[2 * offset + 1] == NULL)
			return (-1);
		*h->root[2 * offset + 1] = dist;
		if (absf_(absol_dist(*h->root[offset])) > absf_(absol_dist(dist)))
		{
			swapped = hswap(h, offset, 1 + 2 * offset, offset);
			if (!swapped)
				return (-1);
		}
		h->len = 2 * offset + 2;
		return ((ssize_t)h->cap);
	}
	return (insert4(dyn, h, dist, offset));
}

void	extract2(t_min_heap *h, size_t offset)
{
	if (h->root[1 + 2 * offset] <= h->root[2 + 2 * offset])
	{
		h->root[offset] = h->root[1 + 2 * offset];
		extract(h, 1 + 2 * offset);
	}
	else
	{
		h->root[offset] = h->root[2 + 2 * offset];
		extract(h, 2 + 2 * offset);
	}
}
