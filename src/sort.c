/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/24 00:52:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_radix_nth(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t			i;
	int				*temp;
	const char		*papb = "pa\npb\n";
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return ;
		if (((0b11 << (n * 2)) & *temp) == 0)
		{
			push_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
			write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
		}
		else
			cmd_radix_nth_123(dyn, idxs, n, *temp);
	}
}

void	cmd_radix_nth_123(t_list **dyn, t_stack_pair *idxs, size_t n, int head)
{
	const char	*pr = "pb\nrb\npa\nra\n";
	const char	*rarb = "ra\nrb\n";

	if (((0b11 << (n * 2)) & head) == 1)
	{
		push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
				+ (n % 2 == 1) * (size_t)(&idxs->a)), head);
		write(STDOUT_FILENO, pr + 6 * (n % 2 == 1), 6);
	}
	else
	{
		push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
				+ (n % 2 == 1) * (size_t)(&idxs->b)), head);
		write(STDOUT_FILENO, rarb + 3 * (n % 2 == 1), 3);
	}
}

void	cmd_radix_nth_2(t_list **dyn, t_stack_pair *idxs, size_t n)
{
	size_t			i;
	int				*temp;
	const char		*papb = "pa\npb\n";
	const size_t	len = (n % 2 == 0) * idxs->a.len + (n % 2 == 1)
		* idxs->b.len;

	i = 0;
	while (++i <= len)
	{
		temp = pop_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->a)
					+ (n % 2 == 1) * (size_t)(&idxs->b)));
		if (temp == NULL)
			return ;
		if (((0b11 << (n * 2)) & *temp) == 2)
		{
			push_back(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
					+ (n % 2 == 1) * (size_t)(&idxs->a)), *temp);
			write(STDOUT_FILENO, papb + (n % 2 == 0) * 3, 3);
		}
		else
			cmd_radix_nth_3(dyn, idxs, n, *temp);
	}
}

void	cmd_radix_nth_3(t_list **dyn, t_stack_pair *idxs, size_t n, int head)
{
	const char	*pr = "pb\nrb\npa\nra\n";

	push_front(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
			+ (n % 2 == 1) * (size_t)(&idxs->a)), head);
	write(STDOUT_FILENO, pr + 6 * (n % 2 == 1), 6);
}

void	cmd_pa_all(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop_back(dyn, &ss->b);
	while (val != NULL)
	{
		push_back(dyn, &ss->a, *val);
		ft_printf("pa\n");
		val = pop_back(dyn, &ss->b);
	}
}
