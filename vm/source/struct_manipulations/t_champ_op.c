/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_champ_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:04:24 by prippa            #+#    #+#             */
/*   Updated: 2018/07/14 16:04:25 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			t_champ_is_nbr_live(t_champ *champs)
{
	unsigned int count;

	count = 0;
	while (champs)
	{
		count += champs->real_lives_number;
		champs = champs->next;
	}
	return ((count >= NBR_LIVE) ? 1 : 0);
}

t_champ		*t_champ_find(int champ_number, t_champ *list)
{
	while (list)
	{
		if (list->champ_number == champ_number)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void		t_champ_zero_lives_number(t_champ *champs)
{
	while (champs)
	{
		champs->lives_number = 0;
		champs->real_lives_number = 0;
		champs = champs->next;
	}
}

int			t_champ_check_double_champ_number(t_champ *champs, int order)
{
	while (champs)
	{
		if (champs->order == order)
			return (1);
		champs = champs->next;
	}
	return (0);
}
