#include "corewar.h"

t_processes	*cw_process_node_constructor(unsigned char *code, int color, int process_PC)
{
	int i;
	t_processes *new;

	i = 0;
	if(!(new = (t_processes *)malloc(sizeof (t_processes))))
		return (NULL);
	while (i < CHAMP_MAX_SIZE + 1)
	{
		new->code[i] = code[i];
		i++;
	}
	new->color = color;
	new->process_PC = process_PC;
	new->carry = process_PC;
	ft_bzero(new->registers, 16);
	new->next = NULL;
	return (new);
}

// void push(struct Node** head_ref, int new_data)
// {
//     struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
//     new_node->data  = new_data;
//     (*head_ref)    = new_node;
// }

void	cw_init_processes(t_champ *champ_pointer, t_processes **processes_pointer)
{
	// reverse the champions;
	int color;
	int process_PC;
	int map_distance;
	t_processes *tmp_processes;
	
	color = 1;
	map_distance = MEM_SIZE / g_cw->pd.champs_count;
	process_PC = 0;
	while(champ_pointer)
	{
		if (!*processes_pointer)
			*processes_pointer = cw_process_node_constructor(champ_pointer->code, color, process_PC);
		else
		{
			tmp_processes = *processes_pointer;
			while (tmp_processes->next)
				tmp_processes = tmp_processes->next;
			tmp_processes->next = cw_process_node_constructor(champ_pointer->code, color, process_PC);
		}
		color++;
		process_PC += map_distance;
		champ_pointer = champ_pointer->next;
	}
}