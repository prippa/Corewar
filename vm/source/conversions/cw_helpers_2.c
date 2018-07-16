#include "corewar.h"

int			cw_is_valid_reg(t_command *cmd)
{
	if ((cmd->arg1.tp == TP_REG && IS_INVALID_REG(cmd->arg1.av))
		|| (cmd->arg2.tp == TP_REG && IS_INVALID_REG(cmd->arg2.av))
		|| (cmd->arg3.tp == TP_REG && IS_INVALID_REG(cmd->arg3.av)))
		return (0);
	return (1);
}

int			cw_get_right_arg(t_processes *proc, char tp, int av)
{
	if (tp == TP_REG)
		return (proc->registers[av - 1]);
	return (av);
}
