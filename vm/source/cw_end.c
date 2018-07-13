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
	t_champ		*champ;
	t_processes	*winer;
	t_processes	*proc;

	proc = g_cw.proc_start;
	winer = proc;
	while (proc)
	{
		if (proc->last_live >= winer->last_live)
			winer = proc;
		proc = proc->next;
	}
	champ = t_champ_find(winer->champ_number, champs);
	ft_printf("Contestant %d, \"%s\", has won !\n",
		(champ->champ_number * (-1)), champ->head.prog_name);
}
