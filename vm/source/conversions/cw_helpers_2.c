#include "corewar.h"

int			cw_is_valid_reg(t_command *cmd)
{
	if ((cmd->arg1.tp == REG && IS_INVALID_REG(cmd->arg1.av))
		|| (cmd->arg2.tp == REG && IS_INVALID_REG(cmd->arg2.av))
		|| (cmd->arg3.tp == REG && IS_INVALID_REG(cmd->arg3.av)))
		return (0);
	return (1);
}

void		cw_move_pc(t_command *cmd, t_processes *proc)
{
	proc->pc = MEM_X(
		(proc->pc + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp +
			g_cw.op[proc->cmd - 1].codage_octal + 1));
}

void		cw_init_proc_cmd(t_processes *proc, unsigned char cmd)
{
	proc->cmd = cmd;
	proc->exec_cycles = g_cw.op[cmd - 1].cycles_price - 1;
}
