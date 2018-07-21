/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_basic_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:55:02 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:55:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cw_check_magic(t_champ *champ)
{
	unsigned char	buf[REG_SIZE];

	ft_bzero(buf, REG_SIZE);
	if ((read(champ->fd, buf, REG_SIZE)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	champ->head.magic = cw_hex_to_dec(buf, 4);
	if (champ->head.magic != COREWAR_EXEC_MAGIC)
		cw_exit(champ->file_name, HEADER);
}

void		cw_get_prog_name(t_champ *champ)
{
	char	buf[PROG_NAME_LENGTH + 1];

	ft_bzero(buf, PROG_NAME_LENGTH + 1);
	if ((g_cw.pd.tmp = read(champ->fd, buf, PROG_NAME_LENGTH)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	else if (g_cw.pd.tmp < PROG_NAME_LENGTH)
		cw_exit(champ->file_name, PROG_NAME);
	ft_strcpy(champ->head.prog_name, buf);
}

void		cw_get_prog_size(t_champ *champ)
{
	unsigned char	buf[REG_SIZE];

	cw_separator_skip(champ->file_name, champ->fd, REG_SIZE);
	ft_bzero(buf, REG_SIZE);
	if ((read(champ->fd, buf, REG_SIZE)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	champ->head.prog_size = cw_hex_to_dec(buf, 4);
	if (champ->head.prog_size > CHAMP_MAX_SIZE)
	{
		g_cw.pd.tmp = champ->head.prog_size;
		cw_exit(champ->file_name, PROG_SIZE_TO_BIG);
	}
}

void		cw_get_comment(t_champ *champ)
{
	char	buf[COMMENT_LENGTH + 1];

	ft_bzero(buf, COMMENT_LENGTH + 1);
	if ((g_cw.pd.tmp = read(champ->fd, buf, COMMENT_LENGTH)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	else if (g_cw.pd.tmp < COMMENT_LENGTH)
		cw_exit(champ->file_name, COMMENT);
	ft_strcpy(champ->head.comment, buf);
}

void		cw_get_prog_code(t_champ *champ)
{
	unsigned char	buf[champ->head.prog_size + 2];

	cw_separator_skip(champ->file_name, champ->fd, REG_SIZE);
	ft_bzero(buf, champ->head.prog_size + 2);
	if ((g_cw.pd.tmp = read(champ->fd, buf, champ->head.prog_size + 1)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	if ((unsigned int)g_cw.pd.tmp != champ->head.prog_size)
		cw_exit(champ->file_name, PROG_SIZE_INVALID);
	ft_memcpy(champ->code, buf, champ->head.prog_size);
}
