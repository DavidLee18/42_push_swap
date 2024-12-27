/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/28 07:46:48 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	analyze_stack(t_vec v, t_min_heap *h)
{
	size_t	i;

	if (h == NULL)
		return ;
	i = v.top;
	while (i != v.bottom)
	{
		if (v.ptr[i] > v.ptr[wrapping_sub(i, 1, v.len - 1)])
			h->cap = insert(h, measure_dist(v, i));
		i = wrapping_sub(i, 1, v.len - 1);
	}
}

void	print_cmds(t_vec v, t_min_heap *h);

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
