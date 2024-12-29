/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2024/12/29 15:49:49 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_vec		*v;
	t_min_heap	*h;
	int			*i;
	t_list		*dyn_mem;

	if (argc == 1)
		return (0);
	dyn_mem = NULL;
	v = (t_vec *)gc_calloc(&dyn_mem, 1, sizeof(t_vec));
	if (v == NULL)
		return (ft_printf("Error\n"), 0);
	h = (t_min_heap *)gc_calloc(&dyn_mem, 1, sizeof(t_min_heap));
	if (h == NULL)
		return (ft_printf("Error\n"), gc_free_all(dyn_mem), 0);
	while (argc > 1)
	{
		i = atoi_(&dyn_mem, argv[argc - 1]);
		if (i == NULL)
			return (ft_printf("Error\n"), gc_free_all(dyn_mem), 0);
		push(&dyn_mem, v, *i);
		argc--;
	}
	print_vec(*v);
	analyze_sort(&dyn_mem, v, h);
	return (gc_free_all(dyn_mem), 0);
}

void	analyze_sort(t_list **dyn, t_vec *v, t_min_heap *h)
{
	if (has_dup(*v))
	{
		ft_printf("Error\n");
		return ;
	}
	analyze_stack(dyn, *v, h);
	print_heap(*h);
	while (!hcomplete(*h))
	{
		print_cmds(v, h);
		analyze_stack(dyn, *v, h);
	}
}
