/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:25:29 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 12:25:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_ld(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == DR)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else if (cmd->codage == IR)
		proc->registers[cmd->arg2.av - 1] = cw_get_dec_from_the_point(
			(proc->pc + IDX_X(cmd->arg1.av)),
			g_cw.op[proc->cmd - 1].label
		);
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0) ? 1 : 0;
}

static int		cw_get_args_av_ld(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == DR || cmd->codage == IR)
		cw_set_arg_av(cmd, proc);
	else
		return (0);
	return (1);
}

void			cw_ld(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cw_get_codage_and_arg_tp(&cmd, proc);
	if (cw_get_args_av_ld(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_ld(&cmd, proc);
}
