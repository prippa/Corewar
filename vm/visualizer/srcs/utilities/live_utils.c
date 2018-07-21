/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:08:17 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/21 16:08:19 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			get_live_sum(void)
{
	int		sum;
	t_champ	*tmp;

	tmp = g_cw.pd.champs;
	sum = 0;
	while (tmp)
	{
		sum += tmp->lives_number;
		tmp = tmp->next;
	}
	return ((sum == 0) ? 1 : sum);
}

int			get_live(int index)
{
	t_champ	*tmp;

	tmp = g_cw.pd.champs;
	while (index--)
		tmp = tmp->next;
	return (tmp->lives_number);
}

int			get_max(void)
{
	int		max;
	t_champ	*tmp;

	tmp = g_cw.pd.champs;
	max = 0;
	while (tmp)
	{
		if (tmp->lives_number > (unsigned int)max)
			max = tmp->lives_number;
		tmp = tmp->next;
	}
	return (max);
}
