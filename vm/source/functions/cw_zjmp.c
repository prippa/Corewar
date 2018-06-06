/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:17:53 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/06 16:52:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//    Перемещает PC с текущей позиции на T_DIR % IDX_MOD если carry равен 1

void			cw_zjmp(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
    if (proc->carry == 1)
        proc->process_PC = MEM_CORRECTION(proc->process_PC + IDX_CORRECTION(cmd->arg1.av));
    else
        proc->process_PC = MEM_CORRECTION(proc->process_PC + IDX_CORRECTION(cmd->arg1.av));

//
//    map->stack[proc->process_PC] = 7;
//    map->stack_color[proc->process_PC] = 5;
//
//    cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}