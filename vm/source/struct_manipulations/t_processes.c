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

t_processes	*t_processe_get_by_id(t_processes *proc_start,
								t_processes *proc_end, unsigned int id)
{
	unsigned int i;

	i = 0;
	while (proc_start && proc_end && i <= (g_cw->proc_counter / 2))
	{
		if (proc_start->id == id)
			return (proc_start);
		else if (proc_end->id == id)
			return (proc_end);
		proc_start = proc_start->next;
		proc_end = proc_end->prev;
		i++;
	}
	return (NULL);
}

int			t_processe_free_by_obj(t_processes **proc_start,
								t_processes **proc_end, t_processes *obj)
{
	if (!(*proc_start) || !(*proc_end) || !obj)
		return (0);
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

int			t_processe_free_by_id(t_processes **proc_start,
								t_processes **proc_end, unsigned int id)
{
	t_processes *tmp;

	if (!(tmp = t_processe_get_by_id(*proc_start, *proc_end, id)))
		return (0);
	if (!t_processe_free_by_obj(proc_start, proc_end, tmp))
		return (0);
	return (1);
}
// TODO change init stuff
void		t_processe_add(t_processes **proc_start,
							t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw->proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw->id_counter++;
	new_obj->carry = 0;
	new_obj->color = 0;
	new_obj->process_PC = 0;
	new_obj->live_status = ALIVE;
	new_obj->has_been_activated = DEAD;
	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);
	new_obj->next = *proc_start;
	new_obj->prev = NULL;
	new_obj->cycles_till_execution = 0;
	if (*proc_start)
		(*proc_start)->prev = new_obj;
	else
		*proc_end = new_obj;
	*proc_start = new_obj;
}

void		t_processes_copy(t_processes **proc_start, t_processes **proc_end, t_processes **current_proc, int position)
{

	t_processes	*new_obj;

	// add general quantity of the processes;
	g_cw->proc_counter++;

	// created the memory area for the new node/process;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);

	// general variable;
	new_obj->id = g_cw->id_counter++;

	new_obj->carry = (*current_proc)->carry; // copy;
	new_obj->color = (*current_proc)->color; // copy;
	new_obj->process_PC = position; // not a copy;
	new_obj->live_status = (*current_proc)->live_status; // copy;
	new_obj->has_been_activated = (*current_proc)->has_been_activated; // copy;
	new_obj->cycles_till_execution = (*current_proc)->cycles_till_execution;

	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);

	ft_memcpy(new_obj->registers, (*current_proc)->registers, 16); // copy;

	// add to the head;
	new_obj->next = *proc_start;
	new_obj->prev = NULL;
	if (*proc_start)
		(*proc_start)->prev = new_obj;
	else
		*proc_end = new_obj;
	*proc_start = new_obj;


}
