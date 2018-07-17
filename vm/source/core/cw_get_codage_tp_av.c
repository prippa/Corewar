/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_codage_tp_av.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:03:10 by prippa            #+#    #+#             */
/*   Updated: 2018/07/14 16:03:14 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	cw_what_tp(unsigned char tp, char label)
{
	if (tp == REG_CODE)
		return (TP_REG);
	else if (tp == DIR_CODE)
		return (label);
	else if (tp == IND_CODE)
		return (TP_IND);
	else
		return (0);
}

void		cw_set_arg_tp_with_codage(t_command *cmd, char label, char comb)
{
	unsigned char tp1;
	unsigned char tp2;
	unsigned char tp3;

	tp1 = cmd->codage;
	tp1 = tp1 >> 6;
	cmd->arg1.tp = cw_what_tp(tp1, label);
	if (comb >= DOUBLE_COMB)
	{
		tp2 = cmd->codage;
		tp2 = tp2 << 2;
		tp2 = tp2 >> 6;
		cmd->arg2.tp = cw_what_tp(tp2, label);
	}
	if (comb == TRIPLE_COMB)
	{
		tp3 = cmd->codage;
		tp3 = tp3 << 4;
		tp3 = tp3 >> 6;
		cmd->arg3.tp = cw_what_tp(tp3, label);
	}
}

void		cw_set_arg_av(t_command *cmd, int pc, char comb)
{
	pc = MEM_X(pc);
	cmd->arg1.av = cw_get_dec_from_the_point(pc, cmd->arg1.tp);
	if (comb >= DOUBLE_COMB)
	{
		pc = MEM_X((pc + cmd->arg1.tp));
		cmd->arg2.av = cw_get_dec_from_the_point(pc, cmd->arg2.tp);
	}
	if (comb == TRIPLE_COMB)
	{
		pc = MEM_X((pc + cmd->arg2.tp));
		cmd->arg3.av = cw_get_dec_from_the_point(pc, cmd->arg3.tp);
	}
}
