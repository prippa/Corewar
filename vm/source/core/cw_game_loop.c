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
	if (t_champ_is_nbr_live(g_cw.pd.champs) || !g_cw.max_checks_check)
	{
		g_cw.cycle_to_die -= CYCLE_DELTA;
		g_cw.max_checks_check = MAX_CHECKS;
	}
	g_cw.cycle_to_die_check = g_cw.cycle_to_die;
	t_champ_zero_lives_number(g_cw.pd.champs);
	t_processe_killer(g_cw.pd.champs);
}

static void		cw_proc_executer(t_processes *proc)
{
	while (proc)
	{
		if (proc->exec_cycles == -1 && IS_COMMAND(g_cw.map[proc->pc]))
		{
			proc->cmd = g_cw.map[proc->pc];
			proc->exec_cycles = g_cw.op[proc->cmd - 1].cycles_price - 1;
		}
		if (proc->exec_cycles != -1)
		{
			if (!proc->exec_cycles)
			{
				g_cw.op[proc->cmd - 1].func(proc);
				proc->exec_cycles = -1;
			}
			else
				proc->exec_cycles--;
		}
		else
			proc->pc = MEM_X((proc->pc + 1));
		proc = proc->next;
	}
}

void			cw_game_loop(void)
{
	t_champ *champs;

	while (1)
	{
		// if (g_cw.cycle == 6909)
		// {

		// }
		if (g_cw.cycle >= 5612 && !g_cw.pd.flags[DUMP])
		{
			cw_refresh_colors();
			cw_print_map(); // TRASH
			ft_printf("\n************\nCycle: %u\n************\n", g_cw.cycle);
			ft_printf("cycle to die: %d\n", g_cw.cycle_to_die);
		}
		if (g_cw.cycle_to_die <= 0)
			break ;
		champs = g_cw.pd.champs;
		while (champs)
		{
			cw_proc_executer(champs->proc_start);
			ft_printf("%d live cur period: %u last live: %u\n",
				champs->champ_number, champs->lives_number, champs->last_live);
			champs = champs->next;
		}
		if (g_cw.pd.flags[DUMP] && g_cw.cycle == g_cw.pd.dump_stop)
			cw_print_dump_exit();
		if (!g_cw.cycle_to_die_check)
			cw_cycles_new_period();
		ft_printf("proc count: %u\n", g_cw.proc_counter);
		if (g_cw.proc_counter == 0)
			break ;
		g_cw.cycle++;
		g_cw.cycle_to_die_check--;
	}
}
