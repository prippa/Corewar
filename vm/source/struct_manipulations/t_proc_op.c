#include "corewar.h"

void		t_processe_init(t_processes *proc)
{
	while (proc)
	{
		if (proc->exec_cycles == -1 && IS_COMMAND(g_cw.map[proc->pc]))
		{
			proc->cmd = g_cw.map[proc->pc];
			proc->exec_cycles = g_cw.op[proc->cmd - 1].cycles_price - 1;
		}
		proc = proc->next;
	}
}

void		t_processes_initer(t_champ *champs)
{
	t_processes *proc;
	while (champs)
	{
		proc = champs->proc_start;
		while (proc)
		{
			if (proc->exec_cycles == -1 && IS_COMMAND(g_cw.map[proc->pc]))
			{
				proc->cmd = g_cw.map[proc->pc];
				proc->exec_cycles = g_cw.op[proc->cmd - 1].cycles_price - 1;
			}
			proc = proc->next;
		}
		champs = champs->next;
	}
}

void		t_processe_killer(t_champ *champs)
{
	t_processes	*head;
	t_processes	*tmp;

	while (champs)
	{
		head = champs->proc_start;
		while (head)
		{
			if (head->is_alive == ALIVE)
				head->is_alive = DEAD;
			else
			{
				tmp = head->next;
				t_processe_free_by_obj(&champs->proc_start, &champs->proc_end, head);
				head = tmp;
				continue;
			}
			head = head->next;
		}
		champs = champs->next;
	}
}
