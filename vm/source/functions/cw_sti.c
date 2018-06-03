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

int		cw_bin_to_in(char *str, int index)
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
			decimal += cw_pow(2, i);
		i++;
		index--;
		len--;
	}
	return (decimal);
}

char	*cw_get_string_for_conversion(int nbr)
{
	int i;
	char *str;
	char *check;
	
	i = 0;
	str = ft_itoa_base(nbr, 2, 87);
	check = ft_strnew(32);
	while (i < 32)
	{
		check[i] = '0';
		i++;
	}
	if (nbr < 0)
		ft_strncpy(&check[0], &str[32], ft_strlen(str) - 32);
	else
		ft_strncpy(&check[32 - ft_strlen(str)], &str[0], ft_strlen(str));
	free(str);
	return (check);
}

void	cw_write_bytes_to_buf(unsigned char *buf, int nbr)
{
	char *check;
	int i;
	int k;

	i = 0;
	check = cw_get_string_for_conversion(nbr);
	while (i < 4)
	{
		if (i == 0)
		{
			k = 7 ;
			buf[i] = cw_bin_to_in(check, k);
		}
		else if (i >= 0)
		{
			k = k + 8;
			buf[i] = cw_bin_to_in(check, k);
		}
		i++;
	}
	free (check);
}

void	cw_sti(t_command *cmd, t_stack *map, t_processes *process)
{
	unsigned char buf[4];
	int i;
	int	j;

	cw_write_bytes_to_buf(buf, 32767);

	process->process_PC += ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD);

	// move the process_PC by the quantity of bytes; // process id // process parent;
	// get clear with it;
	// it will be found by the color ?;

	// process id in order to find the correct process;

	i = 0;
	j = process->process_PC;

	while (i < 4) // we always write here 4 bytes;
	{
		map->stack[j] = buf[i++];
		map->stack_color[j++] = process->color;
	}
	cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
