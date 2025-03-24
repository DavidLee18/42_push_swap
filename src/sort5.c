/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 15:02:45 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix43_nth_23(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
		if (nth43_digit(*temp, n) == 2)
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a),
				*temp);
		else
			push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
	}
}

void	cmd_radix43_nth_0(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
		if (nth43_digit(*temp, n) == 0)
		{
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
			write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
		}
		else
			cmd_radix43_nth_1(dyn, idxs, n, *temp);
	}
	cmd_radix43_nth_2(dyn, idxs, n);
}

void	cmd_radix43_nth_1(t_list **dyn, t_stack_pair *idxs, const size_t n,
			const int head)
{
	const char	*pr = "pb\nrb\npa\nra\n";
	const char	*rarb = "ra\nrb\n";

	if (nth43_digit(head, n) == 1)
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

void	cmd_radix43_nth_2(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
		if (nth43_digit(*temp, n) == 2)
		{
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
			write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
		}
		else
			cmd_radix43_nth_3(dyn, idxs, n, *temp);
	}
}

void	cmd_radix43_nth_3(t_list **dyn, t_stack_pair *idxs, const size_t n,
			const int head)
{
	const char	*pr = "pb\nrb\npa\nra\n";

	push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), head);
	write(STDOUT_FILENO, pr + 6 * (n % 2 == 1), 6);
}
