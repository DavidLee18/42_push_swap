/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:46:02 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/22 21:41:43 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dyn, t_vec *vec, int value)
{
	if (vec->len == vec->cap)
		vecalloc(dyn, vec);
	vec->ptr[vec->top++] = value;
	vec->len++;
}

int	*pop(t_list **dyn, t_vec *vec)
{
	int	*res;

	if (vec->len == 0 || !vec->ptr)
		return (NULL);
	res = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (!res)
		return (NULL);
	vec->top = wrapping_sub(vec->top, 1, vec->len);
	*res = vec->ptr[vec->top];
	vec->ptr[vec->top] = 0;
	vec->len--;
	return (res);
}

void	rotate(t_vec *vec, int n)
{
	if (n == 0 || vec->len <= 1)
		return ;
	else if (n > 0)
	{
		vec->top = wrapping_sub(vec->top, n, vec->len);
		vec->bottom = wrapping_sub(vec->bottom, n, vec->len);
	}
	else
	{
		vec->top = wrapping_add(vec->top, -n, vec->len);
		vec->bottom = wrapping_add(vec->bottom, -n, vec->len);
	}
}

void	swap(t_vec *vec)
{
	int		temp;
	size_t	i;
	size_t	j;

	if (vec->len <= 1)
		return ;
	i = wrapping_sub(vec->top, 1, vec->len);
	j = wrapping_sub(i, 1, vec->len);
	temp = vec->ptr[i];
	vec->ptr[i] = vec->ptr[j];
	vec->ptr[j] = temp;
}

void	vec_init(t_vec *vec)
{
	vec->ptr = NULL;
	vec->bottom = 0;
	vec->cap = 0;
	vec->len = 0;
	vec->top = 0;
}
