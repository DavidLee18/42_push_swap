//
// Created by 이재현 on 2025-03-15.
//

#include "push_swap.h"
#include "push_swap_bonus.h"

_Bool	exec_cmd2(t_list **dyn, t_stack_pair *ss, char *cmd)
{
	if (ft_strcmp(cmd, "rb") == 0)
		return (exec_rb(dyn, ss));
	if (ft_strcmp(cmd, "rr") == 0)
		return (exec_ra(dyn, ss) && exec_rb(dyn, ss));
	if (ft_strcmp(cmd, "rra") == 0)
		return (exec_rra(dyn, ss));
	if (ft_strcmp(cmd, "rrb") == 0)
		return (exec_rrb(dyn, ss));
	if (ft_strcmp(cmd, "rrr") == 0)
		return (exec_rra(dyn, ss) && exec_rrb(dyn, ss));
	return (0);
}

_Bool	exec_pa(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->b);
	if (temp == NULL)
		return (0);
	push_back(dyn, &ss->a, *temp);
	return (1);
}

_Bool	exec_pb(t_list **dyn, t_stack_pair *ss)
{
	int	*temp;

	temp = pop_back(dyn, &ss->a);
	if (temp == NULL)
		return (0);
	push_back(dyn, &ss->b, *temp);
	return (1);
}

_Bool	exec_sa(t_stack_pair *ss)
{
	int	temp;

	if (ss->a.len < 2)
		return (0);
	temp = ss->a.ptr[ss->a.len - 1];
	ss->a.ptr[ss->a.len - 1] = ss->a.ptr[ss->a.len - 2];
	ss->a.ptr[ss->a.len - 2] = temp;
	return (1);
}

_Bool	exec_sb(t_stack_pair *ss)
{
	int	temp;

	if (ss->b.len < 2)
		return (0);
	temp = ss->b.ptr[ss->b.len - 1];
	ss->b.ptr[ss->b.len - 1] = ss->b.ptr[ss->b.len - 2];
	ss->b.ptr[ss->b.len - 2] = temp;
	return (1);
}