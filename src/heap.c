/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:24:14 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/01 03:27:05 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	avail_pos(t_min_heap *heap, size_t from)
{
	if (!heap || !heap->ptr || from >= heap->cap)
		return (SIZE_MAX);
	if (2 * from + 2 < heap->cap)
		return (min_usize(avail_pos(heap, 2 * from + 1),
				avail_pos(heap, 2 * from + 2)));
	else if (2 * from + 2 == heap->cap)
	{
		if (is_null(heap->ptr[2 * from + 1]))
			return (2 * from + 1);
		heapalloc(heap);
		return (2 * from + 2);
	}
	else
	{
		if (is_null(heap->ptr[from]))
			return (from);
		heapalloc(heap);
		return (2 * from + 1);
	}
}

void	bubble_up(t_min_heap *heap, t_rot_dist dist)
{
	size_t		i;
	t_rot_dist	temp;

	if (!heap)
		return ;
	if (heap->cap == 0)
		heapalloc(heap);
	i = avail_pos(heap);
	heap->ptr[i] = dist;
	if (i == 0)
		return ;
	while (i != 0 && heap->ptr[(i - 1) / 2].dist > heap->ptr[i].dist)
	{
		temp = heap->ptr[(i - 1) / 2];
		heap->ptr[(i - 1) / 2] = heap->ptr[i];
		heap->ptr[i] = temp;
		i = (i - 1) / 2;
	}
}

t_rot_dist	*pop_bubble(t_min_heap *heap)
{
	t_rot_dist	*res;

	if (!heap || heap->cap == 0)
		return (NULL);
	res = (t_rot_dist *)ft_calloc(1, sizeof(t_rot_dist));
	if (!res)
		return (NULL);
	*res = heap->ptr[0];
	heap->ptr[0] = (t_rot_dist){.dist = 0, .idx = 0};
	return (res);
}

void	heap_init(t_min_heap *heap)
{
	if (!heap)
		return ;
	heap->cap = 0;
	heap->ptr = NULL;
}

void	heapalloc(t_min_heap *heap)
{
	if (!heap)
		return ;
	if (heap->cap == 0)
		heap->ptr = (t_rot_dist *)ft_calloc(1, sizeof(t_rot_dist));
	else
		heap->ptr = (t_rot_dist *)ft_realloc(&heap->ptr,
				heap->cap * sizeof(t_rot_dist),
				heap->cap * 2 * sizeof(t_rot_dist));
	if (!heap->ptr)
		return ;
	if (heap->cap == 0)
		heap->cap == 1;
	else
		heap->cap *= 2;
}
