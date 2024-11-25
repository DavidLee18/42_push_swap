/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/11/26 04:53:11 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/src/ft_printf.h"

typedef struct s_vec
{
	int		*ptr;
	size_t	top;
	size_t	bottom;
	size_t	len;
	size_t	cap;
}	t_vec;

void	push(t_vec *vec, int value);
int		*pop(t_vec *vec);
void	rotate(t_vec *vec, int n);
void	swap(t_vec *vec);
size_t	wrapping_add(size_t lhs, size_t rhs, size_t max);
size_t	wrapping_sub(size_t lhs, size_t rhs, size_t max);
void	vec_init(t_vec *vec);
void	vecalloc(t_vec *vec);

#endif
