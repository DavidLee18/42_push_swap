/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_radix3_nth_0(t_list **dyn, t_stack_pair *idxs, const size_t n)
{
	size_t			i;
	int				*temp;
	const char		*papb = "pa\npb\n";
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
		if (temp == NULL)
			return ;
		if (nth3_digit(*temp, n) == 0)
		{
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
			write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
		}
		else
			cmd_radix3_nth_1(dyn, idxs, n, *temp);
	}
	cmd_radix3_nth_2(dyn, idxs, n);
}

void	cmd_radix3_nth_1(t_list **dyn, t_stack_pair *idxs, const size_t n,
			const int head)
{
	const char	*pr = "pb\nrb\npa\nra\n";
	const char	*rarb = "ra\nrb\n";

	if (nth3_digit(head, n) == 1)
	{
		push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), head);
		write(STDOUT_FILENO, pr + 6 * (n % 2 == 1), 6);
	}
	else
	{
		push_front(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b), head);
		write(STDOUT_FILENO, rarb + 3 * (n % 2 == 1), 3);
	}
}

void	cmd_radix3_nth_2(t_list **dyn, t_stack_pair *idxs, const size_t n)
{
	size_t			i;
	int				*temp;
	const char		*papb = "pa\npb\n";
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b));
		if (temp == NULL)
			return ;
		push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
	}
}

void	cmd_pa_all(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop_back(dyn, &ss->b);
	while (val != NULL)
	{
		push_back(dyn, &ss->a, *val);
		ft_fprintf(STDOUT_FILENO, "pa\n");
		val = pop_back(dyn, &ss->b);
	}
}

void	cmd_brute(t_list **dyn, t_vec *a)
{
	if (a->len == 2)
		ft_fprintf(STDOUT_FILENO, "sa\n");
	else if (a->len == 3)
		cmd_brute_3(a);
	else if (a->len == 4)
		cmd_brute_4(a);
	else if (a->len == 5)
		cmd_brute_5(vecrev(dyn, a));
}
