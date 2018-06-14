/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:09:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 12:09:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_color(unsigned char data, int color_type)
{
	if (color_type == 1)
		ft_printf("%~.2x", F_GREEN, data);
	else if (color_type == 2)
		ft_printf("%~.2x", F_RED, data);
	else if (color_type == 3)
		ft_printf("%~.2x", F_BLUE, data);
	else if (color_type == 4)
		ft_printf("%~.2x", F_CYAN, data);
	else if (color_type == 5)
		ft_printf("%~.2x", F_BACK_GREEN_BLACK, data);
	else if (color_type == 6)
		ft_printf("%~.2x", F_BACK_RED_BLACK, data);
	else if (color_type == 7)
		ft_printf("%~.2x", F_BACK_BLUE_BLACK, data);
	else if (color_type == 8)
		ft_printf("%~.2x", F_BACK_CYAN_BLACK, data);
	else if (color_type == 9)
		ft_printf("%~.2x", F_BOLD_GREEN, data);
	else if (color_type == 10)
		ft_printf("%~.2x", F_BOLD_RED, data);
	else if (color_type == 11)
		ft_printf("%~.2x", F_BOLD_BLUE, data);
	else if (color_type == 12)
		ft_printf("%~.2x", F_BOLD_CYAN, data);
	else
		ft_printf("%~.2x", F_WHITE, 0);
}

void		cw_display_map(unsigned char *map, int *color)
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	read(1, 0, 1); // this stuff may help with visualization;
	system("clear"); // this stuff may help with visualization;

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		print_color(map[i], color[i]);
		ft_putchar(' ');
		if (lines == NEWLINE_QUANTITY)
		{
			ft_putchar('\n');
			lines = -1;
		}
		lines++;
		spaces++;
		i++;
	}
}
