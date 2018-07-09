#include "corewar.h"

void		cw_refresh_colors(void)
{
	t_champ		*champs;
	t_processes	*proc;

	ft_bzero(&g_cw.color_map, MEM_SIZE);
	champs = g_cw.pd.champs;
	while (champs)
	{
		proc = champs->proc_start;
		while (proc)
		{
			g_cw.color_map[proc->pc] = champs->color;
			proc = proc->next;
		}
		champs = champs->next;
	}
}
