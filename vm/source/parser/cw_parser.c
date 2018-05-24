#include "corewar.h"

static void	cw_check_magic(t_champ *champ)
{
	char	head[REG_SIZE + 1];
	char	cem_txt[REG_SIZE + 1];
	int		cem = COREWAR_EXEC_MAGIC;

	ft_bzero(cem_txt, REG_SIZE + 1);
	ft_memcpy(cem_txt, (void *)(&cem), REG_SIZE);
	ft_memrev(cem_txt, REG_SIZE);
	if ((read(champ->fd, head, REG_SIZE)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	if (ft_memcmp(head, cem_txt, REG_SIZE) != 0)
		cw_exit(champ->file_name, HEADER);
}

static void	cw_get_prog_name(t_champ *champ)
{
	char	buf[PROG_NAME_LENGTH + 1];
	int		ret;

	ft_bzero(buf, PROG_NAME_LENGTH + 1);
	if ((ret = read(champ->fd, buf, PROG_NAME_LENGTH)) < 0)
		cw_perror_exit(champ->file_name, READ_FILE);
	else if (ret < PROG_NAME_LENGTH)
		cw_exit(champ->file_name, PROG_NAME);
	ft_strcpy(champ->prog_name, buf);
}

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
}

void		cw_parser(void)
{
	t_champ *champs;

	champs = g_cw->pd.champs;
	while (champs)
	{
		cw_parse_file(champs);
		champs = champs->next;
	}
}
