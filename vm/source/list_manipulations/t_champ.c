#include "corewar.h"

void	t_champ_free(t_champ **champs)
{
	while (*champs)
	{
		free(*champs);
		*champs = (*champs)->next;
	}
}

void	t_champ_add(t_champ **champs)
{
	
}
