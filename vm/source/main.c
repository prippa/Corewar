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

int		main(int argc, char **argv)
{
	cw_init();
	cw_parse_args(argc, argv + 1);
	cw_parser();
	cw_init_processes(g_cw->pd.champs, &g_cw->processes);
	// while (g_cw->processes)
	// {
	// 	ft_printf("color -> %d\n", g_cw->processes->color);
	// 	ft_printf("process_PC -> %d\n", g_cw->processes->process_PC);
	// 	g_cw->processes = g_cw->processes->next;
	// }
	cw_load_map();
	system("leaks -q corewar");
	// cw_game_loop();
	cw_free();
	return (0);
}
