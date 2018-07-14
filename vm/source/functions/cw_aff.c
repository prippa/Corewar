/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:44:01 by prippa            #+#    #+#             */
/*   Updated: 2018/06/06 19:44:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_aff(t_command *cmd, t_processes *proc)
{
	char c;

	c = (proc->registers[cmd->arg1.av - 1] % 256);
	ft_putstr("Aff: ");
	ft_putchar(c);
	ft_putchar('\n');
}

static int		cw_get_args_av_aff(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == R)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, SINGLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_aff(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, SINGLE_COMB);
	if (cw_get_args_av_aff(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_aff(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
