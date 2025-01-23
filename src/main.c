/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/24 01:03:41 by jaehylee         ###   ########.fr       */
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
		push_back(&dyn_mem, &ss->a, *i);
	}
	// print_vec(ss->a);
	if (!sort(&dyn_mem, ss))
		write(STDERR_FILENO, "Error\n", 6);
	return (gc_free_all(dyn_mem), 0);
}

_Bool	sort(t_list **dyn, t_stack_pair *ss)
{
	t_vec	*idxs;
	t_vec	*pre_cooked;
	t_vec	*sorted_idxs;

	pre_cooked = msort(dyn, ss->a);
	if (pre_cooked == NULL || consec_eq(*pre_cooked))
		return (0);
	// ft_printf("pre_cooked: ");
	// print_vec(*pre_cooked);
	if (veccmp(ss->a, *pre_cooked) == 0)
		return (0);
	idxs = map_idx(dyn, ss->a, *pre_cooked);
	if (idxs == NULL)
		return (0);
	// ft_printf("idxs: ");
	// print_vec(*idxs);
	sorted_idxs = veccpy(dyn, *idxs);
	if (sorted_idxs == NULL || !radix(dyn, sorted_idxs))
		return (0);
	// ft_printf("idxs sorted: ");
	// print_vec(*sorted_idxs);
	idxs = remap_idx(dyn, *idxs, *sorted_idxs);
	if (idxs == NULL)
		return (0);
	// ft_printf("idxs remapped: ");
	// print_vec(*idxs);
	ss->a = *idxs;
	cmd_radix(dyn, ss);
	return (1);
}

t_vec	*map_idx(t_list **dyn, t_vec before, t_vec after)
{
	t_vec	*res;
	size_t	i;
	size_t	j;

	res = _1ota_rev(dyn, before.len);
	if (res == NULL || before.len != after.len)
		return (NULL);
	i = 0;
	while (i < after.len)
	{
		j = 0;
		while (j < before.len)
		{
			if (before.ptr[j] == after.ptr[i])
				res->ptr[j] = res->len - i;
			j++;
		}
		i++;
	}
	return (res);
}
