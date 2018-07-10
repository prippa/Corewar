/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:11:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/06 16:49:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_live(t_processes *proc)
{
	t_champ	*proc_champ;
	t_champ	*av_champ;
	int		av;

	proc->is_alive = ALIVE;
	av = cw_get_dec_from_the_point(proc->pc + 1, g_cw.op[proc->cmd - 1].label);
	proc_champ = t_champ_find(proc->champ_number, g_cw.pd.champs);
	proc_champ->real_lives_number++;
	av_champ = t_champ_find(av, g_cw.pd.champs);
	if (av_champ)
	{
		av_champ->lives_number++;
		av_champ->last_live = g_cw.cycle + 1;
	}
	cw_move_pc_without_codage(proc);
}