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

static void	cw_functions_init(void)
{
	g_cw->op[LIVE - 1] = cw_live;
	g_cw->op[LD - 1] = cw_ld;
	// g_cw->op[ST - 1] = cw_st;
	g_cw->op[ADD - 1] = cw_add;
	g_cw->op[SUB - 1] = cw_sub;
	g_cw->op[AND - 1] = cw_binary_and;
	g_cw->op[OR - 1] = cw_binary_or;
	g_cw->op[XOR - 1] = cw_binary_xor;
	// g_cw->op[ZJMP - 1] = cw_zjump;
	g_cw->op[LDI - 1] = cw_ldi;
	g_cw->op[STI - 1] = cw_sti;
	// g_cw->op[FORK - 1] = cw_fork;
	g_cw->op[LLD - 1] = cw_lld;
	g_cw->op[LLDI - 1] = cw_lldi;
	// g_cw->op[LFORK - 1] = cw_lfork;
	// g_cw->op[AFF - 1] = cw_aff;
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
	cw_functions_init();
	g_cw->proc_start = NULL;
	g_cw->proc_end = NULL;
	g_cw->loop = 1;
	g_cw->i = 0;
	g_cw->proc_counter = 0;
	g_cw->id_counter = 1;
}
