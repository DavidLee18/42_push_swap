/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/12 11:54:38 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_pair	*ss;
	int				*i;
	t_list			*dyn_mem;

	if (argc == 1)
		return (0);
	dyn_mem = NULL;
	ss = (t_stack_pair *)gc_calloc(&dyn_mem, 1, sizeof(t_stack_pair));
	if (ss == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	while (--argc >= 1)
	{
		i = atoi_(&dyn_mem, argv[argc]);
		if (i == NULL)
			return (write(STDERR_FILENO, "Error\n", 6), gc_free_all(dyn_mem),
				0);
		push(&dyn_mem, &ss->a, *i);
	}
	return (gc_free_all(dyn_mem), 0);
}
