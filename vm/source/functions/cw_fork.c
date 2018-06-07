#include "corewar.h"

// Значение ((T_IND % IDX_MOD) плюс текущая позиция PC) является позицией,
// на которой создаётся копия текущего процесса, со всеми его параметрами (кроме позиции).

// value of the args < 0 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void			cw_fork(t_command *cmd, t_stack *map, t_processes *proc)
{
    int				position_on_the_map;



    position_on_the_map = MEM_CORRECTION(proc->process_PC + IDX_CORRECTION(cmd->arg1.av));

    position_on_the_map = (position_on_the_map < 0) ? MEM_SIZE + position_on_the_map : position_on_the_map;

    ft_printf("position_on_the_map -> %d\n", position_on_the_map);

    proc->process_PC = MEM_CORRECTION(
            proc->process_PC + cmd->arg1.tp + 1);

    ft_printf("process_PC -> %d\n", proc->process_PC);


//	 for testing;
    map->stack[proc->process_PC] = 7;
    map->stack_color[proc->process_PC] = 5;

    // TODO read(1, 0, 1);

    cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
