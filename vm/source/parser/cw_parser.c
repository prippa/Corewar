#include "corewar.h"

static void	cw_parse_file(t_champ *champ)
{
	cw_check_magic(champ);
	cw_get_prog_name(champ);
	cw_get_prog_size(champ);
	cw_get_comment(champ);

	ft_printf("magic = (%u) | prog name = (%s) | prog size = (%u) | comment = (%s)\n",
	champ->head.magic, champ->head.prog_name, champ->head.prog_size, champ->head.comment);
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
