/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:03:45 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/01 03:28:51 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	is_null(t_rot_dist d)
{
	return (d.dist == 0 && d.idx == 0);
}

size_t	min_usize(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}
