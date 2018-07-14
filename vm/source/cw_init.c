/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:25 by prippa            #+#    #+#             */
/*   Updated: 2018/06/07 15:46:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

struct s_corewar g_cw;

static void	cw_op_init_label(void)
{
	g_cw.op[0].label = 4;
	g_cw.op[1].label = 4;
	g_cw.op[2].label = 4;
	g_cw.op[3].label = 4;
	g_cw.op[4].label = 4;
	g_cw.op[5].label = 4;
	g_cw.op[6].label = 4;
	g_cw.op[7].label = 4;
	g_cw.op[8].label = 2;
	g_cw.op[9].label = 2;
	g_cw.op[10].label = 2;
	g_cw.op[11].label = 2;
	g_cw.op[12].label = 4;
	g_cw.op[13].label = 2;
	g_cw.op[14].label = 2;
	g_cw.op[15].label = 4;
}

static void	cw_op_init_cycles_price(void)
{
	g_cw.op[0].cycles_price = 10;
	g_cw.op[1].cycles_price = 5;
	g_cw.op[2].cycles_price = 5;
	g_cw.op[3].cycles_price = 10;
	g_cw.op[4].cycles_price = 10;
	g_cw.op[5].cycles_price = 6;
	g_cw.op[6].cycles_price = 6;
	g_cw.op[7].cycles_price = 6;
	g_cw.op[8].cycles_price = 20;
	g_cw.op[9].cycles_price = 25;
	g_cw.op[10].cycles_price = 25;
	g_cw.op[11].cycles_price = 800;
	g_cw.op[12].cycles_price = 10;
	g_cw.op[13].cycles_price = 50;
	g_cw.op[14].cycles_price = 1000;
	g_cw.op[15].cycles_price = 2;
}

static void	cw_get_op(void)
{
	g_cw.op[0].func = &cw_live;
	g_cw.op[1].func = &cw_ld;
	g_cw.op[2].func = &cw_st;
	g_cw.op[3].func = &cw_add;
	g_cw.op[4].func = &cw_sub;
	g_cw.op[5].func = &cw_binary_and;
	g_cw.op[6].func = &cw_binary_or;
	g_cw.op[7].func = &cw_binary_xor;
	g_cw.op[8].func = &cw_zjmp;
	g_cw.op[9].func = &cw_ldi;
	g_cw.op[10].func = &cw_sti;
	g_cw.op[11].func = &cw_fork;
	g_cw.op[12].func = &cw_lld;
	g_cw.op[13].func = &cw_lldi;
	g_cw.op[14].func = &cw_lfork;
	g_cw.op[15].func = &cw_aff;
	cw_op_init_cycles_price();
	cw_op_init_label();
}

static void	cw_parse_data_init(t_parse_data *pd)
{
	pd->champs = NULL;
	pd->tmp = 0;
	pd->champs_count = 0;
	pd->dump_stop = 0;
	ft_bzero(pd->flags, CW_F_SIZE);
	ft_bzero(pd->flag_champ_number, MAX_PLAYERS);
}

void		cw_init(void)
{
	cw_parse_data_init(&g_cw.pd);
	ft_bzero(g_cw.map, MEM_SIZE);
	ft_bzero(g_cw.colors, MEM_SIZE);
	ft_bzero(g_cw.color_map, MEM_SIZE);
	ft_bzero(g_cw.color_map_pc, MEM_SIZE);
	ft_bzero(g_cw.color_map_bold, MEM_SIZE);
	ft_bzero(g_cw.color_map_live, MEM_SIZE);
	ft_bzero(g_cw.color_live_cycle_buf, MEM_SIZE);
	cw_get_op();
	g_cw.proc_start = NULL;
	g_cw.proc_end = NULL;
	g_cw.cycle = 0;
	g_cw.cycle_to_die = CYCLE_TO_DIE;
	g_cw.cycle_to_die_check = CYCLE_TO_DIE;
	g_cw.max_checks_check = MAX_CHECKS;
	g_cw.proc_counter = 0;
	g_cw.last_reported_to_be_alive = -1;
	g_cw.game_over = 1;
}
