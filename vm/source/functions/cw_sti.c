#include "corewar.h"

int		cw_bin_to_in(char *str)
{
	int decimal;
	int	len;
	int base;

	decimal = 0;
	len = 8;
	base = 1;
	while (len)
	{
		base = base + base * 2;
		if (str[len] == '1')
			decimal += base;
		len--;
	}
	ft_printf("%d\n", decimal);
	return (decimal);
}

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process)
{
	ft_printf("%d\n", cmd->arg2.av);
	ft_printf("%d\n", cmd->arg3.av);
	
	process->process_PC += ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD);

	ft_printf("process_PC -> %d\n", process->process_PC);
	char *str = ft_itoa_base(-1, 2, 87);

	unsigned char buf[4];
	int a = 0;
	while (a < 4)
	{
		buf[a] = cw_bin_to_in(&str[a + 8]);
		a++;
	}

	ft_printf("process_PC -> %s\n", str);
	
	int i = 0;
	int	j = process->process_PC;
	while (i < 4)
	{
		map->stack[j] = buf[i];
		map->stack_color[j] = process->color;
		i++;
		j++;
	}
		cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
