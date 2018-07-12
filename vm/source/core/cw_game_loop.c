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
		g_cw.color_map_pc[proc->pc] = 0;
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
		g_cw.color_map_pc[proc->pc] = 1;
		proc = proc->next;
	}
}

int				cw_game_loop(void)
{
	t_champ *champs;

	if (g_cw.cycle_to_die <= 0)
		return (0);
	t_processes_initer(g_cw.pd.champs);
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
		return (0);
	g_cw.cycle++;
	g_cw.cycle_to_die_check--;
	return (1);
}
