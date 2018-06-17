#include "corewar.h"

void		cw_print_players(t_champ *champs)
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

void		cw_print_winer(t_champ *champs)
{
	t_champ	*winer;

	winer = champs;
	while (champs)
	{
		if (winer->last_live < champs->last_live)
			winer = champs;
		champs = champs->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
		(winer->champ_number * (-1)), winer->head.prog_name);
}
