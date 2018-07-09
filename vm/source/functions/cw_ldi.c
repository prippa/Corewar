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

static int		cw_get_pc_of_arg1_arg2_ldi(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR)
		return (proc->pc + ((proc->registers[cmd->arg1.av - 1]
			+ proc->registers[cmd->arg2.av - 1]) % IDX_MOD));
	else if (cmd->codage == RDR)
		return (proc->pc + ((proc->registers[cmd->arg1.av - 1]
			+ cmd->arg2.av) % IDX_MOD));
	else if (cmd->codage == DRR)
		return (proc->pc + ((cmd->arg1.av
			+ proc->registers[cmd->arg2.av - 1]) % IDX_MOD));
	else if (cmd->codage == DDR)
		return (proc->pc + ((cmd->arg1.av
			+ cmd->arg2.av) % IDX_MOD));
	else if (cmd->codage == IRR)
		return (proc->pc + (
			(cw_get_dec_from_the_point(((cmd->arg1.av % IDX_MOD) + proc->pc), 4)
				+ proc->registers[cmd->arg2.av - 1]) % IDX_MOD));
	else if (cmd->codage == IDR)
		return (proc->pc + (
			(cw_get_dec_from_the_point(((cmd->arg1.av % IDX_MOD) + proc->pc), 4)
				+ cmd->arg2.av) % IDX_MOD));
	return (0);
}

static void		cw_execute_ldi(t_command *cmd, t_processes *proc)
{
	int				pc;

	pc = cw_get_pc_of_arg1_arg2_ldi(cmd, proc);
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(pc, 4);
}

static int		cw_get_args_av_ldi(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RRD || cmd->codage == RDR
		|| cmd->codage == RDD || cmd->codage == RIR || cmd->codage == RID)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP);
	else
		return (0);
	return (1);
}

void			cw_ldi(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cw_get_codage_and_arg_tp(&cmd, proc);
	if (cw_get_args_av_ldi(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_ldi(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
