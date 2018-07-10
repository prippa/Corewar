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

static int		cw_get_pc_of_arg2_arg3_sti(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR)
		return (proc->pc + ((proc->registers[cmd->arg2.av - 1]
			+ proc->registers[cmd->arg3.av - 1]) % IDX_MOD));
	else if (cmd->codage == RRD)
		return (proc->pc + ((proc->registers[cmd->arg2.av - 1]
			+ cmd->arg3.av) % IDX_MOD));
	else if (cmd->codage == RDR)
		return (proc->pc + ((cmd->arg2.av
		+ proc->registers[cmd->arg3.av - 1]) % IDX_MOD));
	else if (cmd->codage == RDD)
		return (proc->pc + ((cmd->arg2.av
		+ cmd->arg3.av) % IDX_MOD));
	else if (cmd->codage == RIR)
		return (proc->pc + (
			(cw_get_dec_from_the_point((cmd->arg2.av % IDX_MOD), 4)
			+ proc->registers[cmd->arg3.av - 1]) % IDX_MOD));
	else if (cmd->codage == RID)
		return (proc->pc + (
			(cw_get_dec_from_the_point((cmd->arg2.av % IDX_MOD), 4)
			+ cmd->arg3.av) % IDX_MOD));
	return (0);
}

static void		cw_execute_sti(t_command *cmd, t_processes *proc)
{
	int				pc;
	unsigned char	buf[4];

	pc = cw_get_pc_of_arg2_arg3_sti(cmd, proc);
	cw_write_bytes_to_buf(buf, proc->registers[cmd->arg1.av - 1]);
	cw_write_to_map(buf, pc);
}

static int		cw_get_args_av_sti(t_command *cmd, t_processes *proc)
{
	if (cmd->codage == RRR || cmd->codage == RRD || cmd->codage == RDR
		|| cmd->codage == RDD || cmd->codage == RIR || cmd->codage == RID)
		cw_set_arg_av(cmd, proc->pc + CODAGE_SKIP);
	else
		return (0);
	return (1);
}

void			cw_sti(t_processes *proc)
{
	t_command cmd;

	ft_bzero(&cmd, sizeof(t_command));
	cw_get_codage_and_arg_tp(&cmd, proc);
	if (cw_get_args_av_sti(&cmd, proc) && cw_is_valid_reg(&cmd))
		cw_execute_sti(&cmd, proc);
	cw_move_pc_with_codage(&cmd, proc);
}
