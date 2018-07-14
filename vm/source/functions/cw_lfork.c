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

	av = cw_get_dec_from_the_point(proc->pc + 1, g_cw.op[proc->cmd - 1].label);
    if ((pc = MEM_X((proc->pc + av))) < 0)
        pc += MEM_SIZE;
    t_processes_copy(&g_cw.proc_start, &g_cw.proc_end, proc, pc);
    cw_move_pc_without_codage(proc);
}
