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

static int		cw_get_arguments_value_lldi(t_command *cmd, t_stack *map, t_processes *process)
{
	if (cmd->codage == REG_REG_REG)
		return ((((process->registers[cmd->arg1.av - 1] + process->registers[cmd->arg2.av - 1])) + process->process_PC));
	else if (cmd->codage == REG_DIR_REG)
		return ((((process->registers[cmd->arg1.av - 1] + cmd->arg2.av)) + process->process_PC));
	else if (cmd->codage == DIR_REG_REG)
		return ((((cmd->arg1.av + process->registers[cmd->arg2.av - 1])) + process->process_PC));
	else if (cmd->codage == DIR_DIR_REG)
		return ((((cmd->arg1.av + cmd->arg2.av)) + process->process_PC));
	else if (cmd->codage == IND_REG_REG)
		return ((((cw_get_dec_from_the_point(map->stack, ((cmd->arg1.av % IDX_MOD) + process->process_PC)) + process->registers[cmd->arg2.av - 1])) + process->process_PC));
	else if (cmd->codage == IND_DIR_REG)
		return ((((cw_get_dec_from_the_point(map->stack, ((cmd->arg1.av % IDX_MOD) + process->process_PC)) + cmd->arg2.av)) + process->process_PC));
	return (0);
}

void			cw_lldi(t_command *cmd, t_stack *map, t_processes *proc)
{
	// if (proc->id == 20)
	// {	
		// ft_printf("lldi reg -> %d, ", proc->registers[cmd->arg3.av - 1]);
		// ft_printf("carry -> %d\n", proc->carry);
	exit(0);
	// }
	int arg;

	arg = cw_get_arguments_value_lldi(cmd, map, proc);
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(
		map->stack,
		arg
	);
	proc->carry = (proc->registers[cmd->arg3.av - 1] == 0 ? 1 : 0);//carry


    if (map->cycle_stack[proc->process_PC] == 0)
        map->stack_color[proc->process_PC] = proc->color;
	// map->stack_color[proc->process_PC] = proc->color;


	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));

	// if(map->stack_color[proc->process_PC] != 0)
	if (map->stack_color[proc->process_PC] == 0)
    {
        // ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);

        // ft_putstr("****************************************1\n");

        // ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = number_for_empty_signal; /// do something with i

        // ft_printf("stack_color lldi == 0 -> %d\n", map->stack_color[proc->process_PC]);
        
    }
    else if (map->stack_color[proc->process_PC] != 0 && map->stack_color[proc->process_PC] != number_for_empty_signal)
    {
        // ft_putstr("****************************************2\n");
        // ft_printf("stack_color lldi != 0 -> %d\n", map->stack_color[proc->process_PC]);

        map->stack_color[proc->process_PC] = proc->proc_process_PC_color;

        // ft_printf("stack_color lldi != 0 -> %d\n", map->stack_color[proc->process_PC]);

    }
		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw.map.stack, g_cw.map.stack_color);
}
