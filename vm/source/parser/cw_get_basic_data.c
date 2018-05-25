#include "corewar.h"

void		cw_check_magic(t_champ *champ)
{
	char			magic[REG_SIZE];

	ft_bzero(magic, REG_SIZE);
	if ((read(champ->fd, magic, REG_SIZE)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	champ->head.magic = cw_hex_to_dec((unsigned char (*)[])magic);
	if (champ->head.magic != COREWAR_EXEC_MAGIC)
		cw_exit(champ->file_name, HEADER);
}

void		cw_get_prog_name(t_champ *champ)
{
	char	buf[PROG_NAME_LENGTH + 1];
	int		ret;

	ft_bzero(buf, PROG_NAME_LENGTH + 1);
	if ((ret = read(champ->fd, buf, PROG_NAME_LENGTH)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	else if (ret < PROG_NAME_LENGTH)
		cw_exit(champ->file_name, PROG_NAME);
	ft_strcpy(champ->head.prog_name, buf);
}

void		cw_get_prog_size(t_champ *champ)
{
	char	buf[REG_SIZE];

	cw_lseek_cur_skip(champ->fd, REG_SIZE);
	ft_bzero(buf, REG_SIZE);
	if ((read(champ->fd, buf, REG_SIZE)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	champ->head.prog_size = cw_hex_to_dec((unsigned char (*)[])buf);
	if (champ->head.prog_size > CHAMP_MAX_SIZE)
	{
		g_cw->pd.tmp = champ->head.prog_size;
		cw_exit(champ->file_name, PROG_SIZE_TO_BIG);
	}
}

void		cw_get_comment(t_champ *champ)
{
	char	buf[COMMENT_LENGTH + 1];
	int		ret;

	ft_bzero(buf, COMMENT_LENGTH + 1);
	if ((ret = read(champ->fd, buf, COMMENT_LENGTH)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	else if (ret < COMMENT_LENGTH)
		cw_exit(champ->file_name, COMMENT);
	ft_strcpy(champ->head.comment, buf);
}
