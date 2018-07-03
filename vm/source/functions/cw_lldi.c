/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:32:01 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 18:32:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_lldi(t_command *cmd, t_stack *map, t_processes *proc)
{
	ft_printf("lldi\n");
	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("lldi\n");
		getchar();
	}

	int arg;

	if (cmd->arg1.tp == 2)
		arg = IDX_CORRECTION(cmd->arg1.av) + cmd->arg2.av + proc->process_PC;
	else
		arg = cmd->arg1.av + cmd->arg2.av + proc->process_PC;
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(
		map->stack,
		4,
		arg
	);
	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0 ? 1 : 0);//carry


	map->stack_color[proc->process_PC] = proc->color;


	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));
	ft_printf("process_PC -> %d\n", proc->process_PC);

	if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("lldi\n");
		getchar();
	}
	// if(map->stack_color[proc->process_PC] != 0)
	    if (map->stack_color[proc->process_PC] == 0)
    {
        ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);

        ft_putstr("****************************************1\n");

        ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = 14;

        ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);
        
    }
    else if (map->stack_color[proc->process_PC] != 0 && map->stack_color[proc->process_PC] != 14)
    {
        ft_putstr("****************************************2\n");
        ft_printf("stack_color lldi != 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = proc->proc_process_PC_color;

        ft_printf("stack_color lldi != 0 -> %d\n", map->stack_color[proc->process_PC]);

    }
	
		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
