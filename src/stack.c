/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 06:46:02 by jaehylee          #+#    #+#             */
/*   Updated: 2024/11/25 07:00:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_vec *vec, int value);
int		*pop(t_vec *vec);

void	rotate(t_vec *vec, int n)
{
	if (n == 0 || vec->len <= 1)
		return ;
	else if (n > 0)
	{
		if (vec->top == vec->len - 1)
			vec->top = 0;
		else
			vec->top++;
		rotate(vec, n - 1);
	}
	else
	{
		if (vec->top == 0)
			vec->top = vec->len - 1;
		else
			vec->top--;
		rotate(vec, n + 1);
	}
}
