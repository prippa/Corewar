/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_champ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:54:41 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:54:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			t_champ_sort_by_champ_number(t_champ **champs)
{
	t_champ *list;
	t_champ *next;
	t_champ *prev;

	list = *champs;
	prev = NULL;
	while (list->next)
	{
		next = list->next;
		if (list->champ_number < next->champ_number)
		{
			list->next = next->next;
			next->next = list;
			if (prev)
				prev->next = next;
			else
				*champs = next;
			list = *champs;
			prev = NULL;
			continue;
		}
		prev = list;
		list = list->next;
	}
}

void			t_champ_sort_by_order(t_champ **champs)
{
	t_champ *list;
	t_champ *next;
	t_champ *prev;

	list = *champs;
	prev = NULL;
	while (list->next)
	{
		next = list->next;
		if (list->order > next->order)
		{
			list->next = next->next;
			next->next = list;
			if (prev)
				prev->next = next;
			else
				*champs = next;
			list = *champs;
			prev = NULL;
			continue;
		}
		prev = list;
		list = list->next;
	}
}

void			t_champ_rev(t_champ **champs)
{
	t_champ *prev;
	t_champ *current;
	t_champ *next;

	prev = NULL;
	current = *champs;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*champs = prev;
}

void			t_champ_free(t_champ **champs)
{
	t_champ *tmp;

	while (*champs)
	{
		tmp = *champs;
		*champs = (*champs)->next;
		free(tmp);
	}
}

void			t_champ_add(t_champ **champs)
{
	t_champ *new_obj;

	if (!(new_obj = (t_champ *)malloc(sizeof(t_champ))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->fd = -1;
	ft_bzero(new_obj->file_name, FILE_NAME_MAX + 1);
	new_obj->head.magic = 0;
	ft_bzero(new_obj->head.prog_name, PROG_NAME_LENGTH + 1);
	new_obj->head.prog_size = 0;
	ft_bzero(new_obj->head.comment, COMMENT_LENGTH + 1);
	ft_bzero(new_obj->code, CHAMP_MAX_SIZE);
	new_obj->champ_number = 0;
	new_obj->order = 0;
	new_obj->lives_number = 0;
	new_obj->real_lives_number = 0;
	new_obj->last_live = 0;
	new_obj->color = 0;
	new_obj->next = *champs;
	*champs = new_obj;
}
