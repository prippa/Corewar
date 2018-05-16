#include "corewar.h"

static void	cw_parse_data_free(t_parse_data *pd)
{
	ft_strdel(&pd->name);
}

void		cw_free(void)
{
	cw_parse_data_free(&g_cw->pd);
	free(g_cw);
}
