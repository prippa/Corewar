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

void			cw_ldi(t_command *cmd, t_stack *map, t_processes *proc)
{
	int arg;

	if (cmd->arg1.tp == 2)
		arg = IDX_CORRECTION(cmd->arg1.av) + cmd->arg2.av + proc->process_PC;
	else
		arg = IDX_CORRECTION((cmd->arg1.av + cmd->arg2.av)) + proc->process_PC;
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(
		map->stack,
		4,
		arg
	);


	map->stack_color[proc->process_PC] = proc->color;
	
	
	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));
		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
	map->stack_color[proc->process_PC] = proc->proc_process_PC_color;
}
