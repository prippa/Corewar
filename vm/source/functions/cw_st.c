#include "corewar.h"

void			cw_st(t_command *cmd, t_stack *map, t_processes *proc)
{
	int				index;
	unsigned char	buf[4];

	if (cmd->arg2.tp == 1)
		proc->registers[cmd->arg2.av - 1] = proc->registers[cmd->arg1.av - 1];
	else
	{
		cw_write_bytes_to_buf(buf, proc->registers[cmd->arg1.av - 1]);
		if ((index = MEM_CORRECTION(
			proc->process_PC + IDX_CORRECTION(cmd->arg2.av))) < 0)
			index = MEM_SIZE + index;
		cw_write_to_map(map, proc, buf, index);
		// ft_printf("INDEX ----- %d\n", index);
	}
	proc->process_PC = MEM_CORRECTION(
		proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + 2);

		// map->stack[proc->process_PC] = 7;
		// map->stack_color[proc->process_PC] = 5;
		// ft_printf("process_carry -> %d\n\n", proc->carry);
		cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
