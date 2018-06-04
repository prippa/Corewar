/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:44:40 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 16:44:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			cw_add(t_command *cmd, t_stack *map, t_processes *process, int process_id)
{
	





	process->registers[cmd->arg3.av - 1] = process->registers[cmd->arg1.av - 1] + process->registers[cmd->arg2.av - 1];
	process->carry = (process->registers[cmd->arg3.av - 1] != 0) ? 1 : 0;
}
