/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:28:25 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/05 18:47:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rot_swap(t_vec *v, ssize_t offset)
{
	while (offset != 0)
	{
		rotate(v, 2 * (offset > 0) - 1);
		if (offset < 0)
			ft_printf("r");
		ft_printf("ra\n");
		offset -= (offset > 0) * 1 + (offset < 0) * (-1);
	}
	swap(v);
	ft_printf("sa\n");
}
