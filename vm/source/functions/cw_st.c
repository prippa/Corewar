#include "corewar.h"

void			cw_st(t_command *cmd, t_stack *map, t_processes *proc)
{
	unsigned short index;

	if (cmd->arg2.tp == 1)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
	{
		index = ABS(MEM_CORRECTION(proc->process_PC + IDX_CORRECTION(cmd->arg2.av)));
		ft_printf("INDEX ----- %d\n", index);
		map->stack[index] = cmd->arg1.av;
		map->stack_color[index] = proc->color;
	}
	proc->process_PC = MEM_CORRECTION(
		proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + 2);

		map->stack[proc->process_PC] = 7;
		map->stack_color[proc->process_PC] = 5;
		ft_printf("process_carry -> %d\n\n", proc->carry);
		cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
