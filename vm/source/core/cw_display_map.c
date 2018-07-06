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
		ft_printf("%~.2x", F_BLUE, data);
	else if (color_type == 3)
		ft_printf("%~.2x", F_RED, data);
	else if (color_type == 4)
		ft_printf("%~.2x", F_CYAN, data);
	else if (color_type == 5)
		ft_printf("%~.2x", F_BACK_GREEN_BLACK, data);
	else if (color_type == 6)
		ft_printf("%~.2x", F_BACK_BLUE_BLACK, data);
	else if (color_type == 7)
		ft_printf("%~.2x", F_BACK_RED_BLACK, data);
	else if (color_type == 8)
		ft_printf("%~.2x", F_BACK_CYAN_BLACK, data);
	else if (color_type == 9)
		ft_printf("%~.2x", F_BOLD_GREEN, data);
	else if (color_type == 10)
		ft_printf("%~.2x", F_BOLD_BLUE, data);
	else if (color_type == 11)
		ft_printf("%~.2x", F_BOLD_RED, data);
	else if (color_type == 12)
		ft_printf("%~.2x", F_BOLD_CYAN, data);
	else if (color_type == 13)
		ft_printf("%~.2x", F_BACK_GREEN_WHITE, data);
	else if (color_type == 14)
		ft_printf("%~.2x", F_BACK_BLUE_WHITE, data);
	else if (color_type == 15)
		ft_printf("%~.2x", F_BACK_RED_WHITE, data); // change the color;
	else if (color_type == 16)
		ft_printf("%~.2x", F_BACK_CYAN_WHITE, data); // change the color;
		else if (color_type == 100) // do a macor
		ft_printf("%~.2x", F_BACK_GRAY_BLACK, data); // change the color;
	else
		ft_printf("%~.2x", F_WHITE, 0);
}

void		cw_display_map(unsigned char *map, unsigned int *color)
{
	unsigned int i;
	unsigned int spaces;
	unsigned int lines;

	read(1, 0, 1); // this stuff may help with visualization;
	system("clear"); // this stuff may help with visualization;
	ft_putstr("\n\n   ");

	i = 0;
	spaces = 1;
	lines = 0;
	while (i < MEM_SIZE)
	{
		print_color(map[i], color[i]);
		ft_putstr(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_putstr("\n   ");
			lines = -1;
		}
		lines++;
		spaces++;
		i++;
	}
}

void		cw_display_dump(void)
{
	int	counter;
	int index;

	counter = 0;
	index = 0;
	while (index < MEM_SIZE)
	{
		ft_printf("0x%.4x : ", counter);
		while (index < (counter + CW_BIT))
		{
			ft_printf("%.2x ", g_cw.map.stack[index]);
			index++;
		}
		ft_putstr("\n");
		counter += CW_BIT;
	}
}
