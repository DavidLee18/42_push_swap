/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:42:48 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/24 00:52:30 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	radix_nth(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t			i;
	int				*temp;
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return (0);
		if (((0b11 << (n * 2)) & *temp) == 0)
			push_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
		else if (!radix_nth_123(dyn, idxs, n, *temp))
			return (0);
	}
	return (1);
}

_Bool	radix_nth_123(t_list **dyn, t_stack_pair *idxs, size_t n, int head)
{
	if (((0b11 << (n * 2)) & head) == 1)
		push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
				+ (n % 2 == 1) * (size_t)(&idxs->a)), head);
	else
		push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
				+ (n % 2 == 1) * (size_t)(&idxs->b)), head);
	return (1);
}

_Bool	radix_nth_23(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t			i;
	int				*temp;
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return (0);
		if (((0b11 << (n * 2)) & *temp) == 2)
			push_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
		else
			push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
	}
	return (1);
}

t_vec	*remap_idx(t_list **dyn, t_vec idxs, t_vec sorted_idxs)
{
	t_vec	*res;
	size_t	i;
	size_t	j;

	res = veccpy(dyn, idxs);
	if (res == NULL)
		return (NULL);
	i = sorted_idxs.len - 1;
	while (1)
	{
		j = idxs.len - 1;
		while (1)
		{
			if ((size_t)idxs.ptr[j] == sorted_idxs.len - i)
				res->ptr[j] = sorted_idxs.ptr[i];
			if (j-- == 0)
				break ;
		}
		if (i-- == 0)
			break ;
	}
	return (res);
}

void	cmd_radix(t_list **dyn, t_stack_pair *ss)
{
	int		*max;
	size_t	n;
	size_t	max_digits;

	max = vecmax(dyn, ss->a);
	if (max == NULL)
		return ;
	n = 0;
	max_digits = (size_t)ft_ulog(4, *max);
	while (n <= max_digits)
	{
		cmd_radix_nth(dyn, ss, n);
		cmd_radix_nth_2(dyn, ss, n);
		n++;
	}
	if (max_digits % 2 == 0)
		cmd_pa_all(dyn, ss);
}
