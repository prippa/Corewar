/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:25 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:56:27 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

struct s_corewar *g_cw;

static void cw_get_op(void)
{
	const t_op op_tab[] =
	{
		{&cw_live, 10},
		{&cw_ld, 5},
		{&cw_st, 5},
		{&cw_add, 10},
		{&cw_sub, 10},
		{&cw_binary_and, 6},
		{&cw_binary_or, 6},
		{&cw_binary_xor, 6},
		{&cw_zjmp, 20},
		{&cw_ldi, 25},
		{&cw_sti, 25},
		{&cw_fork, 800},
		{&cw_lld, 10},
		{&cw_lldi, 50},
		{&cw_lfork, 1000},
		{&cw_aff, 2}
	};
	g_cw->op = op_tab;
//	todo int i = g_cw->op[FORK - 1].func();
}

static void	cw_parse_data_init(t_parse_data *pd)
{
	pd->champs = NULL;
	pd->tmp = -1;
	pd->champs_count = 0;
	pd->nbr_cycles = 0;
	ft_bzero(pd->flags, CW_F_SIZE);
}

void		cw_init(void)
{
	if (!(g_cw = (t_corewar *)malloc(sizeof(t_corewar))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	cw_parse_data_init(&g_cw->pd);
	cw_get_op();
	g_cw->proc_start = NULL;
	g_cw->proc_end = NULL;
	g_cw->loop = 1;
	g_cw->i = 0;
	g_cw->proc_counter = 0;
	g_cw->id_counter = 1;
}
