/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 16:43:33 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/src/ft_printf.h"
# define SIZE_MAX_ 18446744073709551615
# define INT_MAX_ 2147483647
# define INT_MIN_ -2147483648

typedef struct s_vec
{
	int		*ptr;
	size_t	len;
	size_t	cap;
}	t_vec;

typedef struct s_stack_pair
{
	t_vec	a;
	t_vec	b;
}	t_stack_pair;

void		push_back(t_list **dyn, t_vec *vec, int value);
void		push_front(t_list **dyn, t_vec *vec, int value);
int			*pop_back(t_list **dyn, t_vec *vec);
void		vecalloc(t_list **dyn, t_vec *vec);
_Bool		has_dup(t_vec v);
void		print_vec(t_vec v);
t_vec		*_1ota_rev(t_list **dyn, size_t i);
t_vec		*veccpy(t_list **dyn, t_vec v);
_Bool		velem(int i, t_vec v);
int			*vecmax(t_list **dyn, t_vec v);
int			veccmp(t_vec v1, t_vec v2);
_Bool		consec_eq(t_vec v);

int			*atoi_(t_list **dyn, const char *str);
int			sort(t_list **dyn, t_stack_pair *ss);

t_vec		*msort(t_list **dyn, t_vec v);
t_vec		*msplit(t_list **dyn, t_vec v);
t_vec		*merge(t_list **dyn, t_vec a, t_vec b);
t_vec		*pure(t_vec *v, t_vec val);

_Bool		radix(t_list **dyn, t_vec *v);
_Bool		radix_opt(t_list **dyn, t_stack_pair *idxs, size_t max);
_Bool		radix3_nth_01(t_list **dyn, t_stack_pair *idxs, size_t n);
void		radix3_nth_2(t_list **dyn, t_stack_pair *idxs, size_t n);
_Bool		radix43_nth_01(t_list **dyn, t_stack_pair *idxs, size_t n);
_Bool		radix43_nth_23(t_list **dyn, t_stack_pair *idxs, size_t n);
void		pa_all(t_list **dyn, t_stack_pair *ss);

t_vec		*map_idx(t_list **dyn, t_vec before, t_vec after);
t_vec		*remap_idx(t_list **dyn, t_vec idxs, t_vec sorted_idxs);

void		cmd_radix(t_list **dyn, t_stack_pair *ss);
void		cmd_radix_opt(t_list **dyn, t_stack_pair *idxs, size_t max);
void		cmd_radix3_nth_0(t_list **dyn, t_stack_pair *idxs, size_t n);
void		cmd_radix3_nth_1(t_list **dyn, t_stack_pair *idxs, size_t n,
				int head);
void		cmd_radix3_nth_2(t_list **dyn, t_stack_pair *idxs, size_t n);
void		cmd_radix43_nth_0(t_list **dyn, t_stack_pair *idxs, size_t n);
void		cmd_radix43_nth_1(t_list **dyn, t_stack_pair *idxs, size_t n,
				int head);
void		cmd_radix43_nth_2(t_list **dyn, t_stack_pair *idxs, size_t n);
void		cmd_radix43_nth_3(t_list **dyn, t_stack_pair *idxs, size_t n,
				int head);
void		cmd_pa_all(t_list **dyn, t_stack_pair *ss);
void		cmd_brute(const t_vec *a);
void		cmd_brute_3(const t_vec *a);
void		cmd_brute_4(const t_vec *a);
void		cmd_brute_5(const t_vec *a);

size_t		min_usize(size_t a, size_t b);
size_t		abs_isize(ssize_t i);
size_t		upow(size_t a, size_t b);
t_vec		*either_vec(_Bool cond, t_vec *a, t_vec *b);
size_t		nth3_digit(size_t num, size_t n);
size_t		nth43_digit(size_t num, size_t n);

void		gc_free_all(t_list *head);
_Bool		gc_add_to_list(t_list **head, void *new);
void		*gc_calloc(t_list **head, size_t count, size_t size);
_Bool		gc_realloc(t_list **dyn, void **oldp, size_t old_size,
				size_t new_size);
_Bool		gc_realloc2(t_list **dyn, void **oldp, void *new);
_Bool		gc_realloc3(t_list *temp_node, void **oldp, void *new);
char		*gc_substr(t_list **dyn, char const *s,
				unsigned int start, size_t len);
char		**gc_split(t_list **dyn, char const *s, char c);
char		*gc_strjoin(t_list **dyn, char const *s1, char const *s2);

t_stack_pair	*join_atoi_split(t_list **dyn, char **argv, int argc);
t_stack_pair	*atoi_push(t_list **dyn, char **nums);

#endif
