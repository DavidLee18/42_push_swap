/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/09 15:25:27 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/src/ft_printf.h"
# define SIZE_MAX 18446744073709551615

typedef struct s_vec
{
	int		*ptr;
	size_t	top;
	size_t	bottom;
	size_t	len;
	size_t	cap;
}	t_vec;

typedef struct s_rot_dist
{
	size_t	idx;
	size_t	dist;
}	t_rot_dist;

typedef struct s_min_heap
{
	t_rot_dist	*ptr;
	size_t		cap;
}	t_min_heap;

size_t		wrapping_add(size_t lhs, size_t rhs, size_t max);
size_t		wrapping_sub(size_t lhs, size_t rhs, size_t max);

void		push(t_vec *vec, int value);
int			*pop(t_vec *vec);
void		rotate(t_vec *vec, int n);
void		swap(t_vec *vec);
void		vec_init(t_vec *vec);
void		vecalloc(t_vec *vec);

void		insert(t_min_heap *heap, t_rot_dist dist);
t_rot_dist	*pop_bubble(t_min_heap *heap);
void		heap_init(t_min_heap *heap);
void		heapalloc(t_min_heap *heap);
void		hswap(t_min_heap *heap, size_t a, size_t b);

_Bool		is_null(t_rot_dist d);
size_t		min_usize(size_t a, size_t b);

#endif
