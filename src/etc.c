/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 08:03:45 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/05 05:39:06 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	abs_isize(ssize_t i)
{
	if (i < 0)
		return ((size_t)(-i));
	return ((size_t)i);
}

double	absf_(double d)
{
	if (d < 0)
		return (-d);
	return (d);
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
		if (str[i] < '0' || str[i] > '9')
			return (NULL);
		temp = 10 * temp + sign * (str[i] - '0');
		i++;
	}
	if (temp < INT_MIN_ || temp > INT_MAX_ || (ft_strlen(str) == 1 && sign
			&& !temp && ft_strncmp(str, "0", 1)))
		return (NULL);
	*res = (int)temp;
	return (res);
}
