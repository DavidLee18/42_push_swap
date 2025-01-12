/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:28:25 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/12 17:51:48 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vec	*msort(t_list **dyn, t_vec v)
{
	t_vec	*xs;
	t_vec	*a;
	t_vec	*b;

	xs = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (v.len <= 1)
	{
		if (xs == NULL)
			return (NULL);
		*xs = v;
		return (xs);
	}
	xs = msplit(dyn, v);
	if (xs == NULL)
		return (NULL);
	a = msort(dyn, xs[0]);
	b = msort(dyn, xs[1]);
	if (a == NULL || b == NULL)
		return (NULL);
	return (merge(dyn, *a, *b));
}

t_vec	*msplit(t_list **dyn, t_vec v)
{
	t_vec	*xs;
	size_t	i;

	xs = (t_vec *)gc_calloc(dyn, 2, sizeof(t_vec));
	if (xs == NULL)
		return (NULL);
	i = 0;
	while (i < v.len / 2)
		push(dyn, xs, v.ptr[wrapping_add(v.bottom, i++, v.len)]);
	while (i < v.len)
		push(dyn, xs + 1, v.ptr[wrapping_add(v.bottom, i++, v.len)]);
	return (xs);
}

t_vec	*merge(t_list **dyn, t_vec a, t_vec b);
