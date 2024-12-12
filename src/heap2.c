/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/09 15:25:23 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hswap(t_min_heap *heap, size_t a, size_t b)
{
	t_rot_dist	temp;

	if (!heap || !heap->ptr || heap->cap == 0 || a >= heap->cap
		|| b >= heap->cap)
		return ;
	temp = heap->ptr[a];
	heap->ptr[a] = heap->ptr[b];
	heap->ptr[b] = temp;
}
