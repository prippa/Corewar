#include "corewar.h"

#define IS_INVALID_REG(x) (x < 1 || x > REG_NUMBER)

int		cw_command_filter(t_command *cmd)
{
	if (cmd->arg1.tp == T_REG && IS_INVALID_REG(cmd->arg1.av))
	{
		return (INVALID_REG_AV);
	}
	else if (cmd->arg2.tp == T_REG && IS_INVALID_REG(cmd->arg2.av))
	{
		return (INVALID_REG_AV);
	}
	else if (cmd->arg3.tp == T_REG && IS_INVALID_REG(cmd->arg3.av))
	{
		return (INVALID_REG_AV);
	}
	return (0);
}
