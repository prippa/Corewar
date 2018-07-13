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

static t_champ	*cw_get_winer_by_champ(t_champ *champs)
{
	t_champ	*winer;

	winer = champs;
	while (champs)
	{
		if (winer->last_live < champs->last_live)
			winer = champs;
		champs = champs->next;
	}
	return (winer);
}

void			cw_print_winer(t_champ *champs)
{
	t_champ		*champ;
	t_processes	*winer;
	t_processes	*proc;

	if (g_cw.proc_start)
	{
		proc = g_cw.proc_start;
		winer = proc;
		while (proc)
		{
			if (winer->last_live <= proc->last_live)
				winer = proc;
			proc = proc->next;
		}
		champ = t_champ_find(winer->champ_number, champs);
	}
	else
		champ = cw_get_winer_by_champ(champs);
	ft_printf("Contestant %d, \"%s\", has won !\n",
		(champ->champ_number * (-1)), champ->head.prog_name);
}
