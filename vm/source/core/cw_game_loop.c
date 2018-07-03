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

// 4894 <- write color trouble;
// 5020 <- color if nothing on the map;
// cw_helpers write to map costello;
// replace all constants like 5 or 9 to variable in game loop and zjmp;
// каретка не должна менять цвет если один из процессов остался на том же месте

// если у любого игрока было 21 лайвж
// первый 6 байт + 2ж

#include "corewar.h"

#define	DIR_CHECK(x) (x > 8 && x < 13) || x == 14 || x == 15

	#define test 8000 //5312

static void		ft_zero_it(char *str)
{
	int i;

	i = 0;
	while (i < 8)
		str[i++] = '0';
}

static	int	ft_codage_for_counting(char *str, int cmd)
{
	if (ft_strequ("01", str))
		return (1);
	if (ft_strequ("11", str))
		return (2);
	if (ft_strequ("10", str))
		return ((DIR_CHECK(cmd)) ? 2 : 4);
	return (0);
}

// - get clear with proc carry;

#define	IS_CMD(x) (x >= 1 && x <= 16)

int			cw_move_PC_when_not_correct_cdg(int codage, int cmd) // read first 3 bytes; !!!!!!!!!!!!! amended
{
	int i;
	int j;
	char *binary;
	char *buf_general;
	char	*buf_for_2_bytes;;

	i = 0;
	j = 0;
	if (!(binary = ft_itoa_base(codage, 2, 0)))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	// ft_printf("binary -----------------------------------------------------------------------> %s\n", binary);

	buf_general = ft_strnew(8);

	ft_zero_it(buf_general);
	// ft_printf("buf_general --------------------------------------------------------------------------> %s\n", buf_general);

	ft_strncpy(&buf_general[8 - ft_strlen(binary)], binary, ft_strlen(binary));

	// ft_printf("buf_general --------------------------------------------------------------------------> %s\n", buf_general);

	buf_for_2_bytes = ft_strnew(2);
	buf_for_2_bytes[0] = '0';
	buf_for_2_bytes[1] = '0';

	// ft_printf("cmd -> %d; cmd_arguments -> %d\n", 	cmd, g_cw->op[cmd - 1].arguments_quantity);

	while (j < g_cw->op[cmd - 1].arguments_quantity) // define from the cmd; // not 4;
	{
		if (j == 0)
		{
			ft_strncpy(buf_for_2_bytes, &buf_general[0], 2);
			// ft_printf("asdfasfasfasdfasdfasdfd -> %s\n", buf_for_2_bytes);
		}
		else if (j == 1)
		{
			ft_strncpy(buf_for_2_bytes, &buf_general[2], 2);
			// ft_printf("asdfasfasfasdfasdfasdfd -> %s\n", buf_for_2_bytes);

		}
		else if (j == 2)
		{
			ft_strncpy(buf_for_2_bytes, &buf_general[4], 2);
			// ft_printf("asdfasfasfasdfasdfasdfd -> %s\n", buf_for_2_bytes);

		}
		else if (j == 3)
		{
			ft_strncpy(buf_for_2_bytes, &buf_general[6], 2);
			// ft_printf("asdfasfasfasdfasdfasdfd -> %s\n", buf_for_2_bytes);
		}

		i += ft_codage_for_counting(buf_for_2_bytes, cmd);
		j++;
	}
	i += 2;














	// ft_printf("->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>%d\n", i);
	// read(1,0,1);
	return (i);

}

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
	// ft_printf("command --------------------------- \n");
	// ft_printf("cmd - %u\n", cmd->cmd);
	// ft_printf("codage - %d\n", cmd->codage);
	// ft_printf("arg1.tp - %u\n", cmd->arg1.tp);
	// ft_printf("arg1.av - %d\n", cmd->arg1.av);
	// ft_printf("arg2.tp - %u\n", cmd->arg2.tp);
	// ft_printf("arg2.av - %d\n", cmd->arg2.av);
	// ft_printf("arg3.tp - %u\n", cmd->arg3.tp);
	// ft_printf("arg3.av - %d\n", cmd->arg3.av);
	// ft_printf("-----------------------------------\n");
}

