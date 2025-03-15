/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:37:49 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 18:50:06 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_brute_5_13(const t_vec *a)
{
	if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("rra\nrra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_printf("ra\nsa\nrra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nra\nsa\nrra\n");
	else
		cmd_brute_5_14(a);
}

void	cmd_brute_5_14(const t_vec *a)
{
	if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 1 && a->ptr[0] == 5)
		ft_printf("ra\nra\nsa\nra\nsa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("ra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 3
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nsa\n");
	else
		cmd_brute_5_15(a);
}

void	cmd_brute_5_15(const t_vec *a)
{
	if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nrra\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("ra\nsa\nra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nra\nra\n");
	else
		cmd_brute_5_16(a);
}

void	cmd_brute_5_16(const t_vec *a)
{
	if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 5)
		ft_printf("rra\nsa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nrra\nrra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 5)
		ft_printf("sa\nra\nsa\nrra\nsa\nrra\nrra\nsa\n");
}
