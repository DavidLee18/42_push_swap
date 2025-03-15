/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/15 16:45:18 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

int		check(t_list **dyn, t_stack_pair *ss);
_Bool	exec_cmd(t_list **dyn, t_stack_pair *ss, char *cmd);
_Bool	exec_cmd2(t_list **dyn, t_stack_pair *ss, char *cmd);
_Bool	exec_pa(t_list **dyn, t_stack_pair *ss);
_Bool	exec_pb(t_list **dyn, t_stack_pair *ss);
_Bool	exec_sa(t_stack_pair *ss);
_Bool	exec_sb(t_stack_pair *ss);
_Bool	exec_ra(t_list **dyn, t_stack_pair *ss);
_Bool	exec_rb(t_list **dyn, t_stack_pair *ss);
_Bool	exec_rra(t_list **dyn, t_stack_pair *ss);
_Bool	exec_rrb(t_list **dyn, t_stack_pair *ss);
int		ft_strcmp(const char *s1, const char *s2);
char	*rtrim_nl(char *s);
#endif //PUSH_SWAP_BONUS_H
