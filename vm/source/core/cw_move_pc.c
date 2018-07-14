/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_move_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:03:00 by prippa            #+#    #+#             */
/*   Updated: 2018/07/14 16:03:01 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_move_pc_with_codage(t_command *cmd, t_processes *proc)
{
	cw_move_pc(proc, (cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));
}

void		cw_move_pc_without_codage(t_processes *proc)
{
	cw_move_pc(proc, (g_cw.op[proc->cmd - 1].label + 1));
}

void		cw_move_pc(t_processes *proc, int value)
{
	if ((proc->pc = MEM_X((proc->pc + value))) < 0)
		proc->pc += MEM_SIZE;
}
