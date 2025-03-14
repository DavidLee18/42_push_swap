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

_Bool	radix3_nth_01(t_list **dyn, t_stack_pair *idxs, const size_t n)
{
	size_t			i;
	int				*temp;
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
		if (temp == NULL)
			return (0);
		if (nth3_digit(*temp, n) == 0)
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a),
				*temp);
		else if (nth3_digit(*temp, n) == 1)
			push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		else
			push_front(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b), *temp);
	}
	return (radix3_nth_2(dyn, idxs, n), 1);
}

void	radix3_nth_2(t_list **dyn, t_stack_pair *idxs, const size_t n)
{
	int	*temp;

	temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
	while (temp != NULL)
	{
		push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
	}
}

t_vec	*remap_idx(t_list **dyn, const t_vec idxs, const t_vec sorted_idxs)
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
	const int	*max = vecmax(dyn, ss->a);
	size_t		n;
	size_t		max_digits;

	if (max == NULL)
		return ;
	n = 0;
	max_digits = (size_t)ft_ulog(3, *max);
	while (++n < max_digits)
		cmd_radix3_nth_0(dyn, ss, n - 1);
	if ((size_t)*max > upow(3, max_digits) && (size_t)*max < 4 * upow(3, max_digits - 1))
		cmd_radix43_nth_0(dyn, ss, max_digits - 1);
	else
	{
		cmd_radix3_nth_0(dyn, ss, max_digits - 1);
		cmd_radix3_nth_0(dyn, ss, max_digits);
	}
	if (ss->b.len != 0)
		cmd_pa_all(dyn, ss);
}

void	cmd_brute_3(const t_vec *a)
{
	if (a->len != 3)
		return ;
	if (a->ptr[0] == 2 && a->ptr[1] == 3 && a->ptr[2] == 1)
		ft_printf("sa\nra\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 1 && a->ptr[2] == 2)
		ft_printf("sa\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 3 && a->ptr[2] == 2)
		ft_printf("rra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 1 && a->ptr[2] == 3)
		ft_printf("ra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 2 && a->ptr[2] == 3)
		ft_printf("sa\nrra\n");
}