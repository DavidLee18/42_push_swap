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
