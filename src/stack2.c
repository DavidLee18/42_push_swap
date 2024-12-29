/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:40:10 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 15:32:30 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	wrapping_add(size_t lhs, size_t rhs, size_t max)
{
	return ((lhs + rhs) % max);
}

size_t	wrapping_sub(size_t n, size_t rhs, size_t max)
{
	ssize_t	res;

	res = (ssize_t)n - (ssize_t)rhs;
	while (res < 0)
		res += max;
	return ((size_t)res);
}

void	vecalloc(t_list **dyn, t_vec *vec)
{
	if (vec->cap == 0)
		vec->ptr = (int *)gc_calloc(dyn, 1, sizeof(int));
	else
		gc_realloc(dyn, (void **)&(vec->ptr), vec->cap
			* sizeof(int), vec->cap * 2 * sizeof(int));
	if (!vec->ptr)
		return ;
	if (vec->cap == 0)
		vec->cap = 1;
	else
		vec->cap *= 2;
}

_Bool	has_dup(t_vec v)
{
	size_t	i;
	size_t	temp;

	temp = 0;
	while (temp < v.len)
	{
		i = 0;
		while (i < v.len)
		{
			if (i != temp && v.ptr[i] != 0 && v.ptr[i] == v.ptr[temp])
				return (1);
			i++;
		}
		temp++;
	}
	return (0);
}

void	print_vec(t_vec v)
{
	size_t	i;

	i = 0;
	ft_printf("vec[");
	while (i < v.len)
	{
		ft_printf("%d", v.ptr[i]);
		if (i != v.len - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}
