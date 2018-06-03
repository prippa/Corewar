#include "corewar.h"

void	t_processe_free_first(t_processes **proc_start, t_processes **proc_end)
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

void	t_processe_add(t_processes **proc_start, t_processes **proc_end)
{
	t_processes	*new_obj;

	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
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
