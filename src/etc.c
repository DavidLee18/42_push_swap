/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:03:45 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 15:47:50 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	abs_isize(ssize_t i)
{
	if (i < 0)
		return ((size_t)(-i));
	return ((size_t)i);
}

size_t	min_usize(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

int	*atoi_(t_list **dyn, char *str)
{
	int		*res;
	long	temp;
	size_t	i;
	int		sign;

	res = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (res == NULL)
		return (NULL);
	temp = 0;
	if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (NULL);
	sign = (str[0] != '-') * 2 - 1;
	i = (str[0] == '-' || str[0] == '+');
	while (i < ft_strlen(str))
	{
		temp = 10 * temp + sign * (str[i] - '0');
		i++;
	}
	if (temp < INT_MIN || temp > INT_MAX)
		return (NULL);
	*res = (int)temp;
	return (res);
}
