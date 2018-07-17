/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:16:50 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 13:16:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_lld(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == DR)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else if (cmd->codage == IR)
		proc->registers[cmd->arg2.av - 1] = cw_get_dec_from_the_point(
			(proc->pc + cmd->arg1.av),
			g_cw.op[proc->cmd - 1].label);
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0) ? 1 : 0;
}

static int		cw_get_args_av_lld(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == DR || cmd->codage == IR)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, DOUBLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_lld(t_processes *proc)
{
	t_command	cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.mp.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, DOUBLE_COMB);
	if (cw_get_args_av_lld(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_lld(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
