/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:41:48 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 05:29:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gc_free_all(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
}

_Bool	gc_add_to_list(t_list **head, void *new)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_calloc(1, sizeof(t_list));
	if (!node)
		return (0);
	node->content = new;
	node->next = NULL;
	if (!(*head))
	{
		(*head) = node;
		return (1);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

void	*gc_calloc(t_list **head, size_t count, size_t size)
{
	void	*new;

	new = ft_calloc(count, size);
	if (!new)
		return (NULL);
	if (!gc_add_to_list(head, new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

void	gc_realloc(t_list **dyn, void **oldp, const size_t old_size,
			const size_t new_size)
{
	void	*temp;
	t_list	*temp_node;

	temp = gc_calloc(dyn, 1, new_size);
	if (temp == NULL)
	{
		*oldp = NULL;
		return ;
	}
	ft_bzero(temp, new_size);
	if (*oldp)
		ft_memmove_(temp, *oldp, min_usize(old_size, new_size));
	temp_node = *dyn;
	if (temp_node->next == NULL)
		*oldp = temp;
	else if (temp_node->next && !temp_node->next->next)
	{
		*dyn = temp_node->next;
		free(temp_node->content);
		free(temp_node);
		*oldp = temp;
	}
	else
		gc_realloc2(dyn, oldp, temp);
}

void	gc_realloc2(t_list **dyn, void **oldp, void *new)
{
	t_list	*temp_node;

	temp_node = *dyn;
	if (temp_node->content == *oldp)
	{
		*dyn = temp_node->next;
		free(temp_node->content);
		free(temp_node);
		*oldp = new;
		return ;
	}
	gc_realloc3(temp_node, oldp, new);
}
