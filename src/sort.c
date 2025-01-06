/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/06 07:38:37 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyze_stack(t_list **dyn, t_vec v, t_min_heap *h)
{
	size_t	i;
	ssize_t	j;
	_Bool	not_first;

	if (h == NULL)
		return ;
	i = wrapping_sub(v.top, 1, v.len);
	not_first = 1;
	while (i != wrapping_sub(v.top, 1, v.len) || not_first)
	{
		if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len)])
		{
			j = insert(dyn, h, measure_dist(v, i));
			if (j < 0)
				return ;
			h->cap = (size_t)j;
			print_heap(*h);
		}
		i = wrapping_sub(i, 1, v.len);
		not_first = 0;
	}
}

void	print_cmds(t_vec *v, t_min_heap *h)
{
	t_rel_dist	*j;
	size_t		i;

	j = extract(h);
	while (j != NULL)
	{
		cmd_rot_swap(v, j->dist);
		i = 0;
		while (i + h->offset < h->cap)
		{
			if (h->root[i + h->offset] != NULL)
			{
				h->root[i + h->offset]->dist -= j->dist;
			}
			i++;
		}
		j = extract(h);
	}
}

t_rel_dist	measure_dist(t_vec v, size_t i)
{
	ssize_t	res1;
	ssize_t	res2;
	size_t	j;
	size_t	weight;

	j = i;
	res1 = 0;
	while (j != wrapping_sub(v.top, 1, v.len))
	{
		j = wrapping_add(j, 1, v.len);
		res1++;
	}
	j = i;
	res2 = 0;
	while (j != wrapping_sub(v.top, 1, v.len))
	{
		j = wrapping_sub(j, 1, v.len);
		res2--;
	}
	weight = abs_isize(v.ptr[i] - v.ptr[wrapping_sub(i, 1, v.len)]);
	if (abs_isize(res1) <= abs_isize(res2))
		return ((t_rel_dist){res1, weight});
	return ((t_rel_dist){res2, weight});
}

double	absol_dist(t_rel_dist dist)
{
	return ((double)dist.dist / (double)dist.weight);
}

void	cmd_rotate(t_vec *v, size_t offset)
{
	ssize_t	min_offset;

	if (offset >= v->len)
		min_offset = (ssize_t)offset % (ssize_t)v->len;
	else
		min_offset = (ssize_t)offset;
	if (min_offset > (ssize_t)v->len / 2)
		min_offset -= (ssize_t)v->len;
	while (min_offset != 0)
	{
		rotate(v, (min_offset > 0) * 2 - 1);
		if (min_offset < 0)
			ft_printf("r");
		ft_printf("ra\n");
		min_offset -= (min_offset > 0) + (min_offset < 0) * (-1);
	}
}
