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

void		cw_free(void)
{
	cw_parse_data_free(&g_cw->pd);
	free(g_cw); // i think that is why i have leaks;
}
