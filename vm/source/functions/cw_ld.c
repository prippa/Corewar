#include "corewar.h"

void	cw_ld(t_command *cmd, t_stack *map, unsigned int process_id)
{
	t_processes *proc;

	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
	if (cmd->arg1.tp == 4)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
	{
		cmd->arg1.av = cmd->arg1.av % IDX_MOD;
		
	}
	proc->carry = (cmd->arg1.av == 0 ? 1 : 0);//carry
	ft_printf("carry = %d\n", proc->carry);
	for(int i = 0; i < REG_NUMBER; i++)
		ft_printf("%d ", proc->registers[i]);
}
