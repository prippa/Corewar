#include "corewar.h"

static void	t_processes_add_to_head(t_processes **proc_start,
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

void		t_processe_add(t_processes **proc_start,
							t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw.proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw.id_counter++;
	new_obj->carry = 0;
	new_obj->pc = 0;
	new_obj->is_alive = DEAD;
	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);
	new_obj->champ_number = 0;
	new_obj->exec_cycles = -1;
	new_obj->cmd = 0;
	t_processes_add_to_head(proc_start, proc_end, new_obj);
}

void		t_processes_copy(t_processes **proc_start, t_processes **proc_end,
			t_processes *copy, int pc)
{
	int			i;
	t_processes	*new_obj;

	g_cw.proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw.id_counter++;
	new_obj->carry = copy->carry;
	new_obj->pc = pc;
	new_obj->is_alive = copy->is_alive;
	new_obj->champ_number = copy->champ_number;
	new_obj->exec_cycles = -1;
	new_obj->cmd = 0;
	i = -1;
	while (++i < REG_NUMBER)
		new_obj->registers[i] = copy->registers[i];
	t_processes_add_to_head(proc_start, proc_end, new_obj);
}
