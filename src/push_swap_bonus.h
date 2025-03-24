/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:21:59 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/24 16:22:13 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"

int		check(t_list **dyn, t_stack_pair *ss);
_Bool	exec_cmd(t_list **dyn, t_stack_pair *ss, char *cmd);
_Bool	exec_cmd2(t_list **dyn, t_stack_pair *ss, char *cmd);
void	exec_pa(t_list **dyn, t_stack_pair *ss);
void	exec_pb(t_list **dyn, t_stack_pair *ss);
void	exec_sa(t_stack_pair *ss);
void	exec_sb(t_stack_pair *ss);
void	exec_ra(t_list **dyn, t_stack_pair *ss);
void	exec_rb(t_list **dyn, t_stack_pair *ss);
void	exec_rra(t_list **dyn, t_stack_pair *ss);
void	exec_rrb(t_list **dyn, t_stack_pair *ss);
char	*rtrim_nl(char *s);
#endif //PUSH_SWAP_BONUS_H
