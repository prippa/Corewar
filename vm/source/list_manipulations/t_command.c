#include "corewar.h"

void	t_command_free(t_command **cmds)
{
	while (*cmds)
	{
		free(*cmds);
		*cmds = (*cmds)->next;
	}
}

void	t_command_add(t_command **cmds)
{
	t_command *new_obj;

	if (!(new_obj = (t_command *)malloc(sizeof(t_command))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->cmd = 0;
	new_obj->codage = 0;
	new_obj->arg1.av = 0;
	new_obj->arg1.tp = 0;
	new_obj->arg2.av = 0;
	new_obj->arg2.tp = 0;
	new_obj->arg3.av = 0;
	new_obj->arg3.tp = 0;
	new_obj->next = *cmds;
	*cmds = new_obj;
}
