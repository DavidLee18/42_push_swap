/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:40:10 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/23 15:10:51 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

_Bool	has_dup(const t_vec v)
{
	size_t	i;
	size_t	temp;

	temp = 0;
	while (temp < v.len)
	{
		i = 0;
		while (i < v.len)
		{
			if (i != temp && v.ptr[i] == v.ptr[temp])
				return (1);
			i++;
		}
		temp++;
	}
	return (0);
}

void	print_vec(const t_vec v)
{
	size_t	i;

	ft_printf("vec[");
	if (v.len > 0)
	{
		i = v.len;
		ft_printf("%d", v.ptr[i - 1]);
		while (i > 0)
		{
			i--;
			if (i <= 0)
				break ;
			ft_printf(", %d", v.ptr[i - 1]);
		}
	}
	ft_printf("]\n");
}
