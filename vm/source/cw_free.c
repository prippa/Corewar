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

static void	cw_processes_free(void)
{
	while (g_cw.proc_start)
		t_processe_free_by_obj(&g_cw.proc_start, &g_cw.proc_end,
			g_cw.proc_start);
}

static void	cw_parse_data_free(void)
{
	t_champ_free(&g_cw.pd.champs);
}

void		cw_free(void)
{
	cw_parse_data_free();
	cw_processes_free();
}
