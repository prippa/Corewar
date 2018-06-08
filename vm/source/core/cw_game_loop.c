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

void		cw_do_smth(t_processes *proc)
{
	t_command cmd;

	// process status: finding the right command; activated; waiting for the execution;

	// parallel actions -> find the command, waiting for the command execution, decrementation of the command till execution;

	// += to cycles when;
	// - cycles = arr[live];

	// add: cycles till execution decrementation;
	// command detection
	
	while (proc)
	{
		ft_printf("proc_id -> %d\n", proc->id);

		g_cw->i = proc->process_PC; // what if g_cw->i is 4095, think about it )))))))))))

		cw_get_command(&cmd, &g_cw->i, g_cw->map.stack); // TODO do not move the map with i;


		ft_printf("command --------------------------- \n");
		ft_printf("cmd - %u\n", cmd.cmd);
		ft_printf("codage - %d\n", cmd.codage);
		ft_printf("arg1.tp - %u\n", cmd.arg1.tp);
		ft_printf("arg1.av - %d\n", cmd.arg1.av);
		ft_printf("arg2.tp - %u\n", cmd.arg2.tp);
		ft_printf("arg2.av - %d\n", cmd.arg2.av);
		ft_printf("arg3.tp - %u\n", cmd.arg3.tp);
		ft_printf("arg3.av - %d\n", cmd.arg3.av);
		ft_printf("-----------------------------------\n");


		ft_bzero(&cmd, sizeof(t_command));

		proc = proc->next;
	}
}

void		cw_game_loop(void)
{
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

	#define CYCLES 20



		while (global_iterator < CYCLES)
		{
			cw_do_smth(g_cw->proc_start);
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
