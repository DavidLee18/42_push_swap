/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:58:20 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/06 14:28:04 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	insert4(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	ssize_t		succeeded;

	if (absf_(absol_dist(dist)) < absf_(absol_dist(*h->root[offset]))
		&& max_balanced_depth(*h, 1 + 2 * offset)
		<= max_balanced_depth(*h, 2 + 2 * offset))
	{
		succeeded = insert(dyn, h, *h->root[offset], 1 + 2 * offset);
		if (succeeded < 0)
			return (-1);
		h->cap = (size_t)succeeded;
		*h->root[offset] = dist;
	}
	else
		return (insert5(dyn, h, dist, offset));
	return ((ssize_t)h->cap);
}

ssize_t	insert5(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	ssize_t		succeeded;

	if (absf_(absol_dist(dist)) < absf_(absol_dist(*h->root[offset])))
	{
		succeeded = insert(dyn, h, *h->root[offset], 2 + 2 * offset);
		if (succeeded < 0)
			return (-1);
		h->cap = (size_t)succeeded;
		*h->root[offset] = dist;
		return ((ssize_t)h->cap);
	}
	return (insert6(dyn, h, dist, offset));
}

ssize_t	insert6(t_list **dyn, t_min_heap *h, t_rel_dist dist, size_t offset)
{
	ssize_t		new_cap;

	if (absf_(absol_dist(dist)) >= absf_(absol_dist(*h->root[offset]))
		&& max_balanced_depth(*h, 1 + 2 * offset)
		<= max_balanced_depth(*h, 2 + 2 * offset))
	{
		new_cap = insert(dyn, h, dist, 1 + 2 * offset);
		if (new_cap < 0)
			return (-1);
		h->cap = new_cap;
	}
	else if (absf_(absol_dist(dist)) >= absf_(absol_dist(*h->root[offset])))
	{
		new_cap = insert(dyn, h, dist, 2 + 2 * offset);
		if (new_cap < 0)
			return (-1);
		h->cap = new_cap;
	}
	return ((ssize_t)h->cap);
}

_Bool	clear_heap(t_list **dyn, t_min_heap *h)
{
	h->root = (t_rel_dist **) gc_calloc(dyn, 1, sizeof(t_rel_dist *));
	if (h->root == NULL)
		return (0);
	h->cap = 1;
	h->len = 0;
	return (1);
}

void	print_rel_dist(t_rel_dist dist)
{
	ft_printf("t_rel_dist { dist: %d, weight: %u }", *((int *)&dist.dist),
		*((unsigned int *)&dist.weight));
}
