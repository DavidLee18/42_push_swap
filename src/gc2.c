/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:28:21 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 05:29:32 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gc_realloc3(t_list *temp_node, void **oldp, void *new)
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
			return ;
		}
		temp_node = temp_node->next;
	}
	*oldp = new;
}
