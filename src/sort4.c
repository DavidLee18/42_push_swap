/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/23 01:07:38 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_nth_3(t_list **dyn, t_stack_pair *idxs, size_t n, int head)
{
	push(dyn, (t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
			+ (n % 2 == 1) * (size_t)(&idxs->a)), head);
	rotate((t_vec *)((n % 2 == 0) * (size_t)(&idxs->b)
			+ (n % 2 == 1) * (size_t)(&idxs->a)), 1);
}

void	pa_all(t_list **dyn, t_stack_pair *ss)
{
	int	*val;

	val = pop(dyn, &ss->b);
	while (val != NULL)
	{
		push(dyn, &ss->a, *val);
		val = pop(dyn, &ss->b);
	}
}
