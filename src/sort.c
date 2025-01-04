/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/03 05:13:35 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyze_stack(t_list **dyn, t_vec v, t_min_heap *h)
{
	size_t	i;
	ssize_t	j;

	if (h == NULL)
		return ;
	i = wrapping_sub(v.top, 1, v.len);
	if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len)])
	{
		j = insert(dyn, h, measure_dist(v, i));
		if (j < 0)
			return ;
		h->cap = (size_t)j;
	}
	i = wrapping_sub(i, 1, v.len);
	while (i != wrapping_sub(v.top, 1, v.len))
	{
		if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len)])
		{
			j = insert(dyn, h, measure_dist(v, i));
			if (j < 0)
				return ;
			h->cap = (size_t)j;
		}
		i = wrapping_sub(i, 1, v.len);
	}
}

void	print_cmds(t_vec *v, t_min_heap *h)
{
	ssize_t	*j;

	if (h == NULL || hpat(*h) == 0 || hcomplete(*h, v->len) || v->len == 0)
		return ;
	j = extract(h);
	if (j == NULL)
		return ;
	while (*j > 0)
	{
		rotate(v, 1);
		ft_printf("ra\n");
		(*j)--;
	}
	while (*j < 0)
	{
		rotate(v, -1);
		ft_printf("rra\n");
		(*j)++;
	}
	swap(v);
	ft_printf("sa\n");
}

ssize_t	measure_dist(t_vec v, size_t i)
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
		return (res1);
	return (res2);
}

void	cmd_rotate(t_vec *v, size_t offset)
{
	ssize_t min_offset;

	if (offset >= v->len)
		min_offset = (ssize_t)offset % (ssize_t)v->len;
	else
		min_offset = (ssize_t)offset;
	if (min_offset > (ssize_t)v->len / 2)
		min_offset -= (ssize_t)v->len;
	while (min_offset > 0)
	{
		rotate(v, 1);
		ft_printf("ra\n");
		min_offset--;
	}
	while (min_offset < 0)
	{
		rotate(v, -1);
		ft_printf("rra\n");
		min_offset++;
	}
}