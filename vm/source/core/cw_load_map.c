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

void	fill_map_with_bots(unsigned char *dst, t_champ *champ)
{
	int				map_distance;
	unsigned int	i;
	unsigned int	j;

	map_distance = MEM_SIZE / champ_quantity(champ);
	i = 0;
	while (champ)
	{
		j = 0;
		while (j < champ->head.prog_size)
		{
			dst[i] = champ->code[j];
			i++;
			j++;
		}
		i += map_distance - j;
		champ = champ->next;
	}
}

void	init_map(unsigned char *dst)
{
	unsigned int i;

	i  = 0;
	while (i < MEM_SIZE)
		dst[i++] = '0';
}	

void	display_map(unsigned char *map) // parallel array in a stack for the colors;
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

void	cw_load_map(void)
{
	init_map(g_cw->map.stack);

	fill_map_with_bots(g_cw->map.stack, g_cw->pd.champs);
	display_map(g_cw->map.stack);
}
