/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:28:21 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/02 02:10:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

_Bool	gc_realloc3(t_list *temp_node, void **oldp, void *new)
{
	t_list	*temp_node2;

	while (temp_node->next && temp_node->next->next)
	{
		if (temp_node->next->content == *oldp)
		{
			temp_node2 = temp_node->next;
			temp_node->next = temp_node->next->next;
			free(temp_node2->content);
			free(temp_node2);
			*oldp = new;
			return (1);
		}
		temp_node = temp_node->next;
	}
	*oldp = new;
	return (1);
}
