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

int			t_processe_free_by_id(t_processes **proc_start,
								t_processes **proc_end, unsigned int id)
{
	t_processes *temp;

	if (!(temp = t_processe_get_by_id(*proc_start, *proc_end, id)))
		return (0);
	if (temp == *proc_start)
	{
		*proc_start = (*proc_start)->next;
		(*proc_start)->prev = NULL;
	}
	else
	{
		if (temp->next == NULL)
		{
			temp->prev->next = NULL;
			*proc_end = temp->prev;
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	free(temp);
	return (1);
}

void		t_processe_free_one(t_processes **proc_start,
								t_processes **proc_end)
{
	t_processes *tmp;

	tmp = *proc_start;
	*proc_start = (*proc_start)->next;
	if (*proc_start)
		(*proc_start)->prev = NULL;
	else
		*proc_end = NULL;
	free(tmp);
}

void		t_processe_add(t_processes **proc_start,
							t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw->proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw->id_counter++;
	new_obj->carry = 0;
	new_obj->champ_size = 0;
	new_obj->color = 0;
	new_obj->process_PC = 0;
	ft_bzero(new_obj->registers, REG_NUMBER);
	new_obj->next = *proc_start;
	new_obj->prev = NULL;
	if (*proc_start)
		(*proc_start)->prev = new_obj;
	else
		*proc_end = new_obj;
	*proc_start = new_obj;
}
