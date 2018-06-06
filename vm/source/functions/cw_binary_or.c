/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_binary_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 14:32:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/06/01 14:32:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
// TODO delete all comments
// static t_processes	*cw_process_find(int process_id, t_processes *list)
// {
// 	while (list)
// 	{
// 		if (list->id == process_id)
// 			return (list);
// 		list = list->next;
// 	}
// 	return (NULL);
// }

static void		ft_zero_it(char *str)
{
	int i;

	i = 0;
	while (i < 32)
		str[i++] = '0';
}

static void		binary_or_comparison(char *var_1, char *var_2, char *var_res)
{
	int i;

	i = 0;
	while (i < 32)
	{
		if (var_1[i] == '1' || var_2[i] == '1')
			var_res[i] = '1';
		else
			var_res[i] = '0';
		i++;
	}
}

static int				cw_return_value_according_to_the_type_of_parameter_1(t_command *cmd, t_processes *process)
{
	if (cmd->arg1.tp == 1)
		return (process->registers[cmd->arg1.av - 1]);
	else if (cmd->arg1.tp == 2)
		return (cmd->arg1.av);
	else if (cmd->arg1.tp == 4)
		return (cmd->arg1.av);
	return (0);
}

static int				cw_return_value_according_to_the_type_of_parameter_2(t_command *cmd, t_processes *process)
{
	if (cmd->arg2.tp == 1)
		return (process->registers[cmd->arg2.av - 1]);
	else if (cmd->arg2.tp == 2)
		return (cmd->arg2.av);
	else if (cmd->arg2.tp == 4)
		return (cmd->arg2.av);
	return (0);
}

static char			*cw_res_of_comparison(t_command *cmd, t_processes *proc)
{
	char *x;
	char *y;
	char x_stack[33];
	char y_stack[33];
	char res_of_comparison[33];

	x = ft_itoa_base(cw_return_value_according_to_the_type_of_parameter_1(cmd, proc), 2, 0);
	y = ft_itoa_base(cw_return_value_according_to_the_type_of_parameter_2(cmd, proc), 2, 0);
	x_stack[32] = '\0';
	y_stack[32] = '\0';
	res_of_comparison[32] = '\0';
	ft_zero_it(x_stack);
	ft_zero_it(y_stack);
	ft_zero_it(res_of_comparison);
	ft_strncpy(&x_stack[32 - (int)ft_strlen(x)], x, (int)ft_strlen(x));
	ft_strncpy(&y_stack[32 - (int)ft_strlen(y)], y, (int)ft_strlen(y));

	// testing
	int i = 0;
	while (i < 32)
		ft_printf("%c", x_stack[i++]);
	i = 0;
	ft_printf("\n");
	while (i < 32)
		ft_printf("%c", y_stack[i++]);
	ft_printf("\n");		
	binary_or_comparison(x_stack, y_stack, res_of_comparison);
	i = 0;
	while (i < 32)
		ft_printf("%c", res_of_comparison[i++]);
	ft_printf("\n");
	

	free(x);
	free(y);
	return (ft_strdup(res_of_comparison));
}

void			cw_binary_or(t_command *cmd, t_stack *map, t_processes *proc/*, unsigned int process_id*/)
{

//	t_processes *proc;
	// int	arguments[3];
	//process;
//	proc = t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, process_id);

	// process_cw;
	char *res_of_comparison;

	res_of_comparison = cw_res_of_comparison(cmd, proc);
	proc->registers[cmd->arg3.av - 1] = ft_atoi_base(res_of_comparison, 2);
	free(res_of_comparison);

	ft_printf("res of comparison->%d\n", proc->registers[cmd->arg3.av - 1]);
	proc->process_PC += MEM_CORRECTION(
		proc->process_PC + cmd->arg1.tp + cmd->arg2.tp + cmd->arg3.tp + 2);
	proc->carry = (proc->registers[cmd->arg3.av - 1] != 0) ? 1 : 0;

//	 testing
//	 map->stack[proc->process_PC] = 7;
//	 map->stack_color[proc->process_PC] = 5;
//
//	 cw_display_map(g_cw->map.stack, g_cw->map.stack_color);


	

}
