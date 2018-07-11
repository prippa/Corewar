/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:34:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/07 15:31:00 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		cw_execute_sti(t_command *cmd, t_processes *proc)
{
	int				pc;
	unsigned char	buf[4];

	if (cmd->codage == RIR || cmd->codage == RID)
		pc = (proc->pc + (
		((cw_get_dec_from_the_point(((cmd->arg2.av % IDX_MOD) + proc->pc), 4))
		+ (cw_get_right_arg(proc, cmd->arg3.tp, cmd->arg3.av))) % IDX_MOD));
	else
		pc = (proc->pc + (((cw_get_right_arg(proc, cmd->arg2.tp, cmd->arg2.av))
		+ (cw_get_right_arg(proc, cmd->arg3.tp, cmd->arg3.av))) % IDX_MOD));
	cw_write_bytes_to_buf(buf, proc->registers[cmd->arg1.av - 1]);
	cw_write_to_map(buf, pc);
}

static int		cw_get_args_av_sti(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RRD || cmd->codage == RDR
		|| cmd->codage == RDD || cmd->codage == RIR || cmd->codage == RID)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP, TRIPLE_COMB);
	else
		return (0);
	return (1);
}

void			cw_sti(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cmd.codage = g_cw.map[MEM_X((proc->pc + 1))];
	cw_set_arg_tp_with_codage(&cmd, g_cw.op[proc->cmd - 1].label, TRIPLE_COMB);
	if (cw_get_args_av_sti(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_sti(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
