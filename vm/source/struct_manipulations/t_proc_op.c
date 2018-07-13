#include "corewar.h"

void		t_processes_initer(void)
{
	t_processes *proc;

	proc = g_cw.proc_start;
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
			g_cw.color_map_pc[head->pc]--;
			t_processe_free_by_obj(&g_cw.proc_start, &g_cw.proc_end, head);
			head = tmp;
			continue;
		}
		head = head->next;
	}
}
