#include "corewar.h"

static void	t_processes_add_to_head(t_processes **proc_start,
							t_processes **proc_end, t_processes **new_obj)
{
	(*new_obj)->next = *proc_start;
	(*new_obj)->prev = NULL;
	if (*proc_start)
		(*proc_start)->prev = *new_obj;
	else
		*proc_end = *new_obj;
	*proc_start = *new_obj;
}

// TODO change init stuff
void		t_processe_add(t_processes **proc_start,
							t_processes **proc_end)
{
	t_processes	*new_obj;

	g_cw.proc_counter++;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);
	new_obj->id = g_cw.id_counter++;
	new_obj->carry = 0;
	new_obj->color = 0;
	new_obj->process_PC = 0;
	new_obj->live_status = ALIVE;
	new_obj->has_been_activated = DEAD;
	ft_bzero(new_obj->registers, sizeof(int) * REG_NUMBER);
	new_obj->cycles_till_execution = 1;
	new_obj->proc_color_write_to_map = 0;
	new_obj->current_command = 0;
	new_obj->detect_deviation = 0;
	new_obj->champ_number = 0;
	t_processes_add_to_head(proc_start, proc_end, &new_obj);
}

void		t_processes_copy(t_processes **proc_start, t_processes **proc_end,
			t_processes **current_proc, int position)
{

	t_processes	*new_obj;

	// add general quantity of the processes;
	g_cw.proc_counter++;

	// created the memory area for the new node/process;
	if (!(new_obj = (t_processes *)malloc(sizeof(t_processes))))
		cw_perror_exit(ERR_MALLOC_MESSAGE, MALLOC);

	// general variable;
	new_obj->id = g_cw.id_counter++;

	new_obj->carry = (*current_proc)->carry; // not a copy;
	new_obj->color = (*current_proc)->color; // copy;
	new_obj->process_PC = position; // not a copy;
	new_obj->live_status = (*current_proc)->live_status; // copy;
	new_obj->has_been_activated = (*current_proc)->has_been_activated; // copy;
	new_obj->cycles_till_execution = 1; // not copy;
	new_obj->proc_color_write_to_map = (*current_proc)->proc_color_write_to_map; // copy;
	new_obj->proc_process_PC_color = (*current_proc)->proc_process_PC_color;
	new_obj->champ_number = (*current_proc)->champ_number;




	new_obj->live_color = (*current_proc)->live_color;

	// what to do if command is not valid
	if (g_cw.map.stack[position] >= 1 && g_cw.map.stack[position] <= 16)
		new_obj->current_command = g_cw.map.stack[position];
	else
		new_obj->current_command = 0;

	new_obj->detect_deviation = 0; ////////////////////////// ?

	// ft_memcpy(new_obj->registers, (*current_proc)->registers, sizeof(int) * REG_NUMBER);
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		new_obj->registers[i] = (*current_proc)->registers[i];

	

	// add to the map;
	if(g_cw.map.stack_color[new_obj->process_PC] != 0)
	{
		if (new_obj->color == 1)
		{
			g_cw.map.stack_color[new_obj->process_PC] = 5;
		}
		else if (new_obj->color == 2)
			g_cw.map.stack_color[new_obj->process_PC] = 6;
		else if (new_obj->color == 3)
			g_cw.map.stack_color[new_obj->process_PC] = 7;
		else if (new_obj->color == 4)
			g_cw.map.stack_color[new_obj->process_PC] = 8;
	}
	else
		g_cw.map.stack_color[new_obj->process_PC] = 0;

	

				// ft_printf("%~d\n", F_BACK_GREEN_BLACK, g_cw.map.stack_color[new_obj->process_PC]);
				// getchar();


	    // if (new_obj->process_PC > 4095 || new_obj->process_PC < 0)
     //    {
     //    	ft_printf("copy\n");
     //        getchar();
     //    }


	
	// add to the head;
		t_processes_add_to_head(proc_start, proc_end, &new_obj);

	    // if (new_obj->process_PC > 4095 || new_obj->process_PC < 0)
	        
     //    {
     //    ft_printf("copy\n");
     //        getchar();
            
     //    }



}