void		cw_execute_corewar_magic(t_processes *proc)
{
	t_command cmd;
	

	// ft_printf("%s\n", "in corwar magic"); // 235 536 184
	// exit(1);
	// getchar();
	// int		cycles = 0;
	while (proc)
	{
		// ft_printf("proc_PC --------------------------------------------------------------------> %d\n", proc->process_PC);
		// ft_printf("id -----------> %d\n", proc->id);
		// ft_printf("cur cmd -----------> %d\n", proc->current_command);
		// ft_printf("color -----------> %d\n", g_cw->map.stack_color[proc->process_PC]);

		ft_bzero(&cmd, sizeof(t_command));


		// cmd.cmd, do not include codage;
		// ft_printf("%s\n", "before get cmd");
		
		// if (proc->process_PC > 4095)
		// {
		// 	ft_printf("proc_id -> %d\n", proc->id);
		// 	ft_printf("PC -> %d\n", proc->process_PC);
		// }
		
		if (cw_get_command(&cmd, proc->process_PC, g_cw->map.stack) ==  NOT_EXIST_CODE && proc->current_command == 0) // if no active command; // adopt here;
		{

				// ft_printf("%s\n", "after get cmd");
// 
				// ft_printf("in -> %d\n", g_cw->map.stack_color[proc->process_PC]);

        		// ft_printf("stack_color not vali -> %d\n", g_cw->map.stack_color[proc->process_PC]);

				// ft_printf("%s\n", "woohoo");




        		if (g_cw->map.stack_color[proc->process_PC ] != 0 && g_cw->map.stack_color[proc->process_PC ] != 14 && g_cw->map.cycle_stack[proc->process_PC] == 0)
					g_cw->map.stack_color[proc->process_PC] = proc->color; //check it;
				else if (g_cw->map.stack_color[proc->process_PC ] == 0 || g_cw->map.stack_color[proc->process_PC ] == 14)
					g_cw->map.stack_color[proc->process_PC] = 14;

				static int zeta;

				if (g_cw->map.stack_color[proc->process_PC] == zeta) // one process_PC is enough maybe;
				{
					// ft_putstr("here\n");
					g_cw->map.stack_color[proc->process_PC] = 9;
				}




				proc->process_PC = MEM_CORRECTION((proc->process_PC + 1));

				if (proc->process_PC > 4095 || proc->process_PC < 0)
				{
					ft_printf("here ->*******************************************1\n");
					getchar();

					// getch();
					// sleep(60);
				}





				if (proc->process_PC != 0 && g_cw->map.stack_color[proc->process_PC - 1] == 14) // one process_PC is enough maybe;
				{
					// ft_putstr("here\n");
					g_cw->map.stack_color[proc->process_PC - 1] = 0;
				}
				else if (proc->process_PC == 0 && g_cw->map.stack_color[MEM_SIZE - 1] == 14)
					g_cw->map.stack_color[MEM_SIZE - 1] = 0;


				if (g_cw->map.stack_color[proc->process_PC ] == 0)
				{
					// g_cw->map.stack_color[proc->process_PC - 1] = 0;
					g_cw->map.stack_color[proc->process_PC] = 14;
				}
				else if (g_cw->map.stack_color[proc->process_PC] != 14 && g_cw->map.stack_color[proc->process_PC] != 0)
				{
					// g_cw->map.stack_color[proc->process_PC - 1] = 0;
					// int color_before = g_cw->map.stack_color[proc->process_PC];


					if (g_cw->map.stack_color[proc->process_PC] == 5)
						zeta = 5;

					// ft_printf("cycle_stack -> %d\n", g_cw->map.cycle_stack[proc->process_PC]);

					// if (g_cw->map.cycle_stack[proc->process_PC] == 0)
						g_cw->map.stack_color[proc->process_PC] = proc->proc_process_PC_color; // цвет кареткиж
				}
				// else


		}
		else
		{

			// cw_print_cmd_specifications(&cmd);

			// decrement the cycles and then execute;

			// ft_bzero(&cmd, sizeof(t_command));

			if (proc->current_command == 0)
			{
				proc->current_command = cmd.cmd;
			}

			// int detect deviation;

			if (proc->current_command != cmd.cmd/* && proc->current_command != 0*/) // 3910
			{
				// ft_printf("\nnot equal\n");
				
				// ft_printf("cur cmd -> %d\n", proc->current_command);
				// ft_printf("cmd cmd -> %d\n", cmd.cmd);

				// ft_printf("cycles done -> %d\n", proc->cycles_till_execution);
				// ft_printf("necessary cycles -> %d\n", g_cw->op[proc->current_command - 1].cycles_price);
				// ft_printf("PC -> %d\n", proc->process_PC);
				// ft_printf("proc id -> %d\n", proc->process_PC);

				proc->detect_deviation = 1;
				
				// exit (0); // -> show the first deviation;
			}


			if (proc->detect_deviation == 0)
			{

				if (proc->cycles_till_execution < g_cw->op[cmd.cmd - 1].cycles_price) // keep the current comman
				{
					// ft_printf("till exec normal -> %d\n", proc->cycles_till_execution);
					// ft_printf("process_PC_normal -> %d\n", proc->process_PC);

					proc->cycles_till_execution++;
				}
				else
				{
					// ft_printf("execute\n");
					// ft_printf("here ->*******************************************2\n");
					// getchar();

					if (!cw_get_command(&cmd, proc->process_PC, g_cw->map.stack))
					{
						g_cw->op[cmd.cmd - 1].func(&cmd, &g_cw->map, proc);
						proc->current_command = 0;
						proc->cycles_till_execution = 1;
					}
					else
					{
						// ft_printf("not valid codage -------------------------------> %d\n", cmd.codage);
						
						g_cw->map.stack_color[proc->process_PC] = proc->color;

						proc->process_PC = MEM_CORRECTION((proc->process_PC + cw_move_PC_when_not_correct_cdg(cmd.codage, cmd.cmd)));

				if (proc->process_PC > 4095 || proc->process_PC < 0)
				{
					ft_printf("here ->*******************************************3\n");
					getchar();

						// sleep(60);
					// ft_printf("here ->2\n");
				}

						if (g_cw->map.stack_color[proc->process_PC] != 0 && g_cw->map.stack_color[proc->process_PC] != 14)
    						g_cw->map.stack_color[proc->process_PC] = proc->proc_process_PC_color;
    					else
    						g_cw->map.stack_color[proc->process_PC] = 14;

    					proc->cycles_till_execution = 1;

						proc->current_command = 0;


						//colors


					}
				}
			}
			else if (proc->detect_deviation == 1)
			{
				
				ft_bzero(&cmd, sizeof(t_command));

				if (proc->cycles_till_execution < g_cw->op[proc->current_command - 1].cycles_price) // keep the current comman
				{
// 
					// ft_printf("till exec dev-> %d\n", proc->cycles_till_execution);
					// ft_printf("process_PC_dev -> %d\n", proc->process_PC);

// 
					proc->cycles_till_execution++;
				}
				else
				{
					// ft_printf("execute\n");

					// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);

					if (!cw_get_command_2(&cmd, proc->process_PC, g_cw->map.stack, proc->current_command))
					{
						g_cw->op[proc->current_command - 1].func(&cmd, &g_cw->map, proc);
						proc->current_command = 0;
						proc->detect_deviation = 0;
						proc->cycles_till_execution = 1;
					}
					else
					{
						// ft_printf("not valid codage -------------------------------> %d\n", "123456");//////////// ?
					// ft_printf("here ->*******************************************4\n");
					// getchar();

						cw_get_command(&cmd, proc->process_PC, g_cw->map.stack); // to have the cmd.codage actual on the map; /////////////////// ?

						g_cw->map.stack_color[proc->process_PC] = proc->color;

						proc->process_PC += cw_move_PC_when_not_correct_cdg(cmd.codage, proc->current_command);


				if (proc->process_PC > 4095 || proc->process_PC < 0)
				{
					ft_printf("here ->*******************************************5\n");
				getchar();
						// sleep(60);
					// ft_printf("here ->3\n");
				}

						if (g_cw->map.stack_color[proc->process_PC] != 0 && g_cw->map.stack_color[proc->process_PC] != 14)
    						g_cw->map.stack_color[proc->process_PC] = proc->proc_process_PC_color;
    					else
    						g_cw->map.stack_color[proc->process_PC] = 14;

    					proc->cycles_till_execution = 1;

						proc->current_command = 0;


						//colors


					}
					// else
					// 	ft_printf("not valid codage -> %d", NOT_CORRECT_CODAGE);
					// exit (0); // -> show the first deviation;
				}
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

void cw_display_map_write(unsigned int *map)
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	read(1, 0, 1); // this stuff may help with visualization;
	system("clear"); // this stuff may help with visualization;

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%~.2d", F_WHITE, map[i]);
		ft_printf(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = -1;
		}
		lines++;
		spaces++;
		i++;
	}
}

void	cw_decrementor(unsigned int *write_to_the_map_stack, int *stack_color, unsigned int *cycle_stack) // for 50 cycles;
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (write_to_the_map_stack[i] != 0)
		{
			if (write_to_the_map_stack[i] == 9 && cycle_stack[i] == 0 && stack_color[i] != 5)
			{
				stack_color[i] = 1;
				write_to_the_map_stack[i] = 0;
			}
			else if (write_to_the_map_stack[i] == 10 && cycle_stack[i] == 0 && stack_color[i] != 6)
			{
				stack_color[i] = 2;
				write_to_the_map_stack[i] = 0;
			}
			else if (write_to_the_map_stack[i] == 11 && cycle_stack[i] == 0 && stack_color[i] != 7)
			{
				stack_color[i] = 3;
				write_to_the_map_stack[i] = 0;
			}
			else if (write_to_the_map_stack[i] == 12 && cycle_stack[i] == 0 && stack_color[i] != 8)
			{
				stack_color[i] = 4;
				write_to_the_map_stack[i] = 0;
			}
			else
				write_to_the_map_stack[i]--;
		}
		if (cycle_stack[i] != 0)
			cycle_stack[i]--;
		i++;
	}
}


