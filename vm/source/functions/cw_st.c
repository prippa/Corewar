/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:14:41 by prippa            #+#    #+#             */
/*   Updated: 2018/06/11 14:14:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_st(t_command *cmd, t_processes *proc)
{
	unsigned char	buf[4];

	if (cmd->codage == RR)
		proc->registers[cmd->arg2.av - 1] = proc->registers[cmd->arg1.av - 1];
	else if (cmd->codage == RI)
	{
		cw_write_bytes_to_buf(buf, proc->registers[cmd->arg1.av - 1]);
		cw_write_to_map(buf, (proc->pc + IDX_X(cmd->arg2.av)));
	}
}

static int		cw_get_args_av_st(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RR || cmd->codage == RI)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, DOUBLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_st(t_processes *proc)
{
	t_command	cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, DOUBLE_COMB);
	if (cw_get_args_av_st(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_st(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
