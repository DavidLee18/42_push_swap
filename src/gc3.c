/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.k>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:39:51 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 21:32:17 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		t_split_next *ts)
{
	split[(ts + 1)->length] = gc_substr(dyn, s, ts->start, ts->length);
	if (!split[(ts + 1)->length])
		return (NULL);
	(ts + 1)->length++;
	return (split);
}

static void
	*gc_split_by_char(t_list **dyn, char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	ts[2];

	i = 0;
	ts[1].length = 0;
	ts[1].start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ts[0].start = ts[1].start;
			ts[0].length = (i - ts[1].start);
			if (i > ts[1].start && !gc_split_range(dyn, split, s, &ts[0]))
				return (NULL);
			ts[1].start = i + 1;
		}
		i++;
	}
	ts[0].start = ts[1].start;
	ts[0].length = (i - ts[1].start);
	if (i > ts[1].start && i > 0 && !gc_split_range(dyn, split, s, &ts[0]))
		return (NULL);
	split[ts[1].length] = 0;
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
