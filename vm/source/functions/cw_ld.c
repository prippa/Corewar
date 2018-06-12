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

void			cw_ld(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
//	t_processes *proc;

//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
	if (cmd->arg1.tp == 4)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
	{
		cmd->arg1.av = IDX_CORRECTION(cmd->arg1.av);
		proc->registers[cmd->arg2.av - 1] = cw_get_dec_from_the_point(
			map->stack,
			4,
			proc->process_PC + cmd->arg1.av
		);
	}
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0 ? 1 : 0); // carry


	map->stack_color[proc->process_PC] = proc->color;
	
	
	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + 2));
		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
