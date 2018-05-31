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

int		champ_quantity(t_champ *champ)
{
	int i;

	i = 0;
	while (champ)
	{
		i++;
		champ = champ->next;
	}
	return (i);
}

void	fill_map_with_bots(unsigned char *dst, int *stack_color, t_champ *champ)
{
	int				map_distance;
	unsigned int	i;
	unsigned int	j;
	int				color;

	map_distance = MEM_SIZE / champ_quantity(champ);
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

void	init_map(unsigned char *stack, int *stack_color)
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

void	print_color(unsigned char data, int color_type)
{
	if (color_type == 1)
		ft_printf("%~.2x", F_GREEN, data);
	else if (color_type == 2)
		ft_printf("%~.2x", F_RED, data);
	else if (color_type == 3)
		ft_printf("%~.2x", F_BLUE, data);
	else if (color_type == 4)
		ft_printf("%~.2x", F_CYAN, data);
}

void	display_map(unsigned char *map, int *color)
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != '0')
			print_color(map[i], color[i]);
		else
			ft_printf("%~.2d", F_WHITE, 0);
		ft_printf(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = -1;
		}
		lines++;
		spaces++;
		i++;
	}
}

void	cw_load_map(void)
{
	init_map(g_cw->map.stack, g_cw->map.stack_color);
	fill_map_with_bots(g_cw->map.stack, g_cw->map.stack_color, g_cw->pd.champs);
	display_map(g_cw->map.stack, g_cw->map.stack_color);
}
