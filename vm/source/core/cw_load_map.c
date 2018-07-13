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

	proc = g_cw.proc_start;
	while (proc)
	{
		map_index = proc->pc;
		g_cw.color_map_pc[proc->pc]++;
		champ_code_index = 0;
		i = -1;
		while (++i < champs->head.prog_size)
		{
			g_cw.map[map_index] = champs->code[champ_code_index];
			g_cw.color_map[map_index] = proc->color;
			champ_code_index++;
			map_index++;
		}
		champs = champs->next;
		proc = proc->next;
	}
}

static int cw_get_right_color_by_champ_number(int champ_number)
{
	if (champ_number == -1)
		return (F_GREEN);
	if (champ_number == -2)
		return (F_BLUE);
	if (champ_number == -3)
		return (F_RED);
	if (champ_number == -4)
		return (F_CYAN);
	return (0);
}

static int cw_get_right_pc_by_color(int color, int map_distance)
{
	if (color == F_GREEN)
		return (0);
	if (color == F_BLUE)
		return (map_distance);
	if (color == F_RED)
		return (map_distance * 2);
	if (color == F_CYAN)
		return (map_distance * 3);
	return (0);
}

static void	cw_load_processes(t_champ *champs)
{
	unsigned char	color;

	while (champs)
	{
		color = cw_get_right_color_by_champ_number(champs->champ_number);
		t_processe_add(&g_cw.proc_start, &g_cw.proc_end);
		g_cw.proc_end->pc = cw_get_right_pc_by_color(color,
								(MEM_SIZE / g_cw.pd.champs_count));
		g_cw.proc_end->registers[0] = champs->champ_number;
		g_cw.proc_end->champ_number = champs->champ_number;
		g_cw.proc_end->color = color;
		champs->color = color;
		champs = champs->next;
	}
}

void		cw_load_map(void)
{
	t_champ_sort_by_order(&g_cw.pd.champs);
	cw_load_processes(g_cw.pd.champs);
	cw_fill_map_with_bots(g_cw.pd.champs);
	t_champ_sort_by_champ_number(&g_cw.pd.champs);
}
