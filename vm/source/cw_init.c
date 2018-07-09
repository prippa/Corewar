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

static void cw_get_op(void)
{
	const t_op op_tab[] =
	{
		{&cw_live, 10, 0, 4},
		{&cw_ld, 5, 1, 4},
		{&cw_st, 5, 1, 4},
		{&cw_add, 10, 1, 4},
		{&cw_sub, 10, 1, 4},
		{&cw_binary_and, 6, 1, 4},
		{&cw_binary_or, 6, 1, 4},
		{&cw_binary_xor, 6, 1, 4},
		{&cw_zjmp, 20, 0, 2},
		{&cw_ldi, 25, 1, 2},
		{&cw_sti, 25, 1, 2},
		{&cw_fork, 800, 0, 2},
		{&cw_lld, 10, 1, 4},
		{&cw_lldi, 50, 1, 2},
		{&cw_lfork, 1000, 0, 2},
		{&cw_aff, 2, 1, 4}
	};
	g_cw.op = op_tab;
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
	ft_bzero(g_cw.color_map, MEM_SIZE);
	cw_get_op();
	g_cw.cycle = 0;
	g_cw.cycle_to_die = CYCLE_TO_DIE;
	g_cw.cycle_to_die_check = CYCLE_TO_DIE;
	g_cw.max_checks_check = MAX_CHECKS;
	g_cw.proc_counter = 0;
	g_cw.id_counter = 1;
}
