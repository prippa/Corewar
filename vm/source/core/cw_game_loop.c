/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:28:33 by prippa            #+#    #+#             */
/*   Updated: 2018/06/07 15:17:13 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// - get clear with proc carry;

#define	IS_CMD(x) (x >= 1 && x <= 16)

void		cw_color_start(t_processes *proc, t_stack *map)
{
	while (proc)
	{
		map->stack_color[proc->process_PC] = proc->proc_process_PC_color;
		proc = proc->next;
	}
}

void		cw_print_cmd_specifications(t_command *cmd)
{
	ft_printf("command --------------------------- \n");
	ft_printf("cmd - %u\n", cmd->cmd);
	ft_printf("codage - %d\n", cmd->codage);
	ft_printf("arg1.tp - %u\n", cmd->arg1.tp);
	ft_printf("arg1.av - %d\n", cmd->arg1.av);
	ft_printf("arg2.tp - %u\n", cmd->arg2.tp);
	ft_printf("arg2.av - %d\n", cmd->arg2.av);
	ft_printf("arg3.tp - %u\n", cmd->arg3.tp);
	ft_printf("arg3.av - %d\n", cmd->arg3.av);
	ft_printf("-----------------------------------\n");
}

void		cw_execute_corewar_magic(t_processes *proc)
{
	t_command cmd;

	
	// int		cycles = 0;
	while (proc)
	{
		// ft_printf("proc_id -> %d\n", proc->id);
		ft_bzero(&cmd, sizeof(t_command));

		if (cw_get_command(&cmd, proc->process_PC, g_cw->map.stack))
		{
			g_cw->map.stack_color[proc->process_PC] = proc->color;

			proc->process_PC += 1;

			g_cw->map.stack_color[proc->process_PC] = proc->proc_process_PC_color; // modify with func according to tha current proc color;
		}
		else
		{
			// ft_printf("true\n");

			// cw_print_cmd_specifications(&cmd);

			// decrement the cycles and then execute;

			if (proc->cycles_till_execution < g_cw->op[cmd.cmd - 1].cycles_price)
			{
				// ft_printf("till exec -> %d\n", proc->cycles_till_execution);

				proc->cycles_till_execution++;
			}
			else if (!cw_get_command(&cmd, proc->process_PC, g_cw->map.stack))
			{
				g_cw->op[cmd.cmd - 1].func(&cmd, &g_cw->map, proc);

				proc->cycles_till_execution = 1;
			}
			// else if (proc->cycles_till_execution != 0 && proc->cycles_till_execution != 1001)
			// 	proc->cycles_till_execution--;


			// if (proc->cycles_till_execution == 0)


		}

		// ft_bzero(&cmd, sizeof(t_command));

		// ft_printf("proc_PC -> %d", proc->process_PC);

		proc = proc->next;
	}
}



void		cw_game_loop(void)
{
	cw_color_start(g_cw->proc_start, &g_cw->map);
	
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);

	// while (g_cw->loop)
	// {
		
	// }
	// int tmp = 1;

	
	// ft_printf("before while -> %d\n",g_cw->i);
	
	// while (g_cw->i < MEM_SIZE) // add the action when the var is 4096;
	// {
	// 	// ft_printf("in while i -> %d\n",g_cw->i);
		
	// 	if ((cw_get_command(&cmd, g_cw->i, g_cw->map.stack)))
	// 	{
	// 		// ft_printf("after codage i -> %d\n", g_cw->i);
	// 		g_cw->i++;
	// 		// to the next position after the cmp function;
	// 		continue;
	// 	}

	int global_iterator = 0;

	#define CYCLES 100

	while (global_iterator < CYCLES)
	{
		ft_printf("cycle -> %d\n", global_iterator);

		cw_execute_corewar_magic(g_cw->proc_start);

		if (global_iterator == CYCLES - 1)
			cw_display_map(g_cw->map.stack, g_cw->map.stack_color);

		global_iterator++;
	}

//     cw_add(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
//     cw_sub(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
//     cw_binary_and(&cmd, &g_cw->map, g_cw->proc_start); // o.k
//     cw_binary_or(&cmd, &g_cw->map,  g_cw->proc_start); // o.k.
//     cw_binary_xor(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
    //  cw_sti(&cmd, &g_cw->map, g_cw->proc_start); // o.k.
		// cw_ld(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_lld(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_ldi(&cmd, &g_cw->map, g_cw->proc_start);
//		cw_lldi(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_zjmp(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_aff(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_st(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_fork(&cmd, &g_cw->map, g_cw->proc_start);
		// cw_lfork(&cmd, &g_cw->map, g_cw->proc_start);

		  //  while (g_cw->proc_start)
    // {
    //     ft_printf("id      -> %u\n", g_cw->proc_start->id);
    //     ft_printf("color   -> %d\n", g_cw->proc_start->color);
    //     ft_printf("proc_PC -> %d\n", g_cw->proc_start->process_PC);
    //     ft_printf("carry   -> %d\n", g_cw->proc_start->carry);
    //     ft_printf("cycles  -> %d\n", g_cw->proc_start->cycles_till_execution);

    //     int d = 0;
    //     while (d < 16)
    //         ft_printf("%d ", g_cw->proc_start->registers[d++]);
    //     ft_printf("\n");



    //     g_cw->proc_start = g_cw->proc_start->next;
    // }



    // tmp++;
	// }
}
