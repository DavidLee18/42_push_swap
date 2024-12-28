/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/28 09:01:33 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyze_stack(t_vec v, t_min_heap *h)
{
	size_t	i;

	if (h == NULL)
		return ;
	i = v.top;
	if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len - 1)])
		h->cap = insert(h, measure_dist(v, i));
	i = wrapping_sub(i, 1, v.len - 1);
	while (i != v.top)
	{
		if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len - 1)])
			h->cap = insert(h, measure_dist(v, i));
		i = wrapping_sub(i, 1, v.len - 1);
	}
}

void	print_cmds(t_vec *v, t_min_heap *h)
{
	ssize_t	j;

	if (h == NULL || hpat(*h) == 0 || hcomplete(*h) || v->len == 0)
		return ;
	j = extract(h);
	while (j > 0)
	{
		rotate(v, 1);
		ft_printf("ra\n");
		j--;
	}
	while (j < 0)
	{
		rotate(v, -1);
		ft_printf("rra\n");
		j++;
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
	while (j != v.top)
	{
		j = wrapping_add(j, 1, v.len - 1);
		res1++;
	}
	j = i;
	res2 = 0;
	while (j != v.top)
	{
		j = wrapping_sub(j, 1, v.len - 1);
		res2--;
	}
	if (abs_isize(res1) <= abs_isize(res2))
		return (res1);
	return (res2);
}
