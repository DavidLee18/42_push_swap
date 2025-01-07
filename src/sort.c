/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/08 06:19:16 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_all(t_list **dyn, t_vec v, t_min_heap *h)
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
		j = insert(dyn, h, measure_dist(v, i), 0);
		if (j < 0)
			return ;
		h->cap = (size_t)j;
		i = wrapping_sub(i, 1, v.len);
		not_first = 0;
	}
}

void	cmd_rot_pb(t_list **dyn, t_stack_pair *ss, t_min_heap *h)
{
	t_rel_dist	*j;
	int			i;
	int			*v;

	j = extract(h, 0);
	v = NULL;
	while (j != NULL)
	{
		print_rel_dist(*j);
		cmd_rotate(&ss->a, j->dist);
		v = pop(dyn, &ss->a);
		if (v == NULL || *v != j->value)
		{
			ft_printf("%p %d\n", v, *v);
			return ;
		}
		push(dyn, &ss->b, j->value);
		ft_printf("pb\n");
		i = -1;
		print_heap(*h, 0);
		while ((size_t)++i < h->cap)
			if (h->root[i] != NULL)
				h->root[i]->dist -= j->dist + (j->dist < 0) - (j->dist > 0);
		j = extract(h, 0);
	}
}

t_rel_dist	measure_dist(t_vec v, size_t i)
{
	ssize_t	res1;
	ssize_t	res2;
	size_t	j;

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
	if (abs_isize(res1) <= abs_isize(res2))
		return ((t_rel_dist){.dist = res1, .value = v.ptr[i]});
	return ((t_rel_dist){.dist = res2, .value = v.ptr[i]});
}

// double	absol_dist(t_rel_dist dist)
// {
// 	return (1.0 / (double)dist.value);
// }

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
