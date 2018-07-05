/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:17:53 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/06 17:23:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define number_for_empty_signal 100

//    Перемещает PC с текущей позиции на T_DIR % IDX_MOD если carry равен 1

void			cw_zjmp(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/) // one is enough maybe;
{
    ft_printf("zjmp\n");

    if (proc->process_PC > 4095 || proc->process_PC < 0)
    {
        ft_printf("zjmp\n");
        ft_printf("PC", proc->process_PC);
        getchar();
    }

	map->stack_color[proc->process_PC] = proc->color;

    // ft_printf("proc_carry -> %d", proc->carry);

    // WTF with proc carry;

    // proc->carry = 1;

    if (proc->carry == 1)
        proc->process_PC = MEM_CORRECTION((proc->process_PC + (IDX_CORRECTION((cmd->arg1.av)))));
    else
        proc->process_PC = MEM_CORRECTION((proc->process_PC + cmd->arg1.tp + 1));
    

    if (proc->process_PC < 0)
    {
        // ft_printf("zjmp before-> %d\n", proc->process_PC);
        // ft_printf("PC -> %d", proc->process_PC);

            // getchar();
        proc->process_PC += MEM_SIZE;
                    // ft_printf("zjmp after -> %d\n", proc->process_PC);
        // ft_printf("PC -> %d", proc->process_PC);
            // getchar();
    
    }
    ft_printf("process_PC -> %d\n", proc->process_PC);



    proc->process_PC = (proc->process_PC < 0 ? MEM_SIZE + proc->process_PC : proc->process_PC);
    
    // ft_printf("proc_PC_in_zjmp -> %d\n", proc->process_PC);

    if (map->stack_color[proc->process_PC] == 0)
    {
        // ft_printf("stack_color jmp == 0 -> %d\n", map->stack_color[proc->process_PC]);

        // ft_putstr("****************************************1\n");
// 
        // ft_printf("stack_color jmp == 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = number_for_empty_signal;

        // ft_printf("stack_color jmp == 0 -> %d\n", map->stack_color[proc->process_PC]);
        
    }
    else if (map->stack_color[proc->process_PC] != 0 && map->stack_color[proc->process_PC] != number_for_empty_signal)
    {
        // ft_putstr("****************************************2\n");
        // ft_printf("stack_color jmp != 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = proc->proc_process_PC_color;

        // ft_printf("stack_color jmp != 0 -> %d\n", map->stack_color[proc->process_PC]);

    }
    if (proc->process_PC > 4095 || proc->process_PC < 0)
    {
        ft_printf("zjmp\n");
        ft_printf("PC -> %d", proc->process_PC);
        getchar();
    }

  // ft_printf("stack_color jmp general -> %d\n", map->stack_color[proc->process_PC]);
//
//    map->stack[proc->process_PC] = 7;
//    map->stack_color[proc->process_PC] = 5;
//
//    cw_display_map(g_cw.map.stack, g_cw.map.stack_color);
}