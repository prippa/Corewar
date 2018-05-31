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

static void	cw_fill_map_with_bots(unsigned char *dst, int *stack_color, t_champ *champ)
{
	int				map_distance;
	unsigned int	i;
	unsigned int	j;
	int				color;

	map_distance = MEM_SIZE / g_cw->pd.champs_count;
	i = 0;
	color = 1;
	while (champ)
	{
		j = 0;
		while (j < champ->head.prog_size)
		{
			dst[i] = champ->code[j];
			stack_color[i] = color;
			i++;
			j++;
		}
		i += map_distance - j;
		color++;
		champ = champ->next;
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
	cw_fill_map_with_bots(g_cw->map.stack, g_cw->map.stack_color, g_cw->pd.champs);
}
