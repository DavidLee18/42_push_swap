/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:37 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/21 21:24:34 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vec	*iota(t_list **dyn, size_t i)
{
	t_vec	*res;
	size_t	j;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		push(dyn, res, j);
		j++;
	}
	return (res);
}

t_vec	*veccpy(t_list **dyn, t_vec v)
{
	t_vec	*res;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	*res = v;
	return (res);
}

_Bool	velem(int i, t_vec v)
{
	size_t	j;

	j = wrapping_sub(v.top, 1, v.len);
	while (j != v.top)
	{
		if (v.ptr[j] == i)
			return (1);
		j = wrapping_sub(j, 1, v.len);
	}
	return (0);
}

int	*vecmax(t_list **dyn, t_vec v)
{
	size_t	j;
	int		*i;

	j = wrapping_sub(v.top, 1, v.len);
	i = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (i == NULL)
		return (NULL);
	*i = v.ptr[j];
	while (j != v.top)
	{
		if (v.ptr[j] > *i)
			*i = v.ptr[j];
		j = wrapping_sub(j, 1, v.len);
	}
	return (i);
}
