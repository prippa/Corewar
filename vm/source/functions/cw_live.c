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

 static t_champ	*cw_champ_find(int champ_number, t_champ *list)
 {
 	while (list)
 	{
 		if (list->champ_number == champ_number)
 			return (list);
 		list = list->next;
 	}
 	return (NULL);
 }

void			cw_live(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
    t_champ *champ;
//
//   proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
    proc->has_been_activated = ALIVE; // maybe for testing we can use += live, will see;

    champ = cw_champ_find(cmd->arg1.av, g_cw->pd.champs);

    if (champ)
    // {
    	champ->lives_number += ALIVE;
	// }


    // ft_printf("champ_number -> %d\n", champ->champ_number);
    // ft_printf("champ_number -> %u\n", champ->lives_number);
    map->stack_color[proc->process_PC] = proc->color;

    proc->process_PC = MEM_CORRECTION(proc->process_PC + cmd->arg1.tp + 1);

//	 for testing;
//	 map->stack[proc->process_PC] = 7;
	 map->stack_color[proc->process_PC] = proc->proc_process_PC_color; // !!!!!!!!!!!!!!!!!!!!
//
//	 cw_display_map(g_cw->map.stack, g_cw->map.stack_color);



}