/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:42:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/05 13:58:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_fill_map_with_bots(t_champ *champs)
{
	int				map_index;
	int				champ_code_index;
	unsigned int	i;
	t_processes		*proc;

	proc = g_cw.proc_end;
	while (proc)
	{
		map_index = proc->pc;
		g_cw.color_map_pc[proc->pc]++;
		champ_code_index = 0;
		i = -1;
		while (++i < champs->head.prog_size)
		{
			g_cw.map[map_index] = champs->code[champ_code_index];
			g_cw.color_map[map_index] = champs->color;
			champ_code_index++;
			map_index++;
		}
		champs = champs->next;
		proc = proc->prev;
	}
}

static void	cw_load_processes(t_champ *champ)
{
	int				process_pc;
	int				map_distance;
	unsigned char	color;

	map_distance = MEM_SIZE / g_cw.pd.champs_count;
	process_pc = 0;
	color = 1;
	while (champ)
	{
		t_processe_add(&g_cw.proc_start, &g_cw.proc_end);
		g_cw.proc_start->pc = process_pc;
		g_cw.proc_start->registers[0] = champ->champ_number;
		g_cw.proc_start->champ_number = champ->champ_number;
		g_cw.proc_start->color = color;
		champ->color = color;
		color++;
		process_pc += map_distance;
		champ = champ->next;
	}
}

void		cw_load_map(void)
{
	// t_champ_sort_by_order(&g_cw.pd.champs);
	cw_load_processes(g_cw.pd.champs);
	// t_champ_sort_by_champ_number(&g_cw.pd.champs);
	cw_fill_map_with_bots(g_cw.pd.champs);
}
