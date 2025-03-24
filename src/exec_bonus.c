/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 15:23:37 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

_Bool	exec_cmd2(t_list **dyn, t_stack_pair *ss, char *cmd)
{
	if (ft_strcmp(cmd, "rb") == 0)
		return (exec_rb(dyn, ss), 1);
	if (ft_strcmp(cmd, "rr") == 0)
		return (exec_ra(dyn, ss), exec_rb(dyn, ss), 1);
	if (ft_strcmp(cmd, "rra") == 0)
		return (exec_rra(dyn, ss), 1);
	if (ft_strcmp(cmd, "rrb") == 0)
		return (exec_rrb(dyn, ss), 1);
	if (ft_strcmp(cmd, "rrr") == 0)
		return (exec_rra(dyn, ss), exec_rrb(dyn, ss), 1);
	return (0);
}

void	exec_pa(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->b);
	if (temp == NULL)
		return ;
	push_back(dyn, &ss->a, *temp);
}

void	exec_pb(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->a);
	if (temp == NULL)
		return ;
	push_back(dyn, &ss->b, *temp);
}

void	exec_sa(t_stack_pair *ss)
{
	int	temp;

	if (ss->a.len < 2)
		return ;
	temp = ss->a.ptr[ss->a.len - 1];
	ss->a.ptr[ss->a.len - 1] = ss->a.ptr[ss->a.len - 2];
	ss->a.ptr[ss->a.len - 2] = temp;
}

void	exec_sb(t_stack_pair *ss)
{
	int	temp;

	if (ss->b.len < 2)
		return ;
	temp = ss->b.ptr[ss->b.len - 1];
	ss->b.ptr[ss->b.len - 1] = ss->b.ptr[ss->b.len - 2];
	ss->b.ptr[ss->b.len - 2] = temp;
}
