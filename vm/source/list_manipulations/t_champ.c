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

void	t_champ_free(t_champ **champs)
{
	while (*champs)
	{
		close((*champs)->fd);
		ft_str_free(&(*champs)->code);
		free(*champs);
		*champs = (*champs)->next;
	}
}

void	t_champ_add(t_champ **champs)
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
	new_obj->code = NULL;
	new_obj->next = *champs;
	*champs = new_obj;
}
