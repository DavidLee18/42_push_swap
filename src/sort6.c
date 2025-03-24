/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:20:48 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_brute_4_1(const t_vec *a)
{
	if (a->ptr[0] == 4 && a->ptr[1] == 1 && a->ptr[2] == 3
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\nsa\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 4 && a->ptr[2] == 3
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "rra\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 1 && a->ptr[2] == 4
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 3 && a->ptr[2] == 4
		&& a->ptr[3] == 2)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\nrra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 2 && a->ptr[2] == 1
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nra\nra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 4 && a->ptr[2] == 1
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "pb\nsa\npa\nra\nra\n");
	else if (a->ptr[0] == 4 && a->ptr[1] == 1 && a->ptr[2] == 2
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nrra\nsa\n");
	else
		cmd_brute_4_2(a);
}

void	cmd_brute_4_2(const t_vec *a)
{
	if (a->ptr[0] == 1 && a->ptr[1] == 4 && a->ptr[2] == 2
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 1 && a->ptr[2] == 4
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 2 && a->ptr[2] == 4
		&& a->ptr[3] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 2 && a->ptr[2] == 1
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\n");
	else if (a->ptr[0] == 2 && a->ptr[1] == 3 && a->ptr[2] == 1
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nrra\n");
	else if (a->ptr[0] == 3 && a->ptr[1] == 1 && a->ptr[2] == 2
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 3 && a->ptr[2] == 2
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nra\n");
	else
		cmd_brute_4_3(a);
}

void	cmd_brute_4_3(const t_vec *a)
{
	if (a->ptr[0] == 2 && a->ptr[1] == 1 && a->ptr[2] == 3
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\n");
	else if (a->ptr[0] == 1 && a->ptr[1] == 2 && a->ptr[2] == 3
		&& a->ptr[3] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\nsa\n");
}

void	cmd_brute_5_1(const t_vec *a)
{
	if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\npb\nrra\nrra\npa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\npb\nrra\npb\nsb\nrra\npa\nrra\npa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\npb\nra\nra\npa\nra\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nra\nra\nsa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\npb\nsa\nra\nra\npa\nra\nra\n");
	else
		cmd_brute_5_2(a);
}

void	cmd_brute_5_2(const t_vec *a)
{
	if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "rra\npb\nrra\npb\nra\npa\npa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "sa\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\npb\nrra\npa\nrra\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 3
		&& a->ptr[1] == 5 && a->ptr[0] == 1)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nsa\nra\nsa\n");
	else
		cmd_brute_5_3(a);
}
