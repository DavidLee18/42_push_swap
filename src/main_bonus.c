/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 13:17:54 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

int	main(const int argc, char **argv)
{
	t_stack_pair	*ss;
	t_list			*dyn_mem;
	int				i;

	if (argc == 1)
		return (0);
	dyn_mem = NULL;
	ss = join_atoi_split(&dyn_mem, argv, argc);
	if (ss == NULL || has_dup(ss->a))
		return (write(STDERR_FILENO, "Error\n", 6), gc_free_all(dyn_mem),
			0);
	i = check(&dyn_mem, ss);
	if (i == 0)
		ft_printf("KO\n");
	else if (i == -1)
		write(STDERR_FILENO, "Error\n", 6);
	else
		ft_printf("OK\n");
	return (gc_free_all(dyn_mem), 0);
}

int	check(t_list **dyn, t_stack_pair *ss)
{
	char	*cmd;
	size_t	i;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd != NULL)
	{
		if (!exec_cmd(dyn, ss, cmd))
			return (free(cmd), -1);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	free(cmd);
	cmd = get_next_line(STDIN_FILENO);
	free(cmd);
	i = 0;
	while (++i < ss->a.len)
	{
		if (ss->a.ptr[i - 1] <= ss->a.ptr[i])
			return (0);
	}
	return (ss->b.len == 0);
}

_Bool	exec_cmd(t_list **dyn, t_stack_pair *ss, char *cmd)
{
	if (ft_strlen(cmd) < 2)
		return (0);
	cmd = rtrim_nl(cmd);
	if (ft_strcmp(cmd, "pa") == 0)
		return (exec_pa(dyn, ss));
	if (ft_strcmp(cmd, "pb") == 0)
		return (exec_pb(dyn, ss));
	if (ft_strcmp(cmd, "sa") == 0)
		return (exec_sa(ss));
	if (ft_strcmp(cmd, "sb") == 0)
		return (exec_sb(ss));
	if (ft_strcmp(cmd, "ss") == 0)
		return (exec_sa(ss) && exec_sb(ss));
	if (ft_strcmp(cmd, "ra") == 0)
		return (exec_ra(dyn, ss));
	return (exec_cmd2(dyn, ss, cmd));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*rtrim_nl(char *s)
{
	if (s[ft_strlen(s) - 1] == '\n')
		s[ft_strlen(s) - 1] = '\0';
	return (s);
}
