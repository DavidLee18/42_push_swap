/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 09:01:46 by jaehylee          #+#    #+#             */
/*   Updated: 2025/01/24 09:22:34 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int argc, char **argv)
{
	t_stack_pair	*ss;
	t_list			*dyn_mem;

	if (argc == 1)
		return (0);
	dyn_mem = NULL;
	ss = join_atoi_split(&dyn_mem, argv, argc);
	if (ss == NULL)
		return (write(STDERR_FILENO, "Error\n", 6), gc_free_all(dyn_mem),
			0);
	// print_vec(ss->a);
	if (sort(&dyn_mem, ss) < 0)
		write(STDERR_FILENO, "Error\n", 6);
	return (gc_free_all(dyn_mem), 0);
}

int	sort(t_list **dyn, t_stack_pair *ss)
{
	t_vec	*idxs;
	const t_vec	*pre_cooked = msort(dyn, ss->a);
	t_vec	*sorted_idxs;

	if (pre_cooked == NULL || consec_eq(*pre_cooked))
		return (-1);
	// ft_printf("pre_cooked: ");
	// print_vec(*pre_cooked);
	if (veccmp(ss->a, *pre_cooked) == 0)
		return (0);
	idxs = map_idx(dyn, ss->a, *pre_cooked);
	if (idxs == NULL)
		return (-1);
	if (idxs->len <= 5)
		return (cmd_brute(&ss->a), 1);
	// ft_printf("idxs: ");
	// print_vec(*idxs);
	sorted_idxs = veccpy(dyn, *idxs);
	if (sorted_idxs == NULL || !radix(dyn, sorted_idxs))
		return (-1);
	// ft_printf("idxs sorted: ");
	// print_vec(*sorted_idxs);
	idxs = remap_idx(dyn, *idxs, *sorted_idxs);
	if (idxs == NULL)
		return (-1);
	// ft_printf("idxs remapped: ");
	// print_vec(*idxs);
	ss->a = *veccpy(dyn, *idxs);
	radix(dyn, idxs);
	// ft_printf("idxs sorted: ");
	// print_vec(*idxs);
	cmd_radix(dyn, ss);
	return (1);
}

t_vec	*map_idx(t_list **dyn, const t_vec before, const t_vec after)
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
				res->ptr[j] = (int)res->len - (int)i;
			j++;
		}
		i++;
	}
	return (res);
}
