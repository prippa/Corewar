#include "corewar.h"

// Значение ((T_IND % IDX_MOD) плюс текущая позиция PC) является позицией,
// на которой создаётся копия текущего процесса, со всеми его параметрами (кроме позиции).

int             cw_find_the_same_PC(t_champ *champs, int cur_PC, unsigned int id, int cycles_till_execution)
{
    t_processes *process_branch = NULL;

    while (champs)
    {
        process_branch = champs->proc_start;
  
        while (process_branch)
        {
            if (cur_PC == process_branch->process_PC && process_branch->id != id && cycles_till_execution < process_branch->cycles_till_execution)
            {

                ft_putstr("here in\n");
                ft_printf("cur_PC->%d process_branch->process_PC->%d\n",process_branch->process_PC,process_branch->process_PC);
                ft_printf("proc id->%d\n", process_branch->id);
                getchar();
               return(1);
            }

            process_branch = process_branch->next;
        }
        champs = champs->next;
    }
    return(0);

}

int             cw_get_same_position_detection(t_champ *champs)
{
    t_processes *process_branch = NULL;
    // int cur_PC;

    while (champs)
    {
        process_branch = champs->proc_start;
  
        while (process_branch)
        {
            // cur_PC = process_branch->process_PC;
            if (cw_find_the_same_PC(g_cw.pd.champs, process_branch->process_PC, process_branch->id, process_branch->cycles_till_execution))
            {
                ft_putstr("here out\n");
                ft_printf("cur_PC->%d process_branch->process_PC->%d\n",process_branch->process_PC,process_branch->process_PC);
                ft_printf("proc id->%d\n", process_branch->id);
                getchar();
                return(1);
            }
            process_branch = process_branch->next;

        }
        champs = champs->next;
    }
    return(0);
}


void			cw_fork(t_command *cmd, t_stack *map, t_processes *proc)
{
    int found_the_fork_with_same_process_PC = 0;
    t_champ *champs = g_cw.pd.champs;

    if (g_cw.cycle >= 5314)
    {
        found_the_fork_with_same_process_PC = cw_get_same_position_detection(champs);
    }
    
    int     position_on_the_map;
    t_champ *champ;

    champ = t_champ_find(proc->champ_number, g_cw.pd.champs);
    // ft_printf("champ live color -> %d\n", champ->proc_start->live_color);
    // getchar();
    if ((position_on_the_map = MEM_CORRECTION((proc->process_PC + IDX_CORRECTION(cmd->arg1.av)))) < 0)
        position_on_the_map += MEM_SIZE;
    // ft_printf("position_on_the_map -> %d\n", position_on_the_map);

    // position on the map will be a process_PC for the new process;
    if (!found_the_fork_with_same_process_PC)
    map->stack_color[proc->process_PC] = proc->color;
    //     if (position_on_the_map > 4095 || position_on_the_map < 0)
    // {
    //     ft_printf("fork\n");
    //     getchar();
    // }

    proc->process_PC = MEM_CORRECTION((proc->process_PC + cmd->arg1.tp + 1));
    //     if (proc->process_PC > 4095 || proc->process_PC < 0)
    // {
    //     ft_printf("fork\n");
    //     getchar();
    // }
    // ft_printf("process_PC -> %d\n", proc->process_PC);


    map->stack_color[proc->process_PC] = proc->proc_process_PC_color;
    //     if (proc->process_PC > 4095 || proc->process_PC < 0)
    // {
    //     ft_printf("fork\n");
    //     getchar();
    // }

    // ft_printf("process_PC -> %d\n", proc->process_PC);

    // t_processes *clone;

    // clone = proc;

    // while (clone->next)
    // {
        // ft_printf("id -> %u\n", clone->id);
        // clone = clone->next;
    // }

    t_processes_copy(&champ->proc_start, &champ->proc_end, &proc, position_on_the_map);

    //     if (proc->process_PC > 4095 || proc->process_PC < 0)
    // {
    //     ft_printf("fork\n");
    //     getchar();
    // }
    
    // if (proc->process_PC > 4095 || proc->process_PC < 0)
    // {
    //     ft_printf("fork\n");
    //     getchar();
    // }

    // while (clone->next)
    // {
        // ft_printf("end id -> %u\n", g_cw.proc_end->id);
        // ft_printf("process_PC -> %d\n", g_cw.proc_end->process_PC);

        // clone = clone->next;
    // }



    // //	 for testing;
    // map->stack[proc->process_PC] = 7;
    // map->stack_color[proc->process_PC] = 5;

    // TODO read(1, 0, 1);

    // cw_display_map(g_cw.map.stack, g_cw.map.stack_color);
}
