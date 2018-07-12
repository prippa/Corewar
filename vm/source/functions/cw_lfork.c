/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 20:10:01 by prippa            #+#    #+#             */
/*   Updated: 2018/07/08 20:10:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_lfork(t_processes *proc)
{
    int		av;
	int		pc;
	t_champ	*champ;

	av = cw_get_dec_from_the_point(proc->pc + 1, g_cw.op[proc->cmd - 1].label);
    champ = t_champ_find(proc->champ_number, g_cw.pd.champs);
    if ((pc = MEM_X((proc->pc + av))) < 0)
        pc += MEM_SIZE;
    t_processes_copy(&champ->proc_start, &champ->proc_end, proc, pc);
    cw_move_pc_without_codage(proc);
}
