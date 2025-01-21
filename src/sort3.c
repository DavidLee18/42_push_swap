/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:42:48 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/21 23:48:55 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	radix_nth(t_list **dyn, t_stack_pair *idxs, size_t n);

t_vec	*remap_idx(t_list **dyn, t_vec idxs, t_vec sorted_idxs);

void	cmd_radix(t_list **dyn, t_stack_pair *ss);
