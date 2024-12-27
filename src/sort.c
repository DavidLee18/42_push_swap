/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/28 01:35:46 by jaehylee         ###   ########.fr       */
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
		{
			if (i > v.len / 2)
				insert(h, (ssize_t)i - (ssize_t)v.len);
			else
				insert(h, (ssize_t)i);
		}
		i = wrapping_sub(i, 1, v.len - 1);
	}
}

void	print_cmds(t_vec v, t_min_heap *h);
