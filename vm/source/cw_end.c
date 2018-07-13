#include "corewar.h"

void			cw_print_players(t_champ *champs)
{
	ft_putstr("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			(champs->champ_number * (-1)), champs->head.prog_size,
			champs->head.prog_name, champs->head.comment);
		champs = champs->next;
	}
}

void			cw_print_winer(t_champ *champs)
{
	t_champ *champ;

	champ = t_champ_find(g_cw.last_reported_to_be_alive, champs);
	ft_printf("Contestant %d, \"%s\", has won !\n",
		(champ->champ_number * (-1)), champ->head.prog_name);
}
