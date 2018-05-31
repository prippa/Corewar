#include "corewar.h"

t_processes	*cw_process_node_constructor(unsigned char *code)
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
	new->color = 0;
	new->process_PC = 0;
	new->carry = 0;
	ft_bzero(new->registers, 16);
	return (new);
}

void	cw_init_processes(t_champ *champ_pointer, t_processes **processes_pointer)
{
	// reverse the champions;

	t_processes *tmp_processes;

	while(champ_pointer)
	{
		tmp_processes = *processes_pointer;
		if (!*processes_pointer)
			ft_printf("Nope\n");










		champ_pointer = champ_pointer->next;
	}
}