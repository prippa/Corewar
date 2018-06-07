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

void			cw_aff(t_command *cmd, t_stack *map, t_processes *proc)
{
	ft_printf("Aff: %c\n", proc->registers[cmd->arg1.av - 1] % 256);
	proc->process_PC = MEM_CORRECTION(proc->process_PC + cmd->arg1.tp + 2);
}
