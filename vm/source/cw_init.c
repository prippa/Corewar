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

static void	cw_parse_data_init(t_parse_data *pd)
{
	pd->champs = NULL;
	pd->tmp = -1;
	pd->champs_count = 0;
	pd->nbr_cycles = 0;
	ft_bzero(pd->flags, CW_F_SIZE);
}
// TODO change init stuff, where else it may occur;
void		cw_init(void)
{
	if (!(g_cw = (t_corewar *)malloc(sizeof(t_corewar))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	cw_parse_data_init(&g_cw->pd);
	g_cw->proc_start = NULL;
	g_cw->proc_end = NULL;
	g_cw->loop = 1;
	g_cw->i = 0;
	g_cw->proc_counter = 0;
	g_cw->id_counter = 1;
}
