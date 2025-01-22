/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:28:25 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/22 12:22:44 by jaehylee         ###   ########.fr       */
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
	ha = pop(dyn, &a);
	hb = pop(dyn, &b);
	if (*ha <= *hb)
	{
		push(dyn, &b, *hb);
		res = merge(dyn, a, b);
		push(dyn, res, *ha);
		return (res);
	}
	push(dyn, &b, *ha);
	res = merge(dyn, a, b);
	push(dyn, res, *hb);
	return (res);
}

t_vec	*pure(t_vec *v, t_vec val)
{
	if (v == NULL)
		return (NULL);
	*v = val;
	return (v);
}

_Bool	radix(t_list **dyn, t_vec *v)
{
	t_stack_pair	*tmps;
	size_t			n;
	int				*max;

	if (v == NULL)
		return (0);
	tmps = (t_stack_pair *)gc_calloc(dyn, 1, sizeof(t_stack_pair));
	if (tmps == NULL)
		return (0);
	tmps->a = *v;
	max = vecmax(dyn, *v);
	if (max == NULL)
		return (0);
	n = 0;
	while (n <= (size_t)ft_ulog(4, *max))
	{
		if (!radix_nth(dyn, tmps, n) || !radix_nth_23(dyn, tmps, n))
			return (0);
		n++;
	}
	return (1);
}
