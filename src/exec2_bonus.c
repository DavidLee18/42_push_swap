/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 16:34:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

_Bool	exec_ra(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->a);
	if (temp == NULL)
		return (0);
	push_front(dyn, &ss->a, *temp);
	return (1);
}

_Bool	exec_rb(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->b);
	if (temp == NULL)
		return (0);
	push_front(dyn, &ss->b, *temp);
	return (1);
}

_Bool	exec_rra(t_list **dyn, t_stack_pair *ss)
{
	size_t	i;

	if (ss->a.len < 2)
		return (0);
	i = 0;
	while (i < ss->a.len - 1)
	{
		if (!exec_ra(dyn, ss))
			return (0);
		i++;
	}
	return (1);
}

_Bool	exec_rrb(t_list **dyn, t_stack_pair *ss)
{
	size_t	i;

	if (ss->b.len < 2)
		return (0);
	i = 0;
	while (i < ss->b.len - 1)
	{
		if (!exec_rb(dyn, ss))
			return (0);
		i++;
	}
	return (1);
}
