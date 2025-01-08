/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/08 12:18:00 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_pair	*ss;
	t_min_heap		*h;
	int				*i;
	t_list			*dyn_mem;

	if (argc == 1)
		return (0);
	dyn_mem = NULL;
	ss = (t_stack_pair *)gc_calloc(&dyn_mem, 1, sizeof(t_stack_pair));
	if (ss == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	h = (t_min_heap *)gc_calloc(&dyn_mem, 1, sizeof(t_min_heap));
	if (h == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), gc_free_all(dyn_mem), 0);
	while (--argc >= 1)
	{
		i = atoi_(&dyn_mem, argv[argc]);
		if (i == NULL)
			return (write(STDERR_FILENO, "Error\n", 6), gc_free_all(dyn_mem),
				0);
		push(&dyn_mem, &ss->a, *i);
	}
	analyze_sort(&dyn_mem, ss, h);
	return (gc_free_all(dyn_mem), 0);
}

_Bool	analyze_sort(t_list **dyn, t_stack_pair *ss, t_min_heap *h)
{
	size_t	*offset;
	size_t	alen;

	if (has_dup(ss->a))
		return (write(STDERR_FILENO, "Error\n", 6), 0);
	else if (ss->a.len == 1)
		return (1);
	offset = twisted_sorted(dyn, ss->a);
	if (offset != NULL)
		return (cmd_rotate(&ss->a, *offset), 1);
	alen = ss->a.len;
	insert_all(dyn, ss->a, h);
	print_heap(*h, 0);
	cmd_rot_pb(dyn, ss, h);
	vec_init(&ss->a);
	cmd_pa_all(dyn, ss, alen);
	print_vec(ss->a);
	return (1);
}
