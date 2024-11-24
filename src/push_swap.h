/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:29:44 by jaehylee          #+#    #+#             */
/*   Updated: 2024/11/25 03:49:16 by jaehylee         ###   ########.fr       */
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
	size_t	len;
	size_t	cap;
}	t_vec;

#endif
