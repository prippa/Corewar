#include "corewar.h"

static unsigned char	cw_vis_get_color(int pc)
{
	if (g_cw.color_live_cycle_buf[pc])
		return (g_cw.color_map_live[pc]);
	else if (g_cw.color_map_pc[pc])
	{
		if (IS_BASE_COLOR(g_cw.color_map[pc]))
			return (g_cw.color_map[pc] + (F_BACK_GREEN_BLACK - 1));
		else
			return (F_BACK_GRAY_BLACK);
	}
	else if (g_cw.color_map_bold[pc])
		return (g_cw.color_map[pc] + (F_BOLD_GREEN - 1));
	else if (IS_BASE_COLOR(g_cw.color_map[pc]))
		return (g_cw.color_map[pc]);
	return (F_BOLD_GRAY);
}

static void				cw_vis_down_cycles_color(int pc)
{
	if (g_cw.color_map_bold[pc])
		g_cw.color_map_bold[pc]--;
	if (g_cw.color_live_cycle_buf[pc])
		g_cw.color_live_cycle_buf[pc]--;
}

void					cw_vis_print_map(char flag) // TRASH
{
	if (flag) system("clear");
	int i;
	int new_line_flag;

	i = 0;
	new_line_flag = 1;
	if (flag) ft_putstr("\n\n   ");
	while (i < MEM_SIZE)
	{
		if (flag) ft_printf("%~.2x ", cw_vis_get_color(i), g_cw.map[i]);
		cw_vis_down_cycles_color(i);
		if (new_line_flag == CW_BIT)
		{
			if (flag) ft_putstr("\n   ");
			new_line_flag = 1;
		}
		else
			new_line_flag++;
		i++;
	}
	ft_printf("\n************\nCycle: %u\n************\n", g_cw.cycle);
	ft_printf("cycle to die: %d\n", g_cw.cycle_to_die);
	ft_printf("proc count: %u\n", g_cw.proc_counter);
	if (flag) read(1, 0, 1);
	if (flag) system("clear");
}
