/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_code_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:02:41 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 17:02:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_get_command(t_command *cmd,
			unsigned char code[CHAMP_MAX_SIZE + 1],
			int *i)
{
	*i += 1;
}

void		cw_get_code_data(t_champ *champ)
{
	g_cw->pd.i = 0;
	while (g_cw->pd.i < champ->head.prog_size)
	{
		// t_command_add(&champ->cmd);
		ft_printf("%u ", champ->code[g_cw->pd.i]);
		cw_get_command(champ->cmd, champ->code, &g_cw->pd.i);
	}
	ft_putchar('\n');
}
