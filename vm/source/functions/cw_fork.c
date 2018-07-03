#include "corewar.h"

// Значение ((T_IND % IDX_MOD) плюс текущая позиция PC) является позицией,
// на которой создаётся копия текущего процесса, со всеми его параметрами (кроме позиции).

void			cw_fork(t_command *cmd, t_stack *map, t_processes *proc)
{
    ft_printf("fork\n");
    if (proc->process_PC > 4095 || proc->process_PC < 0)
    {
        ft_printf("fork\n");
         getchar();
    }

    int				position_on_the_map;

    position_on_the_map = MEM_CORRECTION((proc->process_PC + IDX_CORRECTION(cmd->arg1.av)));
    position_on_the_map = (position_on_the_map < 0) ? MEM_SIZE + position_on_the_map : position_on_the_map;

        if (position_on_the_map > 4095 || position_on_the_map < 0)
    {
        ft_printf("fork position\n");
        getchar();
    }

    // ft_printf("position_on_the_map -> %d\n", position_on_the_map);

    // position on the map will be a process_PC for the new process;

    map->stack_color[proc->process_PC] = proc->color;


    proc->process_PC = MEM_CORRECTION((proc->process_PC + cmd->arg1.tp + 1));
    ft_printf("process_PC -> %d\n", proc->process_PC);

    if (proc->process_PC > 4095 || proc->process_PC < 0)
    {
        ft_printf("fork\n");
        getchar();
    }

    map->stack_color[proc->process_PC] = proc->proc_process_PC_color;

    // ft_printf("process_PC -> %d\n", proc->process_PC);

    // t_processes *clone;

    // clone = proc;

    // while (clone->next)
    // {
        // ft_printf("id -> %u\n", clone->id);
        // clone = clone->next;
    // }

    t_processes_copy(&g_cw->proc_start, &g_cw->proc_end, proc, position_on_the_map);
    

    // while (clone->next)
    // {
        // ft_printf("end id -> %u\n", g_cw->proc_end->id);
        // ft_printf("process_PC -> %d\n", g_cw->proc_end->process_PC);

        // clone = clone->next;
    // }



    // //	 for testing;
    // map->stack[proc->process_PC] = 7;
    // map->stack_color[proc->process_PC] = 5;

    // TODO read(1, 0, 1);

    // cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
