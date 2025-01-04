/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:58:20 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/03 04:58:32 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	insert4(t_list **dyn, t_min_heap *h, t_rel_dist dist)
{
	t_min_heap	l;
	t_min_heap	r;
	ssize_t		succeeded;

	l = (t_min_heap){.root = h->root, .cap = h->cap, .len = h->len - h->offset
		- 1, .offset = h->offset * 2 + 1};
	r = (t_min_heap){.root = h->root, .cap = h->cap, .len = h->len - h->offset
		- 2, .offset = h->offset * 2 + 2};
	if (abs_isize(absol_dist(dist)) < abs_isize(absol_dist(*h->root[h->offset])) && max_balanced_depth(l)
		<= max_balanced_depth(r))
	{
		succeeded = insert(dyn, &l, *h->root[h->offset]);
		if (succeeded < 0)
			return (-1);
		h->cap = (size_t)succeeded;
		*h->root[h->offset] = dist;
	}
	else
		return (insert5(dyn, h, dist));
	return ((ssize_t)h->cap);
}

ssize_t	insert5(t_list **dyn, t_min_heap *h, t_rel_dist dist)
{
	t_min_heap	r;
	ssize_t		succeeded;

	r = (t_min_heap){.root = h->root, .cap = h->cap, .len = h->len - h->offset
		- 2, .offset = h->offset * 2 + 2};
	if (abs_isize(absol_dist(dist)) < abs_isize(absol_dist(*h->root[h->offset])))
	{
		succeeded = insert(dyn, &r, *h->root[h->offset]);
		if (succeeded < 0)
			return (-1);
		h->cap = (size_t)succeeded;
		*h->root[h->offset] = dist;
		return ((ssize_t)h->cap);
	}
	return (insert6(dyn, h, dist));
}

ssize_t	insert6(t_list **dyn, t_min_heap *h, t_rel_dist dist)
{
	t_min_heap	l;
	t_min_heap	r;
	ssize_t		new_cap;

	l = (t_min_heap){.root = h->root, .cap = h->cap, .len = h->len - h->offset
		- 1, .offset = h->offset * 2 + 1};
	r = (t_min_heap){.root = h->root, .cap = h->cap, .len = h->len - h->offset
		- 2, .offset = h->offset * 2 + 2};
	if (abs_isize(absol_dist(dist)) >= abs_isize(absol_dist(*h->root[h->offset])) && max_balanced_depth(l)
		<= max_balanced_depth(r))
	{
		new_cap = insert(dyn, &l, dist);
		if (new_cap < 0)
			return (-1);
		h->cap = new_cap;
	}
	else if (abs_isize(absol_dist(dist)) >= abs_isize(absol_dist(*h->root[h->offset])))
	{
		new_cap = insert(dyn, &r, dist);
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
	h->offset = 0;
	return (1);
}

void	print_rel_dist(t_rel_dist dist)
{
	ft_printf("t_rel_dist { dist: %d, weight: %u }", *((int *)&dist.dist), *((unsigned int *)&dist.weight));
}