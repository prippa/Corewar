/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:11:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/05 19:17:36 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// Выполняет 2 операции:
//1. Засчитывает, что процесс (который выполняет данную команду) жив.
//2. Засчитывает, что жив номер (если этот номер совпадает с номером игрока, то засчитвает, что этот игрок жив), который заходит как аргумент (T_DIR).

void			cw_live(t_command *cmd, t_stack *map, unsigned int process_id)
{
    t_processes *proc;
    // int	arguments[3];
    //process;
    proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);



}