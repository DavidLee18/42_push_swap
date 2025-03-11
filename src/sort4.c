/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/23 14:12:02 by jaehylee         ###   ########.fr       */
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
		ft_printf("ra\nra\nsa\nra\nra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 2 && a->ptr[2] == 3 && a->ptr[3] == 1)
		ft_printf("ra\nsa\nrra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 4 && a->ptr[2] == 3 && a->ptr[3] == 1)
		ft_printf("rra\nsa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 2 && a->ptr[2] == 4 && a->ptr[3] == 1)
		ft_printf("sa\nra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 3 && a->ptr[2] == 4 && a->ptr[3] == 1)
		ft_printf("ra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 3 && a->ptr[2] == 1 && a->ptr[3] == 2)
		ft_printf("sa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 4 && a->ptr[2] == 1 && a->ptr[3] == 2)
		ft_printf("pb\nra\nsa\npa\nrra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 1 && a->ptr[2] == 3 && a->ptr[3] == 2)
		ft_printf("rra\nrra\nsa\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 4 && a->ptr[2] == 3 && a->ptr[3] == 2)
		ft_printf("rra\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 1 && a->ptr[2] == 4 && a->ptr[3] == 2)
		ft_printf("rra\nsa\nrra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 3 && a->ptr[2] == 4 && a->ptr[3] == 2)
		ft_printf("ra\nsa\nrra\nrra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 2 && a->ptr[2] == 1 && a->ptr[3] == 3)
		ft_printf("rra\nsa\nra\nra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 4 && a->ptr[2] == 1 && a->ptr[3] == 3)
		ft_printf("pb\nsa\npa\nra\nra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 1 && a->ptr[2] == 2 && a->ptr[3] == 3)
		ft_printf("rra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 4 && a->ptr[2] == 2 && a->ptr[3] == 3)
		ft_printf("sa\nrra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 1 && a->ptr[2] == 4 && a->ptr[3] == 3)
		ft_printf("ra\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 2 && a->ptr[2] == 4 && a->ptr[3] == 3)
		ft_printf("ra\nra\nsa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 2 && a->ptr[2] == 1 && a->ptr[3] == 4)
		ft_printf("ra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 3 && a->ptr[2] == 1 && a->ptr[3] == 4)
		ft_printf("ra\nra\nsa\nrra\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 1 && a->ptr[2] == 2 && a->ptr[3] == 4)
		ft_printf("ra\nsa\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 3 && a->ptr[2] == 2 && a->ptr[3] == 4)
		ft_printf("rra\nsa\nra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 1 && a->ptr[2] == 3 && a->ptr[3] == 4)
		ft_printf("sa\nra\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 2 && a->ptr[2] == 3 && a->ptr[3] == 4)
		ft_printf("sa\nra\nra\nsa\n");
}

void	cmd_brute_5(const t_vec *a)
{
	if (a->len != 5)
		return ;
	if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_printf("rra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_printf("ra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_printf("ra\nra\npb\npb\nra\npa\npa\nra\nra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 1)
		ft_printf("rra\npb\nrra\nrra\nsa\npa\nrra\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("rra\nrra\npb\nrra\nrra\npa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("rra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("rra\npb\nrra\npb\nrra\npa\nrra\npa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_printf("rra\nsa\nrra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("ra\npb\nra\nra\npa\nra\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("rra\nsa\nra\nra\nsa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("ra\npb\nsa\nra\nra\npa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("rra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_printf("rra\npb\nrra\npb\nra\npa\npa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nrra\npb\nrra\npa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\nrra\nrra\nsa\n");
}