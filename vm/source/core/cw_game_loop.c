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
	t_processe_killer();
}

static void		cw_proc_executer(t_processes *proc)
{
	while (proc)
	{
		g_cw.color_map_pc[proc->pc]--;
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
			cw_move_pc(proc, 1);
		g_cw.color_map_pc[proc->pc]++;
		proc = proc->next;
	}
}

void			cw_game_loop_base(void)
{
	while (42)
	{
		if (g_cw.cycle_to_die <= 0)
			break ;
		if (!g_cw.cycle_to_die_check)
			cw_cycles_new_period();
		if (g_cw.proc_counter == 0)
			break ;
		cw_proc_executer(g_cw.proc_start);
		if (g_cw.pd.flags[DUMP] && g_cw.cycle == g_cw.pd.dump_stop)
			cw_print_dump_exit();
		g_cw.cycle++;
		g_cw.cycle_to_die_check--;
	}
}

int				cw_visu_game_loop(void)
{
	if (g_cw.cycle_to_die <= 0)
		return (0);
	if (!g_cw.cycle_to_die_check)
		cw_cycles_new_period();
	if (g_cw.proc_counter == 0)
		return (0);
	cw_proc_executer(g_cw.proc_start);
	g_cw.cycle++;
	g_cw.cycle_to_die_check--;
	return (1);
}
