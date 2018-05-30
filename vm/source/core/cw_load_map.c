#include "corewar.h"

void	init_map(unsigned char *dst /*, unsigned char *src, int start*/) // for the several bots;
{
	int i;

	i  = 0;
	while (i < MEM_SIZE * 2) // new line quantity;
		dst[i++] = '0';
}	

void	cw_load_map()
{
	unsigned int i;
	unsigned int lines;
	unsigned int spaces;


	i = 0;
	lines = 1;
	spaces = 1;

	// while (i < g_cw->pd.champs->head.prog_size)
	// {
	// 	ft_printf("code -> %x\n", g_cw->pd.champs->code[i]);
	// 	i++;
	// }
	init_map(g_cw->map.stack);

	while (i < MEM_SIZE * 2)
	{
		ft_printf("%c", g_cw->map.stack[i]);
		
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = 0;
		}

		if (spaces == SPACES_BYTES)
		{
			ft_printf(" ");
			spaces = 0;
		}
		lines++;
		spaces++;
		i++;
	}
	ft_printf("i -> %d\n", i);
}
