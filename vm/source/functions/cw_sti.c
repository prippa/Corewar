#include "corewar.h"

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process)
{
	ft_printf("%d\n", cmd->arg2.av);
	ft_printf("%d\n", cmd->arg3.av);
	
	process->process_PC += ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD);

	ft_printf("process_PC -> %d\n", process->process_PC);
	char *str = ft_itoa_base(-1, 2, 87);


	unsigned char buf[8];
	int a = 0;
	while (a < 8)
	{
		buf[a] = 255;
		a++;
	}


	
	ft_printf("process_PC -> %s\n", str);
	
	// ft_strncpy(map->stack[process->process_PC], str, 4);
	int i = 0;
	int	j = process->process_PC;

	// unsigned char qw[8] = {01,01, 01, 01, 01,01, 01, 01};

	// int q = cw_hex_to_dec(qw, 2);

		// ft_printf("q->>>> %x\n", q);
	
	while (i < 4)
	{
		map->stack[j] = buf[i];
		// ft_printf("->>>> %x\n", str[i]);
		map->stack_color[j] = process->color;
		i++;
		j++;
	}
		cw_display_map(g_cw->map.stack, g_cw->map.stack_color);


	// (void)map;



	

}
