/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:28:21 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:06:10 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
