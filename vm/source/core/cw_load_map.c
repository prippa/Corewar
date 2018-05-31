/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:42:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/05/30 20:42:27 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_fill_map_with_bots(t_stack *stack, t_processes *process)
{
	int i;
	int j;
	int woohoo;

	while (process)
	{
		j = 0;
		woohoo = 0;
		i = process->process_PC;
		while (woohoo < process->champ_size)
		{
			stack->stack[i] = process->code[j];
			stack->stack_color[i] = process->color;
			j++;
			i++;
			woohoo++;
		}
		process = process->next;
	}
}

static void	cw_init_map(unsigned char *stack, int *stack_color)
{
	unsigned int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		stack[i] = '0';
		stack_color[i] = 0;
		i++;
	}
}

void		cw_load_map(void)
{
	cw_init_map(g_cw->map.stack, g_cw->map.stack_color);
	cw_fill_map_with_bots(&g_cw->map, g_cw->processes);
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
