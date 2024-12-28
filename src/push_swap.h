/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 07:31:30 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/src/ft_printf.h"
# define SIZE_MAX 18446744073709551615
# define INT_MAX 2147483647
# define INT_MIN -2147483648

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

void		push(t_list **dyn, t_vec *vec, int value);
int			*pop(t_list **dyn, t_vec *vec);
void		rotate(t_vec *vec, int n);
void		swap(t_vec *vec);
void		vec_init(t_vec *vec);
void		vecalloc(t_list **dyn, t_vec *vec);
_Bool		has_dup(t_vec v);

size_t		insert(t_list **dyn, t_min_heap *h, ssize_t dist);
size_t		insert2(t_list **dyn, t_min_heap *h, ssize_t dist);
size_t		insert3(t_list **dyn, t_min_heap *h, ssize_t dist);
ssize_t		extract(t_min_heap *h);
void		extract2(t_min_heap *h);
void		halloc(t_list **dyn, t_min_heap *h);
// size_t		bubble_down(t_min_heap *h, size_t a, size_t b);
size_t		max_balanced_depth(t_min_heap h);
size_t		hpat(t_min_heap h);
void		hswap(t_min_heap *h, size_t a, size_t b);
size_t		hlen(t_min_heap h);
_Bool		hcomplete(t_min_heap h);

void		analyze_stack(t_list **dyn, t_vec v, t_min_heap *h);
void		print_cmds(t_vec *v, t_min_heap *h);
ssize_t		measure_dist(t_vec v, size_t i);
int			*atoi_(t_list **dyn, char *str);
void		analyze_sort(t_list **dyn, t_vec *v, t_min_heap *h);

size_t		min_usize(size_t a, size_t b);
size_t		abs_isize(ssize_t i);
size_t		wrapping_add(size_t lhs, size_t rhs, size_t max);
size_t		wrapping_sub(size_t lhs, size_t rhs, size_t max);
void		gc_free_all(t_list *head);
_Bool		gc_add_to_list(t_list **head, void *new);
void		*gc_calloc(t_list **head, size_t count, size_t size);
void		gc_realloc(t_list **dyn, void **oldp, const size_t old_size,
				const size_t new_size);
void		gc_realloc2(t_list **dyn, void **oldp, void *new);
void		gc_realloc3(t_list *temp_node, void **oldp, void *new);

#endif
