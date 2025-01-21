/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/21 17:13:29 by jaehylee         ###   ########.fr       */
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
	sort(&dyn_mem, ss);
	print_vec(ss->a);
	return (gc_free_all(dyn_mem), 0);
}

void	sort(t_list **dyn, t_stack_pair *ss)
{
	t_vec	*idxs;
	t_vec	*pre_cooked;

	pre_cooked = msort(dyn, ss->a);
	if (pre_cooked == NULL)
		return ;
	idxs = map_idx(dyn, ss->a, *pre_cooked);
	if (idxs == NULL)
		return ;
	radix(dyn, idxs);
	idxs = remap_idx(dyn, *idxs);
	ss->a = *idxs;
	cmd_radix(dyn, ss);
}

t_vec	*map_idx(t_list **dyn, t_vec before, t_vec after)
{
	t_vec	*res;
	size_t	i;
	size_t	j;

	res = iota(dyn, before.len);
	if (res == NULL || before.len != after.len)
		return (NULL);
	i = after.bottom;
	while (i != after.top)
	{
		j = before.bottom;
		while (j < before.top)
		{
			if (before.ptr[j] == after.ptr[i])
				res->ptr[j] = i;
			j = wrapping_add(j, 1, before.len);
		}
		i = wrapping_add(i, 1, after.len);
	}
	return (res);
}
