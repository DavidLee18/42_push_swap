/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:04:55 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:04:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_brute_5_8(const t_vec *a)
{
	if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 4
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\npb\nra\nra\npa\nra\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "pb\npb\nra\nra\npa\npa\nrra\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nrra\nsa\nrra\nrra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nra\nsa\n");
	else
		cmd_brute_5_9(a);
}

void	cmd_brute_5_9(const t_vec *a)
{
	if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 4 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\nsa\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 4 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nrra\nsa\nra\nra\n");
	else if (a->ptr[4] == 4 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 4 && a->ptr[2] == 2
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nra\nsa\nrra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\nra\n");
	else
		cmd_brute_5_10(a);
}

void	cmd_brute_5_10(const t_vec *a)
{
	if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 4
		&& a->ptr[1] == 5 && a->ptr[0] == 3)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nra\nra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\nsa\nra\nsa\nra\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 1 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\nra\nsa\nrra\n");
	else
		cmd_brute_5_11(a);
}

void	cmd_brute_5_11(const t_vec *a)
{
	if (a->ptr[4] == 5 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nra\nra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nsa\nra\nsa\nrra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 3
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nsa\nrra\nsa\nra\nsa\nra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 3
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nsa\nrra\nrra\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nsa\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 3 && a->ptr[2] == 5
		&& a->ptr[1] == 2 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nrra\nsa\nra\nsa\nrra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nsa\nra\nsa\nra\nra\n");
	else
		cmd_brute_5_12(a);
}

void	cmd_brute_5_12(const t_vec *a)
{
	if (a->ptr[4] == 2 && a->ptr[3] == 5 && a->ptr[2] == 1
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\nsa\nra\n");
	else if (a->ptr[4] == 5 && a->ptr[3] == 1 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nrra\nsa\nrra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 5 && a->ptr[2] == 2
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nra\nra\nsa\nra\nsa\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 1 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nrra\n");
	else if (a->ptr[4] == 1 && a->ptr[3] == 2 && a->ptr[2] == 5
		&& a->ptr[1] == 3 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "sa\nrra\nrra\nsa\n");
	else if (a->ptr[4] == 3 && a->ptr[3] == 2 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "ra\nra\n");
	else if (a->ptr[4] == 2 && a->ptr[3] == 3 && a->ptr[2] == 1
		&& a->ptr[1] == 5 && a->ptr[0] == 4)
		ft_fprintf(STDOUT_FILENO, "rra\nrra\nsa\nrra\n");
	else
		cmd_brute_5_13(a);
}
