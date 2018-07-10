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

void		cw_print_map(void) // TRASH
{
	int i;
	int new_line_flag;

	read(1, 0, 1);
	system("clear");
	i = 0;
	new_line_flag = 1;
	ft_putstr("\n\n   ");
	while (i < MEM_SIZE)
	{
		ft_printf("%~.2x ", g_cw.color_map[i], g_cw.map[i]);
		if (new_line_flag == CW_BIT)
		{
			ft_putstr("\n   ");
			new_line_flag = 1;
		}
		else
			new_line_flag++;
		i++;
	}
}

static void		cw_cycles_new_period(void)
{
	g_cw.max_checks_check--;
	if (t_champ_get_lives_number(g_cw.pd.champs) >= NBR_LIVE
		|| g_cw.max_checks_check == 0)
	{
		g_cw.cycle_to_die -= CYCLE_DELTA;
		g_cw.max_checks_check = MAX_CHECKS;
	}
	g_cw.cycle_to_die_check = g_cw.cycle_to_die;
	t_champ_zero_lives_number(g_cw.pd.champs);
	t_processe_killer(g_cw.pd.champs);
}

static void		cw_execute_function(t_processes *proc_start)
{
	g_cw.op[proc_start->cmd - 1].func(proc_start);
	if (IS_COMMAND(g_cw.map[proc_start->pc]))
		cw_init_proc_cmd(proc_start, g_cw.map[proc_start->pc]);
	else
		proc_start->exec_cycles = -1;
}

static void		cw_proc_executer(t_processes *proc_start)
{
	char cmd;

	while (proc_start)
	{
		cmd = g_cw.map[proc_start->pc];
		if (IS_COMMAND(cmd))
		{
			if (proc_start->exec_cycles == -1)
				cw_init_proc_cmd(proc_start, cmd);
			else if (!proc_start->exec_cycles)
				cw_execute_function(proc_start);
			else
				proc_start->exec_cycles--;
		}
		else
			proc_start->pc = MEM_X((proc_start->pc + 1));
		proc_start = proc_start->next;
	}
}

void			cw_game_loop(void)
{
	t_champ *champs;

	while (1)
	{
		// if (g_cw.cycle == 2831)
		// {

		// }
		if (g_cw.cycle_to_die <= 0)
			break ;
		champs = g_cw.pd.champs;
		while (champs)
		{
			cw_proc_executer(champs->proc_start);
			champs = champs->next;
		}
		if (g_cw.pd.flags[DUMP] && g_cw.cycle == g_cw.pd.dump_stop)
			cw_print_dump_exit();
		if (!g_cw.cycle_to_die_check)
			cw_cycles_new_period();
		if (g_cw.proc_counter == 0)
			break ;
		if (g_cw.cycle >= 11000)
		{
			cw_refresh_colors();
			cw_print_map(); // TRASH
			ft_printf("\n************\nCycle: %u\n************\n", g_cw.cycle);
			ft_printf("proc count: %u\n", g_cw.proc_counter);
			ft_printf("cycle to die: %d\n", g_cw.cycle_to_die);
		}
		g_cw.cycle++;
		g_cw.cycle_to_die_check--;
	}
}
