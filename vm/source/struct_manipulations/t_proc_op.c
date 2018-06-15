#include "corewar.h"

void		t_processe_killer(t_processes *head)
{
	while (head)
	{
		if (head->has_been_activated == LIVE)
			head->has_been_activated = DEAD;
		else
			t_processe_free_by_obj(&g_cw->proc_start, &g_cw->proc_end, head);
		head = head->next;
	}
}
