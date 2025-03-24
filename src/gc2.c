/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:28:21 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 15:10:03 by jaehylee         ###   ########.fr       */
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

char
	*gc_strjoin(t_list **dyn, char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)gc_calloc(dyn,
			(ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

t_stack_pair	*join_atoi_split(t_list **dyn, char **argv, int argc)
{
	char	*str;
	char	**tmp;
	int		i;

	i = 0;
	str = argv[++i];
	if (*str == '\0' || ft_strchr(str, ' '))
		return (NULL);
	while (++i < argc)
	{
		if (*argv[i] == '\0' || ft_strchr(argv[i], ' '))
			return (NULL);
		str = gc_strjoin(dyn, str, " ");
		if (str == NULL)
			return (NULL);
		str = gc_strjoin(dyn, str, argv[i]);
		if (str == NULL)
			return (NULL);
	}
	tmp = gc_split(dyn, str, ' ');
	if (tmp == NULL)
		return (NULL);
	return (atoi_push(dyn, tmp));
}

t_stack_pair	*atoi_push(t_list **dyn, char **nums)
{
	t_stack_pair	*ss;
	size_t			i;
	int				*j;

	ss = (t_stack_pair *)gc_calloc(dyn, 1, sizeof(t_stack_pair));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (nums[i])
	{
		j = atoi_(dyn, nums[i]);
		if (j == NULL)
			return (NULL);
		push_front(dyn, &ss->a, *j);
		i++;
	}
	return (ss);
}
