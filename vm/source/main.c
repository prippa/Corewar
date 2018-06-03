/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:56:33 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:56:44 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void print_one_proc(t_processes *proc)
{
	if (!proc)
	{
		ft_putstr("proc == NULL\n");
		return ;
	}
	ft_printf("id - %d\n", proc->id);
	ft_printf("color - %d\n", proc->color);
	ft_printf("process_PC - %d\n", proc->process_PC);
	ft_printf("carry - %d\n", proc->carry);
}

void print_processes(t_processes *start)
{
	int i = 1;
	while (start)
	{
		ft_printf("PROCESSE ------------№%d-----------\n", i);
		print_one_proc(start);
		start = start->next;
		i++;
	}
}

int		main(int argc, char **argv)
{
	cw_init();
	cw_parse_args(argc, argv + 1);
	cw_parser();
	cw_load_map();
ft_putstr("###############################################################\n");
print_processes(g_cw->proc_start);
ft_putstr("###############################################################\n");
ft_putstr("###############################################################\n");
t_processe_free_by_id(&g_cw->proc_start, &g_cw->proc_end, 2);
print_processes(g_cw->proc_start);
ft_putstr("###############################################################\n");
ft_putstr("###############################################################\n");
print_one_proc(t_processe_get_by_id(g_cw->proc_start, g_cw->proc_end, 2));
ft_putstr("###############################################################\n");
// ft_putstr("###############################################################\n");
// t_processe_free_by_id(g_cw->proc_start, g_cw->proc_end, 2);
// print_processes(g_cw->proc_start);
// ft_putstr("###############################################################\n");
	// cw_game_loop();
	// cw_display_map(g_cw->map.stack, g_cw->map.stack_color);
	cw_free();
	system("leaks -q corewar");
	return (0);
}
