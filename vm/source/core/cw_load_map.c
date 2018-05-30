#include "corewar.h"

void	init_map(unsigned char *dst /*, unsigned char *src, int start*/) // for the several bots;
{
	int i;

	i  = 0;
	while (i < MEM_SIZE) // new line quantity;
		dst[i++] = '0';
}	

void	cw_load_map()
{
	unsigned int i;

	i = 0;
	while (i < g_cw->pd.champs->head.prog_size)
	{
		ft_printf("code -> %x\n", g_cw->pd.champs->code[i]);
		i++;
	}
	init_map(g_cw->pd.map);
}
