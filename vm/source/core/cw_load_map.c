#include "corewar.h"

int		champ_quantity(t_champ *champ)
{
	int i;

	i = 0;
	while (champ)
	{
		i++;
		champ = champ->next;
	}
	return (i);
}

void	init_map(unsigned char *dst, unsigned char *src /*int start*/, unsigned int bot_size, t_champ *var) // for the several bots;
{
	unsigned int i;
	int champs_quantity;

	i  = 0;
	champs_quantity = champ_quantity(var);
	while (i < MEM_SIZE)
		dst[i++] = '0';

	// first player;
	i = 0;
	while (i < bot_size)
	{
		dst[i] = src[i];
		i++;
	}


}	

void	display_map(unsigned char *map)
{
	unsigned int i;
	unsigned int lines;
	unsigned int spaces;

	i = 0;
	lines = 1;
	spaces = 1;
	while (i < MEM_SIZE)
	{
		if (map[i] != '0')
			ft_printf("%~.2x", F_GREEN, map[i]);
		else
		{
			ft_printf("%~c", F_WHITE, map[i]);
			ft_printf("%~c", F_WHITE, map[i]);
		}
		ft_printf(" ");
		if (lines == NEWLINE_QUANTITY)
		{
			ft_printf("\n");
			lines = 0;
		}
		lines++;
		spaces++;
		i++;
	}
}

void	cw_load_map()
{
	init_map(g_cw->map.stack, g_cw->pd.champs->code, g_cw->pd.champs->head.prog_size, g_cw->pd.champs);
	display_map(g_cw->map.stack);
}
