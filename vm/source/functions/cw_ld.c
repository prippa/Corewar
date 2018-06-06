#include "corewar.h"

void			cw_ld(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{
//	t_processes *proc;

//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);
	if (cmd->arg1.tp == 4)
		proc->registers[cmd->arg2.av - 1] = cmd->arg1.av;
	else
	{
		cmd->arg1.av = cmd->arg1.av % IDX_MOD;
		proc->registers[cmd->arg2.av - 1] =
		cw_get_dec_from_the_point(map->stack,
		4,
		(proc->process_PC + cmd->arg1.av) % MEM_SIZE); // TODO check out -> process_PC;
		proc->process_PC += cmd->arg1.tp + cmd->arg2.tp + 2;
	}
	proc->carry = (proc->registers[cmd->arg2.av - 1] == 0 ? 1 : 0); // carry
	 map->stack[proc->process_PC] = 7;
	 map->stack_color[proc->process_PC] = 5;

	 ft_printf("process_carry -> %d\n\n", proc->carry);

	 cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
