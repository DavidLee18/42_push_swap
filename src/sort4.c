/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:18:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/22 12:19:24 by jaehylee         ###   ########.fr       */
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
