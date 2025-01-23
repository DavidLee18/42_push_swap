/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:37 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/23 16:54:32 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vec	*_1ota_rev(t_list **dyn, size_t i)
{
	t_vec	*res;
	size_t	j;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	j = i;
	while (j > 0)
	{
		push_back(dyn, res, j);
		j--;
	}
	return (res);
}

t_vec	*veccpy(t_list **dyn, t_vec v)
{
	t_vec	*res;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	res->ptr = (int *)gc_calloc(dyn, v.cap, sizeof(int));
	ft_memmove_(res->ptr, v.ptr, v.len * sizeof(int));
	res->cap = v.cap;
	res->len = v.len;
	return (res);
}

_Bool	velem(int i, t_vec v)
{
	size_t	j;

	j = 0;
	while (j < v.len)
	{
		if (v.ptr[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int	*vecmax(t_list **dyn, t_vec v)
{
	size_t	j;
	int		*i;

	j = 0;
	i = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (i == NULL || v.len == 0)
		return (NULL);
	*i = v.ptr[j];
	while (j < v.len && v.len != 1)
	{
		if (v.ptr[j] > *i)
			*i = v.ptr[j];
		j++;
	}
	return (i);
}

int	veccmp(t_vec v1, t_vec v2)
{
	size_t	i;

	i = 0;
	while (i < v1.len && i < v2.len)
	{
		if (v1.ptr[i] != v2.ptr[i])
			return (v1.ptr[i] - v2.ptr[i]);
		i++;
	}
	if (v1.len > v2.len)
		return (1);
	else if (v2.len > v1.len)
		return (-1);
	return (0);
}
