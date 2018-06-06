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

void			cw_lld(t_command *cmd, t_stack *map, t_processes *proc)
{
	if (cmd->arg1.tp == 4)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
	{
		BOBA(cmd->arg1.av);
		proc->registers[cmd->arg2.av - 1] =
		cw_get_dec_from_the_point(map->stack, 4,
		proc->process_PC + cmd->arg1.av);
		proc->process_PC += cmd->arg1.tp + cmd->arg2.tp + 2;
		BIBA(proc->process_PC);
	}
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0 ? 1 : 0); // carry
}
