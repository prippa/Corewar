/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:32:01 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 18:32:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_lldi(t_command *cmd, t_processes *proc)
{
	int				pc;

	if (cmd->codage == IRR || cmd->codage == IDR)
		pc = (proc->pc +
			(cw_get_dec_from_the_point(((cmd->arg1.av % IDX_MOD) + proc->pc), 4)
				+ cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av)));
	else
		pc = (proc->pc + ((cw_get_right_arg(proc, cmd->arg1.tp, cmd->arg1.av))
			+ (cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av))));
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(pc, 4);
	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0) ? 1 : 0;
}

static int		cw_get_args_av_lldi(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RDR || cmd->codage == DRR
		|| cmd->codage == DDR || cmd->codage == IRR || cmd->codage == IDR)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, TRIPLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_lldi(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, TRIPLE_COMB);
	if (cw_get_args_av_lldi(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_lldi(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
