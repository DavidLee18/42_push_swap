/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:39:51 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/06 09:40:01 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 이재현 on 2025-03-06.
//

#include "push_swap.h"

static char
	**gc_alloc_split(t_list **dyn, char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == c)
			total++;
		i++;
	}
	split = (char **)gc_calloc(dyn, total + 2, sizeof(char *));
	if (!split)
		return (NULL);
	return (split);
}

char
	*gc_substr(t_list **dyn, char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)gc_calloc(dyn, len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static void
	*gc_split_range(t_list **dyn, char **split, char const *s,
		const t_split_next *st, t_split_next *lt)
{
	split[lt->length] = gc_substr(dyn, s, st->start, st->length);
	if (!split[lt->length])
		return (NULL);
	lt->length++;
	return (split);
}

static void
	*gc_split_by_char(t_list **dyn, char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			st.start = lt.start;
			st.length = (i - lt.start);
			if (i > lt.start && !gc_split_range(dyn, split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = (i - lt.start);
	if (i > lt.start && i > 0 && !gc_split_range(dyn, split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char
	**gc_split(t_list **dyn, char const *s, char c)
{
	char	**split;

	split = gc_alloc_split(dyn, s, c);
	if (!split)
		return (NULL);
	if (!gc_split_by_char(dyn, split, s, c))
		return (NULL);
	return (split);
}