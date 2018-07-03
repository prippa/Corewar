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
	ft_printf("ldi\n");
	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("ldi\n");
		getchar();
	}
		//

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
	ft_printf("process_PC -> %d\n", proc->process_PC);

	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("ldi\n");
		getchar();
	}
		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
	map->stack_color[proc->process_PC] = proc->proc_process_PC_color;
}
