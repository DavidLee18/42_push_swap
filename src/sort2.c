/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:28:25 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 14:58:42 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vec	*msort(t_list **dyn, const t_vec v)
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

t_vec	*msplit(t_list **dyn, const t_vec v)
{
	t_vec	*xs;
	size_t	i;

	xs = (t_vec *)gc_calloc(dyn, 2, sizeof(t_vec));
	if (xs == NULL)
		return (NULL);
	i = 0;
	while (i < v.len / 2)
		push_back(dyn, xs, v.ptr[i++]);
	while (i < v.len)
		push_back(dyn, xs + 1, v.ptr[i++]);
	return (xs);
}

t_vec	*merge(t_list **dyn, t_vec a, t_vec b)
{
	t_vec	*res;
	int		*ha;
	int		*hb;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	if (a.len == 0)
		return (pure(res, b));
	else if (b.len == 0)
		return (pure(res, a));
	ha = pop_back(dyn, &a);
	hb = pop_back(dyn, &b);
	if (*ha <= *hb)
	{
		push_back(dyn, &b, *hb);
		res = merge(dyn, a, b);
		push_back(dyn, res, *ha);
		return (res);
	}
	push_back(dyn, &a, *ha);
	res = merge(dyn, a, b);
	push_back(dyn, res, *hb);
	return (res);
}

t_vec	*pure(t_vec *v, const t_vec val)
{
	if (v == NULL)
		return (NULL);
	*v = val;
	return (v);
}

void	radix(t_list **dyn, t_vec *v)
{
	t_stack_pair	*tmps;
	const int		*max = vecmax(dyn, *v);

	tmps = (t_stack_pair *)gc_calloc(dyn, 1, sizeof(t_stack_pair));
	if (v == NULL || max == NULL || tmps == NULL)
		return ;
	tmps->a = *v;
	radix_opt(dyn, tmps, *max);
	*v = tmps->a;
}
