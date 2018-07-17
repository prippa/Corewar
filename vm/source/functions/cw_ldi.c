/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:31:53 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 18:31:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_ldi(t_command *cmd, t_processes *proc)
{
	int				pc;

	if (cmd->codage == IRR || cmd->codage == IDR)
		pc = (proc->pc + IDX_X(
			((cw_get_dec_from_the_point((IDX_X(cmd->arg1.av) + proc->pc), 4))
				+ (cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av)))));
	else
		pc = (proc->pc + IDX_X(
			((cw_get_right_arg(proc, cmd->arg1.tp, cmd->arg1.av))
				+ (cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av)))));
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(pc, 4);
}

static int		cw_get_args_av_ldi(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RDR || cmd->codage == DRR
		|| cmd->codage == DDR || cmd->codage == IRR || cmd->codage == IDR)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, TRIPLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_ldi(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.mp.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, TRIPLE_COMB);
	if (cw_get_args_av_ldi(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_ldi(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
