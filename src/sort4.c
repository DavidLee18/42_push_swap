/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 16:47:49 by jaehylee         ###   ########.fr       */
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
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nsa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nra\nsa\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nrra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("pb\nrra\npb\nra\npa\npa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nrra\npb\nra\nra\npa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("pb\npb\nra\nra\npa\npa\nrra\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("ra\nra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("ra\nsa\nrra\nsa\nrra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("ra\nra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("rra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_printf("rra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("rra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("ra\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("rra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("ra\nra\nsa\nrra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("ra\nsa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_printf("ra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("rra\nsa\nra\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("rra\nrra\nsa\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("rra\nsa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("rra\nsa\nrra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("rra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("rra\nsa\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 3 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("sa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 5 && a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nsa\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nra\nra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nrra\nsa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nra\nra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 5 && a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_printf("sa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("rra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("rra\nrra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nrra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 3 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nra\nsa\nra\nsa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("ra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 3 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 4 && a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nrra\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 1 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 2 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 4 && a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 1 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 2 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 3 && a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nsa\nrra\nrra\nsa\n");
}

_Bool	radix_opt(t_list **dyn, t_stack_pair *idxs, const size_t max)
{
	size_t	n;
	size_t	digits;

	n = 0;
	digits = ft_ulog(3, max);
	while (++n < digits)
	{
		if (!radix3_nth_01(dyn, idxs, n - 1))
			return (0);
	}
	if (max > upow(3, digits) && max < 4 * upow(3, digits - 1))
	{
		if (!radix43_nth_01(dyn, idxs, digits - 1))
			return (0);
	}
	else if (!radix3_nth_01(dyn, idxs, digits - 1) || !radix3_nth_01(dyn, idxs, digits))
		return (0);
	if (idxs->b.len != 0)
		pa_all(dyn, idxs);
	return (1);
}

_Bool	radix43_nth_01(t_list **dyn, t_stack_pair *idxs, const size_t n)
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
		if (nth43_digit(*temp, n) == 0)
			push_back(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a),
				*temp);
		else if (nth43_digit(*temp, n) == 1)
			push_front(dyn, either_vec(n % 2 == 0, &idxs->b, &idxs->a), *temp);
		else
			push_front(dyn, either_vec(n % 2 == 0, &idxs->a, &idxs->b), *temp);
	}
	return (radix43_nth_23(dyn, idxs, n));
}