void		cw_game_loop(void)
{
	cw_color_start(g_cw->proc_start, &g_cw->map);
	
	// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);

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

	// how many cycles live is active

	// 3791


	// 4509 ob

	// 4566 ?


	#define CYCLES 100000

	// #define test 5303







	// 4570;

	while (g_cw->cycle < CYCLES)
	{
		// if (g_cw->cycle == 26689)
		// {
			
		// }

		ft_printf("\n******************************************\ncycle_main -> %d\n******************************************\n", g_cw->cycle);
		// ft_printf("processes -> %d\n", g_cw->proc_counter);

		// GAME EDN IF PERIODS OF CYCLE_TO_DIE IS OWER !
		if (g_cw->cycle_to_die <= 0)
			return ;

		cw_execute_corewar_magic(g_cw->proc_start);


		cw_decrementor(g_cw->map.write_to_the_map_stack, g_cw->map.stack_color, g_cw->map.cycle_stack);

		if (g_cw->cycle >= test)
		{
			exit(0);
			cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
			// cw_display_map_write(g_cw->map.stack_color);
		}
		
		// FLAG -dump in work
		if (g_cw->pd.flags[DUMP] && g_cw->cycle == g_cw->pd.dump_stop)
			cw_print_dump_exit();
		
		// New Period!
		if (!g_cw->cycle_to_die_check)
			cw_cycles_new_period();
		
		// GAME END IF ALL PROCESSES IS DEAD !
		if (g_cw->proc_counter == 0)
			return ;

		g_cw->cycle++;
		g_cw->cycle_to_die_check--;
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
