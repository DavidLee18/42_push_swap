/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:03:45 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/26 07:26:39 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	abs_isize(ssize_t i)
{
	if (i < 0)
		return ((size_t)(-i));
	return ((size_t)i);
}

size_t	min_usize(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}
