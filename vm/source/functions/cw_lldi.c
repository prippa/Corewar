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

static int		cw_get_pc_of_arg1_arg2_lldi(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR)
		return (proc->pc + (proc->registers[cmd->arg1.av - 1]
			+ proc->registers[cmd->arg2.av - 1]));
	else if (cmd->codage == RDR)
		return (proc->pc + (proc->registers[cmd->arg1.av - 1]
			+ cmd->arg2.av));
	else if (cmd->codage == DRR)
		return (proc->pc + (cmd->arg1.av
			+ proc->registers[cmd->arg2.av - 1]));
	else if (cmd->codage == DDR)
		return (proc->pc + (cmd->arg1.av
			+ cmd->arg2.av));
	else if (cmd->codage == IRR)
		return (proc->pc +
			(cw_get_dec_from_the_point(((cmd->arg1.av % IDX_MOD) + proc->pc), 4)
				+ proc->registers[cmd->arg2.av - 1]));
	else if (cmd->codage == IDR)
		return (proc->pc +
			(cw_get_dec_from_the_point(((cmd->arg1.av % IDX_MOD) + proc->pc), 4)
				+ cmd->arg2.av));
	return (0);
}

static void		cw_execute_lldi(t_command *cmd, t_processes *proc)
{
	int				pc;

	pc = cw_get_pc_of_arg1_arg2_lldi(cmd, proc);
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
