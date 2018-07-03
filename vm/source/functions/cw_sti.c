/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:34:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/07 15:31:00 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
// TODO delete all comments

int		cw_arguments_value(t_command *cmd, t_stack *map, t_processes *process) // -1 for registers; // TODO use IDX_CORRECTION for IDX_MOD
{
	if (cmd->codage == 100) // o.k
		return (process->process_PC + (cmd->arg2.av + process->registers[cmd->arg3.av - 1]) % IDX_MOD);
	else if (cmd->codage == 116) // o.k
	{
		// ft_printf("IND -> %d\n", cmd->arg2.av % IDX_MOD);
		return (process->process_PC + (cw_get_dec_from_the_point(map->stack, 4, cmd->arg2.av % IDX_MOD) + process->registers[cmd->arg3.av - 1]) % IDX_MOD);
	}
	else if (cmd->codage == 84) // o.k.
	{
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg2.av - 1]);
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg3.av - 1]);
		// ft_printf("res -> %d\n", ((process->registers[cmd->arg2.av - 1] + (process->process_PC + 1) + process->registers[cmd->arg3.av - 1]) % IDX_MOD));
		return (process->process_PC + (process->registers[cmd->arg2.av - 1] + process->registers[cmd->arg3.av - 1]) % IDX_MOD);
	}
	else if (cmd->codage == 104) // o.k



		return (process->process_PC + (cmd->arg2.av + cmd->arg3.av) % IDX_MOD);





	else if (cmd->codage == 120) // o.k.
		return (process->process_PC + (cw_get_dec_from_the_point(map->stack, 4,cmd->arg2.av % IDX_MOD) + cmd->arg3.av) % IDX_MOD); // %idx_mod

	else if (cmd->codage == 88) // o.k




		return (process->process_PC + (process->registers[cmd->arg2.av - 1]  + cmd->arg3.av) % IDX_MOD);
	return (0);
}

// bold green;

void			cw_sti(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
		ft_printf("sti\n");
			if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("sti\n");
			getchar();
	}

	unsigned char	buf[4];
	// int i;
	int				position_on_the_map;
//	t_processes *proc;
	// int	arguments[3];
	//process;
//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);

	if ((position_on_the_map = MEM_CORRECTION(cw_arguments_value(cmd, map, proc))) < 0)
		position_on_the_map += MEM_SIZE;

	ft_printf("position-> %d\n", cw_arguments_value(cmd, map, proc));

	cw_write_bytes_to_buf(buf, proc->registers[cmd->arg1.av - 1]);

	ft_printf("1 -> %d\n", proc->registers[cmd->arg1.av - 1]);
	ft_printf("2 -> %d\n", cmd->arg2.av);
	ft_printf("3 -> %d\n", cmd->arg3.av);

	// 
//	position_on_the_map +// to func;

	 ft_printf("position_on_the_map -> %d\n", position_on_the_map);
	 
	 ft_printf("process_PC -> %d\n", proc->process_PC);



	map->stack_color[proc->process_PC] = proc->color;


	proc->process_PC = MEM_CORRECTION(
		(proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));

			if (proc->process_PC > 4095 || proc->process_PC < 0)
	{
		ft_printf("sti\n");
			getchar();
	}

	map->stack_color[proc->process_PC] = proc->proc_process_PC_color; // !!!!!!!!!!!!!!!!!!!!
	
	ft_printf("process_PC -> %d\n", proc->proc_process_PC_color);

	// (cmd->arg2.tp == 2) ? proc->process_PC += 1 : 0;
	// (cmd->arg2.tp == 1) ? proc->process_PC += 2 : 0;
	// (cmd->arg2.tp == 2 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;
	// (cmd->arg2.tp == 4 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;


	// move the process_PC by the quantity of bytes;


	// process id // process parent;
	// get clear with it;
	// it will be found by the color ?;

	// process id in order to find the correct process;

	// ft_printf("%d", ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD));
	// position_on_the_map = 15;

	// i = 0; // argument type variation;
	// i = 0;
		// ft_printf("position_on_the_map -> %d\n", position_on_the_map);
	cw_write_to_map(map, proc, buf, position_on_the_map);
// 	while (i < 4) // 2 || 4; // always take 4 bytes to the map;
// 	{
// 		if (position_on_the_map == MEM_SIZE)
// 			position_on_the_map = 0;
// 		// ft_printf("position_on_the_map -> %d", position_on_the_map);
		
// 		map->stack[position_on_the_map] = buf[i++];
// 		map->stack_color[position_on_the_map++] = proc->color;
// //		map->stack_process_id[position_on_the_map++] = proc->id;
// 	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// each process has the color of the parent;

//	 for testing;
	 // map->stack[proc->process_PC] = 7;
	 // map->stack_color[proc->process_PC] = 5;

	// TODO read(1, 0, 1);

	 // cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
