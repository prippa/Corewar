/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:34:31 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/05 13:16:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
			buf[i] = ft_bin_to_int(check, k);
		}
		else if (i >= 0)
		{
			k = k + 8;
			buf[i] = ft_bin_to_int(check, k);
		}
		i++;
	}
	free (check);
}

int		cw_get_dec_from_the_point(unsigned char *str, int quantity, int position)
{
	int res;
	int i;
	int j;

	res = 0;
	i = 0;
	j = position;

	// ft_printf("quantity -> %d\n", quantity);
	// ft_printf("position -> %d\n", position);

	// ft_printf("mod -> %d\n", (0 + (16777216 - 1) % IDX_MOD) % IDX_MOD);

	// int k = 0;
	// while (k < 4096)
	// {
	// 	ft_printf("d->%d\n", str[k]);
	// 	k++;
	// }
	unsigned char buf [4];

	while (i < 4)
	{
		// ft_printf("d->%d\n", str[j] - '0');
		// ft_printf("c->%c\n", str[j]);
		if (str[j] == 48)
			buf[i] = 0;
		else
			buf[i] = str[j];
		i++;
		j++;
	}
	// i = 0;

	// while (i < 4)
	// {
	// 	ft_printf("%.u", buf[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	res = cw_hex_to_dec(buf,4);
	// ft_printf("res --> %d\n", res);
	return (res);

}

int		cw_arguments_value(t_command *cmd, t_stack *map, t_processes *process) // -1 for registers;
{
	if (cmd->codage == 100) // o.k
		return (((process->process_PC + cmd->arg2.av + process->registers[cmd->arg3.av - 1]) % IDX_MOD));
	else if (cmd->codage == 116) // o.k
	{
		// ft_printf("IND -> %d\n", cmd->arg2.av % IDX_MOD);
		return ((process->process_PC + (cw_get_dec_from_the_point(map->stack, 4,cmd->arg2.av % IDX_MOD) + process->registers[cmd->arg3.av - 1]) % IDX_MOD) % IDX_MOD);
	}
	else if (cmd->codage == 84) // o.k.
	{
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg2.av - 1]);
		// ft_printf("r1 -> %d\n", process->registers[cmd->arg3.av - 1]);
		// ft_printf("res -> %d\n", ((process->registers[cmd->arg2.av - 1] + (process->process_PC + 1) + process->registers[cmd->arg3.av - 1]) % IDX_MOD));
		return ((process->process_PC + process->registers[cmd->arg2.av - 1]  + process->registers[cmd->arg3.av - 1]) % IDX_MOD);
	}
	else if (cmd->codage == 104) // o.k
		return ((process->process_PC + cmd->arg2.av + cmd->arg3.av) % IDX_MOD);
	else if (cmd->codage == 120) // o.k.
		return ((process->process_PC + (cw_get_dec_from_the_point(map->stack, 4,cmd->arg2.av % IDX_MOD) + cmd->arg3.av) % IDX_MOD) % IDX_MOD);
	else if (cmd->codage == 88) // o.k
		return ((process->process_PC + process->registers[cmd->arg2.av - 1]  + cmd->arg3.av) % IDX_MOD);
	return (0);
}

void	cw_sti(t_command *cmd, t_stack *map, int process_id)
{
	unsigned char buf[4];
	int i;
	int	position_on_the_map;
	t_processes *proc;
	// int	arguments[3];
	//process;
	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);

	position_on_the_map = 0;

	cw_write_bytes_to_buf(buf, proc->registers[cmd->arg2.av - 1]);

	// ft_printf("2 -> %d\n", cmd->arg2.av);
	// ft_printf("3 -> %d\n", process->registers[cmd->arg3.av]);
	// 
	position_on_the_map += cw_arguments_value(cmd, map, proc); // to func;

	// ft_printf("position_on_the_map -> %d\n", position_on_the_map);

	proc->process_PC += (cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2); // o.k.

	// (cmd->arg2.tp == 2) ? proc->process_PC += 1 : 0;
	// (cmd->arg2.tp == 1) ? proc->process_PC += 2 : 0;
	// (cmd->arg2.tp == 2 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;
	// (cmd->arg2.tp == 4 && cmd->arg3.tp == 2) ? proc->process_PC += 1 : 0;

	// ft_printf("process_PC -> %d\n", process->process_PC);

	// move the process_PC by the quantity of bytes;


	// process id // process parent;
	// get clear with it;
	// it will be found by the color ?;

	// process id in order to find the correct process;

	// ft_printf("%d", ((cmd->arg2.av + process->registers[cmd->arg3.av]) % IDX_MOD));
	// position_on_the_map = 15;

	// i = 0; // argument type variation;
	i = 0;
	if (position_on_the_map < 0)
		position_on_the_map = MEM_SIZE + position_on_the_map;
		// ft_printf("position_on_the_map -> %d\n", position_on_the_map);
	while (i < 4) // 2 || 4; // always take 4 bytes to the map;
	{
		if (position_on_the_map == MEM_SIZE)
		// ft_printf("position_on_the_map -> %d", position_on_the_map);
			position_on_the_map = 0;
		
		map->stack[position_on_the_map] = buf[i++];
		map->stack_color[position_on_the_map] = proc->color;
		map->stack_process_id[position_on_the_map++] = proc->id;
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// each process has the color of the parent;

		// for testing;
	 map->stack[proc->process_PC] = 7;
	 map->stack_color[proc->process_PC] = 5;



	 cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
}
