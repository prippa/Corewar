#include "corewar.h"

#define IS_VALID_REG(x) (x < 1 || x > REG_NUMBER)

int		cw_command_filter(t_command *cmd)
{
	if (cmd->arg1.tp == 1 && IS_VALID_REG(cmd->arg1.av))
	{
		return (INVALID_REG_AV);
		// exit(0);
	}
	else if (cmd->arg2.tp == 1 && IS_VALID_REG(cmd->arg2.av))
	{
		return (INVALID_REG_AV);
		// exit(0);
	}
	else if (cmd->arg3.tp == 1 && IS_VALID_REG(cmd->arg3.av))
	{
		return (INVALID_REG_AV);
		// exit(0);
	}
	return (0);
}
