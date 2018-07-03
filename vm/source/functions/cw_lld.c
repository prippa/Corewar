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
	ft_printf("lld\n");

	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("lld\n");
		getchar();
	}

	if (cmd->arg1.tp == 4)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
		proc->registers[cmd->arg2.av - 1] = cw_get_dec_from_the_point(
			map->stack,
			4,
			proc->process_PC + cmd->arg1.av
		);
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0 ? 1 : 0); // carry

	map->stack_color[proc->process_PC] = proc->color;

	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + 2));

	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("lld\n");
		getchar();
	}

	 map->stack_color[proc->process_PC] = proc->proc_process_PC_color; // !!!!!!!!!!!!!!!!!!!!

		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
