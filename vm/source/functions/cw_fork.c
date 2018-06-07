#include "corewar.h"

// Значение ((T_IND % IDX_MOD) плюс текущая позиция PC) является позицией,
// на которой создаётся копия текущего процесса, со всеми его параметрами (кроме позиции).

void			cw_fork(t_command *cmd, t_stack *map, t_processes *proc)
{
    unsigned char	buf[4];
    // int i;
    int				position_on_the_map;
//	t_processes *proc;
    // int	arguments[3];
    //process;
//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);



    // ft_printf("2 -> %d\n", cmd->arg2.av);
    // ft_printf("3 -> %d\n", process->registers[cmd->arg3.av]);
    //
//	position_on_the_map +// to func;

    ft_printf("position_on_the_map -> %d\n", position_on_the_map);

    proc->process_PC = MEM_CORRECTION(
            proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 1);

    // (cmd->arg2.tp == 2) ? proc->process_PC += 1 : 0;
    // (cmd->arg2.tp == 1) ? proc->process_PC += 2 : 0;
    // (cmd->arg2.tp == 2 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;
    // (cmd->arg2.tp == 4 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;

    ft_printf("process_PC -> %d\n", proc->process_PC);

    // move the process_PC by the quantity of bytes;


    // process id // process parent;
    // get clear with it;
    // it will be found by the color ?;

    // process id in order to find the correct process;

    // ft_printf("%d", ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD));
    // position_on_the_map = 15;

    // i = 0; // argument type variation;
    // i = 0;
    // ft_printf("position_on_the_map -> %d\n", position_on_the_map);
//    cw_write_to_map(map, proc, buf, position_on_the_map);
// 	while (i < 4) // 2 || 4; // always take 4 bytes to the map;
// 	{
// 		if (position_on_the_map == MEM_SIZE)
// 			position_on_the_map = 0;
// 		// ft_printf("position_on_the_map -> %d", position_on_the_map);

// 		map->stack[position_on_the_map] = buf[i++];
// 		map->stack_color[position_on_the_map++] = proc->color;
// //		map->stack_process_id[position_on_the_map++] = proc->id;
// 	}

    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // each process has the color of the parent;

//	 for testing;
    map->stack[proc->process_PC] = 7;
    map->stack_color[proc->process_PC] = 5;

    // TODO read(1, 0, 1);

    cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
