/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 04:16:05 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/21 18:47:40 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		upow(const size_t a, const size_t b)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 1;
	while (++i <= b)
		j *= a;
	return (j);
}

t_vec		*either_vec(const _Bool cond, t_vec *a, t_vec *b)
{
	if (cond)
		return (a);
	return (b);
}

size_t		nth3_digit(const size_t num, const size_t n)
{
	return (num % upow(3, n+1) / upow(3, n));
}