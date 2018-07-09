/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:40 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_add(t_command *cmd, t_processes *proc)
{
	proc->registers[cmd->arg3.av - 1] =
		proc->registers[cmd->arg1.av - 1] + proc->registers[cmd->arg2.av - 1];
	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0) ? 1 : 0;
}

static int		cw_get_args_av_add(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP);
	else
		return (0);
	return (1);
}

void			cw_add(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cw_get_codage_and_arg_tp(&cmd, proc);
	if (cw_get_args_av_add(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_add(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
