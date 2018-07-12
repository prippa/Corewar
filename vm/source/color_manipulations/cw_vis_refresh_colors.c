#include "corewar.h"

void		cw_vis_write_new_color(unsigned char color, int pc, int len)
{
	int i;

	i = 0;
	if ((pc = MEM_X(pc)) < 0)
		pc += MEM_SIZE;
	while (i < len)
	{
		g_cw.color_map[pc] = color;
		g_cw.color_map_bold[pc] = CYCLES_LIGHT;
		pc = MEM_X((pc + 1));
		i++;
	}
}
