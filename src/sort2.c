/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:28:25 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/08 11:51:37 by jaehylee         ###   ########.fr       */
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

void	cmd_pa_all(t_list **dyn, t_stack_pair *ss, size_t vlen)
{
	int		*val;
	size_t	i;

	i = 0;
	while (i < vlen)
	{
		val = pop(dyn, &ss->b);
		if (val == NULL)
			return ;
		push(dyn, &ss->a, *val);
		ft_printf("pa\n");
		i++;
	}
}

void	cmd_rotate_until(t_vec *v, _Bool up, int val)
{
	size_t	i;

	i = wrapping_sub(v->top, 1, v->len);
	while (v->ptr[i] != val)
	{
		rotate(v, (up == 1) * 2 - 1);
		if (!up)
			ft_printf("r");
		ft_printf("ra\n");
		i = wrapping_sub(v->top, 1, v->len);
	}
}
