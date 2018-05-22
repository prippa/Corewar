#include "corewar.h"

struct s_corewar *g_cw;

static void	cw_parse_data_init(t_parse_data *pd)
{
	pd->champs = NULL;
}

void		cw_init(void)
{
	if (!(g_cw = (t_corewar *)malloc(sizeof(t_corewar))))
		cw_perror_exit("ERROR", MALLOC);
	cw_parse_data_init(&g_cw->pd);
}
