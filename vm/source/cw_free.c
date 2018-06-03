/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:18 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:56:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	cw_parse_data_free(t_parse_data *pd)
{
	t_champ_free(&pd->champs);
}

static void	cw_processes_free(t_processes **proc_start, t_processes **proc_end)
{
	while (*proc_start)
		t_processe_free_one(proc_start, proc_end);
}

void		cw_free(void)
{
	cw_parse_data_free(&g_cw->pd);
	cw_processes_free(&g_cw->proc_start, &g_cw->proc_end);
	free(g_cw);
}
