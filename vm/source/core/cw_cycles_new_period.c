/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_cycles_new_period.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:27:06 by prippa            #+#    #+#             */
/*   Updated: 2018/06/14 15:27:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_cycles_new_period(void)
{
	g_cw->max_checks_check--;
	if (t_champ_get_lives_number(g_cw->pd.champs) > NBR_LIVE
		|| !g_cw->max_checks_check)
	{
		g_cw->cycle_to_die -= CYCLE_DELTA;
		g_cw->max_checks_check = MAX_CHECKS;
	}
	t_champ_zero_lives_number(g_cw->pd.champs);
	g_cw->cycle_to_die_check = g_cw->cycle_to_die;
	t_processe_killer(g_cw->proc_start);
}
