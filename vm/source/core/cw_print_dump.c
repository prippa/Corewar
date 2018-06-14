/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_print_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:27:14 by prippa            #+#    #+#             */
/*   Updated: 2018/06/14 15:27:16 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_print_map(void)
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
			ft_printf("%.2x ", g_cw->map.stack[index]);
			index++;
		}
		ft_putchar('\n');
		counter += CW_BIT;
	}
}

void		cw_print_players(void)
{
	int		i;
	t_champ	*champs;

	i = 1;
	champs = g_cw->pd.champs;
	ft_putstr("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, champs->head.prog_size,
			champs->head.prog_name, champs->head.comment);
		champs = champs->next;
		i++;
	}
}

void		cw_print_dump(void)
{
	cw_print_players();
	cw_print_map();
	cw_free();
	exit(0);
}
