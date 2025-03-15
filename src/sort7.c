/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:55:35 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 18:19:00 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_brute_5_3(const t_vec *a)
{
	if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("sa\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nsa\nra\nsa\n");
	else
		cmd_brute_5_4(a);
}

void	cmd_brute_5_4(const t_vec *a)
{
	if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nsa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nra\nsa\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 2)
		ft_printf("ra\nra\nsa\nra\nra\n");
	else
		cmd_brute_5_5(a);
}

void	cmd_brute_5_5(const t_vec *a)
{
	if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nrra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 2)
		ft_printf("rra\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nra\nsa\n");
	else
		cmd_brute_5_6(a);
}

void	cmd_brute_5_6(const t_vec *a)
{
	if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("sa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("rra\nsa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 2)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nra\nra\n");
	else
		cmd_brute_5_7(a);
}

void	cmd_brute_5_7(const t_vec *a)
{
	if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("pb\nrra\npb\nra\npa\npa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 3)
		ft_printf("sa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nra\nsa\nra\nra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_printf("sa\nrra\nrra\nsa\nra\n");
	else
		cmd_brute_5_8(a);
}
