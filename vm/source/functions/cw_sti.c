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

int		cw_bin_to_in(char *str, int index) // process id in order to find the correct process;
{
	int decimal;
	int	len;
	int i;

	decimal = 0;
	len = 7;
	i = 0;
	while (len >= 0)
	{
		if (str[index] == '1')
		{
			decimal += cw_pow(2, i);
			ft_printf("true i -> %d\n", i);
		}
		i++;
		index--;
		len--;
	}
	// ft_printf("decimal -> %d", decimal);
	return (decimal);
}

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process) // move the process_PC by the quantity of bytes; // process id // process parent;
{
	// ft_printf("%d\n", cmd->arg2.av);
	// ft_printf("%d\n", cmd->arg3.av);
	
	process->process_PC += ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD);
	 // it will be found by the color ?; // process_PC will be moved by the quantity of bits,
		// not by the place where the information has to be placed;

	// ft_printf("process_PC -> %d\n", process->process_PC);
	int magic = -500;
	char *str = ft_itoa_base(magic, 2, 87);

	ft_printf("itoa_base -> %s\n", str);


	int bla = 0;

	bla = 0;
	char *check = ft_strnew(32);
	bla = 0;
	while (bla < 32)
	{
		check[bla] = '0';
		bla++;
	}
	// ft_bzero(check, 32);
	ft_printf("len -> %d", ft_strlen(str));
	if (magic < 0)
		ft_strncpy(&check[0], &str[32], ft_strlen(str) - 32);
	else
		ft_strncpy(&check[32 - ft_strlen(str)], &str[0], ft_strlen(str));

	ft_printf("check -> %s\n", check);

	unsigned char buf[4];
	int a = 0;
	int k;

	while (a < 4)
	{
		if (a == 0)
		{
			k = 7 ;
			buf[a] = cw_bin_to_in(check, k);
		}
		else if (a >= 0)
		{
			k = k + 8;
			ft_printf("k->%d", k);
			buf[a] = cw_bin_to_in(check, k);
		}
		// buf[a] =1;
		ft_printf(" to_dec -> %d\n", buf[a]);
		
		a++;
	}
	
	// ft_printf("process_PC -> %s\n", str);
	
	int i = 0;
	int	j = process->process_PC;

	while (i < 4)
	{
		map->stack[j] = buf[i++];
		map->stack_color[j++] = process->color;
	}

	free(str);
	free(check);
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
