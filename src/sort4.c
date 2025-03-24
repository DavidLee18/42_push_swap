/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_all(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop_back(dyn, &ss->b);
	while (val != NULL)
	{
		push_back(dyn, &ss->a, *val);
		val = pop_back(dyn, &ss->b);
	}
}

void	cmd_brute_4(const t_vec *a)
{
	if (a->len != 4)
		return ;
	if (a->ptr[0] == 3 && a->ptr[1] == 4 && a->ptr[2] == 2 && a->ptr[3] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nra\nra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 2 && a->ptr[2] == 3
		&& a->ptr[3] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 4 && a->ptr[2] == 3
		&& a->ptr[3] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 2 && a->ptr[2] == 4
		&& a->ptr[3] == 1)
		ft_fprintf(STDOUT_FILENO, "sa\nra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 3 && a->ptr[2] == 4
		&& a->ptr[3] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 3 && a->ptr[2] == 1
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "sa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 4 && a->ptr[2] == 1
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "pb\nra\nsa\npa\nrra\n");
	else
		cmd_brute_4_1(a);
}

void	cmd_brute_5(const t_vec *a)
{
	if (a->len != 5)
		return ;
	if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nra\npb\npb\nra\npa\npa\nra\nra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\npb\nrra\nrra\nsa\npa\nrra\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\nra\nsa\nra\nra\n");
	else
		cmd_brute_5_1(a);
}

void	radix_opt(t_list **dyn, t_stack_pair *idxs, const size_t max)
{
	size_t	n;
	size_t	digits;

	n = 0;
	digits = ft_ulog(3, max);
	while (++n < digits)
		radix3_nth_01(dyn, idxs, n - 1);
	if (max > upow(3, digits) && max < 4 * upow(3, digits - 1))
		radix43_nth_01(dyn, idxs, digits - 1);
	else
	{
		radix3_nth_01(dyn, idxs, digits - 1);
		radix3_nth_01(dyn, idxs, digits);
	}
	if (idxs->b.len != 0)
		pa_all(dyn, idxs);
}

void	radix43_nth_01(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
			return ;
		if (nth43_digit(*temp, n) == 0)
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a),
				*temp);
		else if (nth43_digit(*temp, n) == 1)
			push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		else
			push_front(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b), *temp);
	}
	radix43_nth_23(dyn, idxs, n);
}
