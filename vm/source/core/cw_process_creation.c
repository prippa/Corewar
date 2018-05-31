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