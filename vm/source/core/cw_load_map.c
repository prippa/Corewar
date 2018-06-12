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
// TODO init id of the process map to zero;
static void	cw_fill_map_with_bots(t_stack *stack, t_processes *process)
{
	int		i;
	int		j;
	int		woohoo;
	t_champ	*champs;

	champs = g_cw->pd.champs;
	while (process && champs)
	{
		j = 0;
		woohoo = 0;
		i = process->process_PC;
		while (woohoo < champs->head.prog_size)
		{
			stack->stack[i] = champs->code[j];
			stack->stack_color[i] = process->color;
//			stack->stack_process_id[i] = process->id;
			j++;
			i++;
			woohoo++;
		}
		champs = champs->next;
		process = process->next;
	}
}

static void	cw_init_map(unsigned char *stack, int *stack_color,
						unsigned int *write_to_the_map_stack, unsigned int *cycle_stack)
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		stack[i] = '0';
		stack_color[i] = 0;
		write_to_the_map_stack[i] = 0;
		cycle_stack[i] = 0;
		i++;
	}
}

static void	cw_load_processes(t_champ *champ)
{
	int			color;
	int			process_pc;
	int			map_distance;

	color = 1;
	map_distance = MEM_SIZE / g_cw->pd.champs_count;

	ft_printf("map_distance -> %d\n", map_distance);
	
	process_pc = 0;
	while (champ)
	{
		t_processe_add(&g_cw->proc_start, &g_cw->proc_end);
		g_cw->proc_start->color = color;
		g_cw->proc_start->proc_process_PC_color = color + 4;
		g_cw->proc_start->proc_color_write_to_map = g_cw->proc_start->proc_process_PC_color + 4;
		g_cw->proc_start->process_PC = process_pc;
		g_cw->proc_start->registers[0] = champ->champ_number;
		color++;
		process_pc += map_distance;
		champ = champ->next;
	}
}

void		cw_load_map(void)
{
	cw_load_processes(g_cw->pd.champs);
	cw_init_map(g_cw->map.stack,
	g_cw->map.stack_color, g_cw->map.write_to_the_map_stack, g_cw->map.cycle_stack);
	cw_fill_map_with_bots(&g_cw->map, g_cw->proc_start);
}
