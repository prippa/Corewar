#include "corewar.h"

void		cw_parser(void)
{
	t_champ *cm;

	cm = g_cw->pd.champs;
	while (cm)
	{
		ft_printf("fd = (%d), file name = (%s)\n", cm->fd, cm->file_name);
		cm = cm->next;
	}
}
