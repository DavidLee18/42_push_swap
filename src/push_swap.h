/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/26 08:30:42 by jaehylee         ###   ########.fr       */
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

typedef struct s_min_heap
{
	ssize_t	*root;
	size_t	offset;
	size_t	cap;
}	t_min_heap;

size_t		wrapping_add(size_t lhs, size_t rhs, size_t max);
size_t		wrapping_sub(size_t lhs, size_t rhs, size_t max);

void		push(t_vec *vec, int value);
int			*pop(t_vec *vec);
void		rotate(t_vec *vec, int n);
void		swap(t_vec *vec);
void		vec_init(t_vec *vec);
void		valloc(t_vec *vec);

void		insert(t_min_heap *h, ssize_t dist);
void		insert2(t_min_heap *h, ssize_t dist);
void		insert3(t_min_heap *h, ssize_t dist);
ssize_t		*pop_bubble(t_min_heap *h);
void		halloc(t_min_heap *h);
void		hswap(t_min_heap *h, size_t a, size_t b);
size_t		max_balanced_depth(t_min_heap h);
size_t		hpat(t_min_heap h);

size_t		min_usize(size_t a, size_t b);
size_t		abs_isize(ssize_t i);

#endif
