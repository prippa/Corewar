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

static int		cw_get_arguments_value_ldi(t_command *cmd, t_stack *map, t_processes *process)
{
	if (cmd->codage == REG_REG_REG)
	{
		// ft_printf("REG_REG_REG ldi\n");
		// getchar();
		return ((((process->registers[cmd->arg1.av - 1] + process->registers[cmd->arg2.av - 1]) % IDX_MOD) + process->process_PC));
	}
	else if (cmd->codage == REG_DIR_REG)
	{
		// ft_printf("REG_DIR_REG ldi\n");
		// getchar();
		return ((((process->registers[cmd->arg1.av - 1] + cmd->arg2.av) % IDX_MOD) + process->process_PC));
	}
	else if (cmd->codage == DIR_REG_REG)
	{
		// ft_printf("DIR_REG_REG ldi\n");
		// getchar();
		return ((((cmd->arg1.av + process->registers[cmd->arg2.av - 1]) % IDX_MOD) + process->process_PC));
	}
	else if (cmd->codage == DIR_DIR_REG)
	{
		// ft_printf("DIR_DIR_REG ldi\n");
		// getchar();
		return ((((cmd->arg1.av + cmd->arg2.av) % IDX_MOD) + process->process_PC));
	}
	else if (cmd->codage == IND_REG_REG)
	{
		// ft_printf("IND_REG_REG ldi\n");
		// getchar();
		return ((((cw_get_dec_from_the_point(map->stack, ((cmd->arg1.av % IDX_MOD) + process->process_PC)) + process->registers[cmd->arg2.av - 1]) % IDX_MOD) + process->process_PC));
	}
	else if (cmd->codage == IND_DIR_REG)
	{
		// ft_printf("IND_DIR_REG ldi\n");
		// getchar();
		return ((((cw_get_dec_from_the_point(map->stack, ((cmd->arg1.av % IDX_MOD) + process->process_PC)) + cmd->arg2.av) % IDX_MOD) + process->process_PC));
	}
	return (0);
}

void			cw_ldi(t_command *cmd, t_stack *map, t_processes *proc)
{
	int arg;

	arg = cw_get_arguments_value_ldi(cmd, map, proc);
	proc->registers[cmd->arg3.av - 1] = cw_get_dec_from_the_point(
		map->stack,
		arg
	);


	map->stack_color[proc->process_PC] = proc->color;
	
	
	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));

		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		// cw_display_map(g_cw.map.stack, g_cw.map.stack_color);
	map->stack_color[proc->process_PC] = proc->proc_process_PC_color;
}
