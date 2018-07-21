/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:45 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_separator_skip(char *file_name, int fd, const long size)
{
	unsigned char	buf[size];
	unsigned int	i;

	if ((read(fd, buf, size)) < 0)
		cw_perror_exit(file_name, READ_FILE);
	i = -1;
	while (++i < size)
		if (buf[i] != 0)
			cw_exit(file_name, NOT_NULL_BITES);
	// if ((lseek(fd, size, SEEK_CUR)) < 0)
	// 	cw_perror_exit(ERR_LSEEK_CUR_MESSAGE, LSEEK);
}

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
	cw_get_prog_size(champ);
	cw_get_comment(champ);
	cw_get_prog_code(champ);
}

void		cw_parser(void)
{
	t_champ *champs;

	champs = g_cw.pd.champs;
	while (champs)
	{
		cw_parse_file(champs);
		close(champs->fd);
		champs = champs->next;
	}
}
