/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:40:10 by jaehylee          #+#    #+#             */
/*   Updated: 2024/11/26 05:49:52 by jaehylee         ###   ########.fr       */
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

void	vecalloc(t_vec *vec)
{
	if (vec->cap == 0)
		vec->ptr = (int *)ft_calloc(1, sizeof(int));
	else
		vec->ptr = (int *)ft_realloc(&vec->ptr, vec->cap * sizeof(int),
				vec->cap * 2 * sizeof(int));
	if (!vec->ptr)
		return ;
	if (vec->cap == 0)
		vec->cap == 1;
	else
		vec->cap *= 2;
}
