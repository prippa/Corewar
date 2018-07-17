/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_proc_add_cpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:04:33 by prippa            #+#    #+#             */
/*   Updated: 2018/07/14 16:04:34 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	t_processes_add_to_start(t_processes **proc_start,
				t_processes **proc_end, t_processes *new_obj)
{
	new_obj->next = *proc_start;
	new_obj->prev = NULL;
	if (*proc_start)
		(*proc_start)->prev = new_obj;
	else
		*proc_end = new_obj;
	*proc_start = new_obj;
}

static void	t_processes_add_to_end(t_processes **proc_start,
				t_processes **proc_end, t_processes *new_obj)
{
	new_obj->next = NULL;
	new_obj->prev = *proc_end;
	if (*proc_end)
		(*proc_end)->next = new_obj;
	else
		*proc_start = new_obj;
	*proc_end = new_obj;
}

void		t_processe_add(t_processes **proc_start,
				t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw.proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->pc = 0;
	new_obj->carry = 0;
	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);
	new_obj->is_alive = DEAD;
	new_obj->champ_number = 0;
	new_obj->exec_cycles = -1;
	new_obj->cmd = 0;
	new_obj->color = 0;
	t_processes_add_to_end(proc_start, proc_end, new_obj);
}

void		t_processes_copy(t_processes **proc_start, t_processes **proc_end,
				t_processes *copy, int pc)
{
	int			i;
	t_processes	*new_obj;

	g_cw.proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->pc = pc;
	new_obj->carry = copy->carry;
	i = -1;
	while (++i < REG_NUMBER)
		new_obj->registers[i] = copy->registers[i];
	new_obj->is_alive = copy->is_alive;
	new_obj->champ_number = copy->champ_number;
	new_obj->cmd = 0;
	new_obj->exec_cycles = -1;
	new_obj->color = copy->color;
	g_cw.mp.color_map_pc[pc]++;
	t_processes_add_to_start(proc_start, proc_end, new_obj);
}
