/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:25:40 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/12 15:44:45 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rotate(t_vec *v, ssize_t offset)
{
	ssize_t	min_offset;

	if (offset >= (ssize_t)v->len || offset <= (-(ssize_t)v->len))
		min_offset = (ssize_t)offset % (ssize_t)v->len;
	else
		min_offset = (ssize_t)offset;
	if (min_offset > (ssize_t)v->len / 2)
		min_offset -= (ssize_t)v->len;
	else if (min_offset < -((ssize_t)v->len / 2))
		min_offset += (ssize_t)v->len;
	while (min_offset != 0)
	{
		rotate(v, (min_offset > 0) * 2 - 1);
		if (min_offset < 0)
			ft_printf("r");
		ft_printf("ra\n");
		min_offset -= (min_offset > 0) + (min_offset < 0) * (-1);
	}
}

_Bool	cmd_pa(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop(dyn, &ss->b);
	if (val == NULL)
		return (0);
	push(dyn, &ss->a, *val);
	ft_printf("pa\n");
	return (1);
}

_Bool	cmd_pb(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop(dyn, &ss->a);
	if (val == NULL)
		return (0);
	push(dyn, &ss->b, *val);
	ft_printf("pb\n");
	return (1);
}

void	cmd_ra(t_stack_pair *ss)
{
	rotate(&ss->a, 1);
	ft_printf("ra\n");
}

void	cmd_rb(t_stack_pair *ss)
{
	rotate(&ss->b, 1);
	ft_printf("rb\n");
}
