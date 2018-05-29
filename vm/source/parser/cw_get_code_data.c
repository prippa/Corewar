/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_code_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:02:41 by prippa            #+#    #+#             */
/*   Updated: 2018/05/29 01:10:28 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_get_code_data(t_champ *champ)
{
	g_cw->pd.i = 0;
	while (g_cw->pd.i < champ->head.prog_size)
	{
		t_command_add(&champ->cmd);
		cw_get_command(champ->cmd, &g_cw->pd.i, champ->code);
	}
}
