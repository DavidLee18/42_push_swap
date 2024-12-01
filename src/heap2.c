/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:44:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/01 17:34:38 by jaehylee         ###   ########.fr       */
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

void	balance(t_min_heap *heap, size_t from)
{
	if (!heap || !heap->ptr || (heap->cap != 0 && from >= heap->cap))
		return ;
	if (2 * from + 2 < heap->cap)
	{
		if (is_null(heap->ptr[2 * from + 1])
			&& !is_null(heap->ptr[2 * from + 2])
			&& (is_null(heap->ptr[from])
				|| heap->ptr[from].dist > heap->ptr[2 * from + 2].dist))
		{
			hswap(heap, 2 * from + 2, from);
			balance(heap, 2 * from + 2);
		}
		else if (!is_null(heap->ptr[2 * from + 1])
			&& is_null(heap->ptr[2 * from + 2]))
		{
			if (is_null(heap->ptr[from]))
			{
			}
			else
		}
		else if (!is_null(heap->ptr[2 * from + 1])
			&& !is_null(heap->ptr[2 * from + 2]))
		{
			if (is_null(heap->ptr[from]))
			{
			}
			else
		}
	}
	else if (2 * from + 2 == heap->cap
		&& !is_null(heap->ptr[2 * from + 1])
		&& (heap->ptr[from].dist > heap->ptr[2 * from + 1].dist
			|| is_null(heap->ptr[from])))
		hswap(heap, 2 * from + 1, from);
}
