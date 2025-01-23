/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:42:48 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/22 22:31:58 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	radix_nth(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t	i;
	size_t	len;
	int		*temp;
	int		rem;

	i = 0;
	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1) * idxs->b.len;
	while (++i <= len)
	{
		temp = pop(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return (0);
		rem = (0b11 << n) & *temp;
		if (rem == 0)
			push(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
		else
			radix_nth_123(dyn, idxs, n, *temp);
	}
	return (1);
}

void	radix_nth_123(t_list **dyn, t_stack_pair *idxs, size_t n, int head)
{
	int	rem;

	rem = (0b11 << n) & head;
	if (rem == 1)
	{
		push(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
				+ (n % 2 == 1) * (size_t)(&idxs->a)), head);
		rotate((t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
				+ (n % 2 == 1) * (size_t)(&idxs->a)), 1);
	}
	else
	{
		push(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
				+ (n % 2 == 1) * (size_t)(&idxs->b)), head);
		rotate((t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
				+ (n % 2 == 1) * (size_t)(&idxs->b)), 1);
	}
}

_Bool	radix_nth_23(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t	i;
	size_t	len;
	int		*temp;
	int		rem;

	i = 0;
	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1) * idxs->b.len;
	while (++i <= len)
	{
		temp = pop(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return (0);
		rem = (0b11 << n) & *temp;
		if (rem == 2)
			push(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
		else
			radix_nth_3(dyn, idxs, n, *temp);
	}
	return (1);
}

t_vec	*remap_idx(t_list **dyn, t_vec idxs, t_vec sorted_idxs)
{
	t_vec	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	res = veccpy(dyn, idxs);
	if (res == NULL)
		return (NULL);
	i = wrapping_sub(sorted_idxs.top, 1, sorted_idxs.len);
	k = 0;
	while (i != sorted_idxs.bottom && ++k <= res->len)
	{
		j = wrapping_sub(idxs.top, 1, idxs.len);
		while (j != idxs.bottom && j != wrapping_sub(j, 1, idxs.len))
		{
			if (sorted_idxs.ptr[i] == idxs.ptr[j])
				res->ptr[j] = k;
			j = wrapping_sub(j, 1, idxs.len);
		}
		i = wrapping_sub(i, 1, sorted_idxs.len);
	}
	return (res);
}

// void	cmd_radix(t_list **dyn, t_stack_pair *ss);
