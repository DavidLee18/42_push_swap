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

_Bool	radix_nth(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
	return (1);
}

_Bool	radix_nth_2(t_list **dyn, t_stack_pair *idxs, const size_t n)
{
	int	*temp;

	temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
	while (temp != NULL)
	{
		push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
	}
	return (1);
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
	while (n <= max_digits)
	{
		cmd_radix_nth(dyn, ss, n);
		cmd_radix_nth_2(dyn, ss, n);
		n++;
	}
	if (max_digits % 2 == 0)
		cmd_pa_all(dyn, ss);
}

void	cmd_brute_3(const t_stack_pair *ss)
{
	if (ss->a.len != 3)
		return ;
	if (ss->a.ptr[0] == 2 && ss->a.ptr[1] == 3 && ss->a.ptr[2] == 1)
		ft_printf("sa\nra\n");
	else if (ss->a.ptr[0] == 3 && ss->a.ptr[1] == 1 && ss->a.ptr[2] == 2)
		ft_printf("sa\n");
	else if (ss->a.ptr[0] == 1 && ss->a.ptr[1] == 3 && ss->a.ptr[2] == 2)
		ft_printf("rra\n");
	else if (ss->a.ptr[0] == 2 && ss->a.ptr[1] == 1 && ss->a.ptr[2] == 3)
		ft_printf("ra\n");
	else if (ss->a.ptr[0] == 1 && ss->a.ptr[1] == 2 && ss->a.ptr[2] == 3)
		ft_printf("sa\nrra\n");
}