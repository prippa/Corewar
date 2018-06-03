#include "corewar.h"

int		cw_pow(int base, int level)
{
	int	res;

	res = 1;
	if (level == 0)
		return (1);
	while (level)
	{
		res = res * base;
		level--;;
	}
	return (res);
}

int		cw_bin_to_in(char *str) // process id in order to find the correct process;
{
	int decimal;
	int	len;
	int i;

	decimal = 0;
	len = 7;
	i = 0;
	while (len >= 0)
	{
		if (str[len] == '1')
			decimal += cw_pow(2, i);
		i++;
		len--;
	}
	return (decimal);
}

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process) // move the process_PC by the quantity of bytes; // process id // process parent;
{
	ft_printf("%d\n", cmd->arg2.av);
	ft_printf("%d\n", cmd->arg3.av);
	
	process->process_PC += ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD);
	 // it will be found by the color ?; // process_PC will be moved by the quantity of bits,
		// not by the place where the information has to be placed;

	ft_printf("process_PC-> %d\n", process->process_PC);

	char *str = ft_itoa_base(2, 2, 87);

	char *buf1 = "00000010";

	unsigned char buf[4];
	int a = 0;
	while (a < 4)
	{
		buf[a] = cw_bin_to_in(&buf1[a + 8]);
		a++;
	}
	
	ft_printf("process_PC ========-> %s\n", str);
	
	int i = 0;
	int	j = process->process_PC;

	while (i < 4)
	{
		map->stack[j] = buf[i++];
		map->stack_color[j++] = process->color;
	}
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
