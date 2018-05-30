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
	// int champs_quantity;
	int map_distance;
	// int total_map_size;
	unsigned int i;
	unsigned int j;
	
	// champs_quantity = champ_quantity(champ);
	map_distance = MEM_SIZE / champ_quantity(champ);
	ft_printf("%d\n", map_distance);
	// total_map_size = MEM_SIZE;
	// while (total_map_size)
	// {
	// 	while (i < bot_size)
	// 	{
	// 		dst[i] = src[i];
	// 		i++;
	// 	}
	// 	i += map_distance;
	// 	total_map_size -= map_distance;
	// }
	i = 0;
	// j = 0;
	while (champ)
	{
		j = 0;
		ft_printf("i -> %u\n", i);
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
			ft_printf("%~.2x", F_GREEN, map[i]); // adopt + 1;
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
	init_map(g_cw->map.stack/*, g_cw->pd.champs->code, g_cw->pd.champs->head.prog_size, g_cw->pd.champs*/);

	fill_map_with_bots(g_cw->map.stack, g_cw->pd.champs);
	display_map(g_cw->map.stack);
}
