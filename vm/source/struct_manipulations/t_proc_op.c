#include "corewar.h"

void		t_processe_killer(t_processes *head)
{
	t_processes *tmp;

	while (head)
	{
		if (head->has_been_activated == LIVE)
			head->has_been_activated = DEAD;
		else
		{
			tmp = head->next;
			t_processe_free_by_obj(&g_cw->proc_start, &g_cw->proc_end, head);
			if (!tmp)
				return ;
			head = tmp;
			continue;
		}
		head = head->next;
	}
}
