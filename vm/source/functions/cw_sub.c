/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:49 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:51 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// static t_processes	*cw_process_find(int process_id, t_processes *list)
// {
// 	while (list)
// 	{
// 		if (list->id == process_id)
// 			return (list);
// 		list = list->next;
// 	}
// 	return (NULL);
// }

void			cw_sub(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
//	t_processes *proc;
	// int	arguments[3];
	//process;

//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
//	ft_printf("process_id-> %d\n\n", proc->id);

//	ft_printf("proc->registers[cmd->arg1.av - 1]-> %d\n", proc->registers[cmd->arg1.av - 1]);
//	ft_printf("proc->registers[cmd->arg2.av - 1]-> %d\n", proc->registers[cmd->arg2.av - 1]);
	
	proc->registers[cmd->arg3.av - 1] = proc->registers[cmd->arg1.av - 1] - proc->registers[cmd->arg2.av - 1];

//	ft_printf("proc->registers[cmd->arg3.av - 1]-> %d\n", proc->registers[cmd->arg3.av - 1]);

	proc->carry = (proc->registers[cmd->arg3.av - 1] != 0) ? 1 : 0;
	proc->process_PC = BIBA(
		proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2);


	 // for testing;
//	 map->stack[proc->process_PC] = 7;
//	 map->stack_color[proc->process_PC] = 5;
//
//	 ft_printf("process_carry -> %d\n\n", proc->carry);
//
//	  cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
