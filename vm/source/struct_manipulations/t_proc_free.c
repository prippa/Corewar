/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_processes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:25:50 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 19:30:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			t_processe_free_by_obj(t_processes **proc_start,
								t_processes **proc_end, t_processes *obj)
{
	if (!(*proc_start) || !(*proc_end) || !obj)
		return (0);
	g_cw.mp.color_map_pc[obj->pc]--;
	g_cw.proc_counter--;
	if (obj == *proc_start)
	{
		*proc_start = (*proc_start)->next;
		if (*proc_start)
			(*proc_start)->prev = NULL;
		else
			*proc_end = NULL;
	}
	else if (!obj->next)
	{
		obj->prev->next = NULL;
		*proc_end = obj->prev;
	}
	else
	{
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	free(obj);
	return (1);
}

void		t_processe_killer(void)
{
	t_processes	*head;
	t_processes	*tmp;

	head = g_cw.proc_start;
	while (head)
	{
		if (head->is_alive == ALIVE)
			head->is_alive = DEAD;
		else
		{
			tmp = head->next;
			t_processe_free_by_obj(&g_cw.proc_start, &g_cw.proc_end, head);
			head = tmp;
			continue;
		}
		head = head->next;
	}
}

void		t_processes_free(t_processes **proc_start, t_processes **proc_end)
{
	while (*proc_start)
		t_processe_free_by_obj(proc_start, proc_end, *proc_start);
}
