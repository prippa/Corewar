/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:12 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:56:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_perror_exit(char *message, int error_number)
{
	perror(message);
	cw_free();
	exit(error_number);
}

static void	cw_exit_print_message(char *message, int error_number)
{
	if (error_number == HEADER)
		ft_dprintf(2, "Error: File [%s] has an invalid header\n", message);
	else if (error_number == PROG_NAME)
		ft_dprintf(2, "Error: File [%s] has an invalid prog name\n", message);
	else if (error_number == PROG_SIZE_TO_BIG)
		ft_dprintf(2, "Error: File [%s] has too large a code (\
%u bytes > %u bytes)\n", message, (unsigned int)(g_cw.pd.tmp), CHAMP_MAX_SIZE);
	else if (error_number == COMMENT)
		ft_dprintf(2, "Error: File [%s] has an invalid comment\n", message);
	else if (error_number == PROG_SIZE_INVALID)
		ft_dprintf(2, "Error: File [%s] \
has a code size that differ from what its header says\n", message);
	else
		ft_dprintf(2, "%s\n", message);
}

void		cw_exit(char *message, int error_number)
{
	cw_exit_print_message(message, error_number);
	cw_free();
	exit(error_number);
}

void		cw_print_dump_exit(void)
{
	int	counter;
	int index;

	cw_print_players(g_cw.pd.champs);
	counter = 0;
	index = 0;
	while (index < MEM_SIZE)
	{
		ft_printf("0x%.4x : ", counter);
		while (index < (counter + CW_BIT))
		{
			ft_printf("%.2x ", g_cw.map[index]);
			index++;
		}
		ft_putchar('\n');
		counter += CW_BIT;
	}
	cw_free();
	exit(0);
}
