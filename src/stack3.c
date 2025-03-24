/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:37 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:05:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vec	*_1ota_rev(t_list **dyn, const size_t i)
{
	t_vec	*res;
	size_t	j;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	j = i;
	while (j > 0)
	{
		push_back(dyn, res, (int)j);
		j--;
	}
	return (res);
}
