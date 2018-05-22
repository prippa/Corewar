#include "corewar.h"

static void	cw_parse_data_free(t_parse_data *pd)
{
	t_champ_free(&pd->champs);
}

void		cw_free(void)
{
	cw_parse_data_free(&g_cw->pd);
	free(g_cw);
}
