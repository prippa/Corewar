#include "corewar.h"

void		cw_move_pc_with_codage(t_command *cmd, t_processes *proc)
{
	cw_move_pc(proc, (cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2));
}

void		cw_move_pc_without_codage(t_processes *proc)
{
	cw_move_pc(proc, (g_cw.op[proc->cmd - 1].label + 1));
}

void		cw_move_pc(t_processes *proc, int value)
{
	if ((proc->pc = MEM_X((proc->pc + value))) < 0)
		proc->pc += MEM_SIZE;
	if (IS_COMMAND(g_cw.map[proc->pc]))
	{
		proc->cmd = g_cw.map[proc->pc];
		proc->exec_cycles = g_cw.op[proc->cmd - 1].cycles_price - 1;
	}
	else
		proc->exec_cycles = -1;
}
