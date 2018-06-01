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

static void	cw_processes_free(t_processes *head_ref)
{
	if (!head_ref)
		return ;
	if (head_ref->next)
		cw_processes_free(head_ref->next);
	free(head_ref);
}

void		cw_free(void)
{
	cw_parse_data_free(&g_cw->pd);
	cw_processes_free(g_cw->processes);
	free(g_cw);
}
