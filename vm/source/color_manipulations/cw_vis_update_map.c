/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_print_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:57:30 by prippa            #+#    #+#             */
/*   Updated: 2018/07/14 15:57:31 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned char	cw_vis_get_color(int pc)
{
	if (g_cw.mp.color_live_cycle_buf[pc])
		return (g_cw.mp.color_map_live[pc]);
	else if (g_cw.mp.color_map_pc[pc])
	{
		if (IS_BASE_COLOR(g_cw.mp.color_map[pc]))
			return (g_cw.mp.color_map[pc] + (F_BACK_GREEN_BLACK - 1));
		else
			return (F_BACK_GRAY_BLACK);
	}
	else if (g_cw.mp.color_map_bold[pc])
		return (g_cw.mp.color_map[pc] + (F_BOLD_GREEN - 1));
	else if (IS_BASE_COLOR(g_cw.mp.color_map[pc]))
		return (g_cw.mp.color_map[pc]);
	return (F_BOLD_GRAY);
}

static void				cw_vis_down_cycles_color(int pc)
{
	if (g_cw.mp.color_map_bold[pc])
		g_cw.mp.color_map_bold[pc]--;
	if (g_cw.mp.color_live_cycle_buf[pc])
		g_cw.mp.color_live_cycle_buf[pc]--;
}

void					cw_vis_update_map(void)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		g_cw.mp.colors[i] = cw_vis_get_color(i);
		cw_vis_down_cycles_color(i);
		i++;
	}
}
