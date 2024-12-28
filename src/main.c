/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/28 09:36:21 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vec		*v;
	t_min_heap	*h;
	int			*i;

	if (argc == 1)
		return (0);
	v = (t_vec *)ft_calloc(1, sizeof(t_vec));
	if (v == NULL)
		return (0);
	h = (t_min_heap *)ft_calloc(1, sizeof(t_min_heap));
	if (h == NULL)
		return (free(v), 0);
	while (argc > 1)
	{
		i = atoi_(argv[argc - 1]);
		if (i == NULL)
			return (ft_printf("Error\n"), 0);
		argc--;
	}
	return (0);
}
