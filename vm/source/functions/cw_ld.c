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

int				cw_read_command_ld(t_command *cmd, t_processes *proc)
{
	proc->pc = MEM_X((proc->pc + 1));
	cmd->codage = g_cw.map[proc->pc];
	cw_set_arg_tp(cmd, g_cw.op[proc->cmd - 1].label);
}

void			cw_ld(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	if (cw_read_command_ld(&cmd, proc) != 0)
	{

	}
	proc->pc = MEM_X(proc->pc + cmd.arg1.tp + cmd.arg2.tp + g_cw.op[proc->cmd - 1].codage_octal + 1);
}
