/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:46:02 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/23 15:15:46 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list **dyn, t_vec *vec, int value)
{
	if (vec->len == vec->cap)
		vecalloc(dyn, vec);
	vec->ptr[vec->len++] = value;
}

void	push_front(t_list **dyn, t_vec *vec, int value)
{
	int	*newp;
	int	*temp;

	if (vec->len == vec->cap)
	{
		if (vec->cap == 0)
		{
			push_back(dyn, vec, value);
			return ;
		}
		newp = (int *)gc_calloc(dyn, 2 * vec->cap, sizeof(int));
		vec->cap *= 2;
	}
	else
		newp = (int *)gc_calloc(dyn, vec->cap, sizeof(int));
	temp = newp + 1;
	ft_memmove_(temp, vec->ptr, sizeof(int) * (vec->len++));
	*newp = value;
	vec->ptr = newp;
}

int	*pop_back(t_list **dyn, t_vec *vec)
{
	int	*res;

	if (vec->len == 0 || !vec->ptr)
		return (NULL);
	res = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (!res)
		return (NULL);
	*res = vec->ptr[--vec->len];
	return (res);
}
