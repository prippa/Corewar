/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:11:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/06 16:49:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//todo delete all comments;

// Выполняет 2 операции:
//1. Засчитывает, что процесс (который выполняет данную команду) жив.
//2. Засчитывает, что жив номер (если этот номер совпадает с номером игрока, то засчитвает, что этот игрок жив), который заходит как аргумент (T_DIR).
// we take the next live process in the linked list of processes;

void			cw_live(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
	// ft_printf("proc id --------------------> %d\n", proc->id);
	// ft_printf("proc_PC -----------> %d\n", proc->process_PC);
	// ft_printf("cur cmd -----------> %d\n", proc->current_command);
	// ft_printf("till_execution ----> %d\n", proc->cycles_till_execution);
	// ft_printf("color ----> %d\n", g_cw.map.stack_color[proc->process_PC]);

	t_champ *champ;

//   proc = t_processe_get_by_id(g_cw.proc_start, g_cw.proc_end, process_id);

	proc->has_been_activated = ALIVE; // maybe for testing we can use += live, will see;

	champ = t_champ_find(cmd->arg1.av, g_cw.pd.champs);

	// ft_printf("here live\n");


	// maybe we have segfault here; who knows :)

	if (champ)
	{
		champ->lives_number += ALIVE;
		champ->last_live = g_cw.cycle + 1;
	}

	// ft_printf("here after\n");

	// ft_printf("champ_number -> %d\n", champ->champ_number);
	// ft_printf("champ_number -> %u\n", champ->lives_number);

	// here
	if (champ)
	{
		map->stack_color[proc->process_PC] = proc->live_color; // write to the 50 cycles;
		map->write_to_the_map_stack[proc->process_PC] = proc->live_color + 50; // -> 59;
		map->cycle_stack[proc->process_PC] = 50; // -
	}
	else
		map->stack_color[proc->process_PC] = proc->color; // write to the 50 cycles;


	// ft_printf("live_color -> %d\n", map->stack_color[proc->process_PC]);

	proc->process_PC = MEM_CORRECTION((proc->process_PC + cmd->arg1.tp + 1));
	
	// ft_printf("process_PC -> %d\n", proc->process_PC);


//	 for testing;
//	 map->stack[proc->process_PC] = 7;
	 map->stack_color[proc->process_PC] = proc->proc_process_PC_color; // move the color of the PC;
//
//	 cw_display_map(g_cw.map.stack, g_cw.map.stack_color);



}