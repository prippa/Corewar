/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_binary_and.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:32:08 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 14:32:10 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_and(t_command *cmd, t_processes *proc)
{
	proc->registers[cmd->arg3.av - 1] =
		cw_get_right_arg(proc, cmd->arg1.tp, cmd->arg1.av) &
		cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av);
	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0) ? 1 : 0;
}

static int		cw_get_args_av_and(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RDR || cmd->codage == RIR
		|| cmd->codage == DRR || cmd->codage == DDR || cmd->codage == DIR
		|| cmd->codage == IRR || cmd->codage == IDR || cmd->codage == IIR)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, TRIPLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_binary_and(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, TRIPLE_COMB);
	if (cw_get_args_av_and(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_and(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
