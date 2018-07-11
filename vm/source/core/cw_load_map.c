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
	int	map_index;
	int	champ_code_index;
	int	i;

	while (champs)
	{
		map_index = champs->proc_start->pc;
		g_cw.color_map_pc[champs->proc_start->pc] = 1;
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
		t_processe_add(&champ->proc_start, &champ->proc_end);
		champ->proc_start->pc = process_pc;
		champ->proc_start->registers[0] = champ->champ_number;
		champ->proc_start->champ_number = champ->champ_number;
		champ->proc_start->color = color;
		champ->color = color;
		color++;
		process_pc += map_distance;
		champ = champ->next;
	}
}

void		cw_load_map(void)
{
	cw_load_processes(g_cw.pd.champs);
	cw_fill_map_with_bots(g_cw.pd.champs);
}
