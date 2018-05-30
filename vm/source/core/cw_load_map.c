#include "corewar.h"

void	init_map(char *str)
{
	int i;

	i  = 0;
	while (i < MEM_SIZE + NEWLINE_QUANTITY)
		str[i++] = '0';
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
}
