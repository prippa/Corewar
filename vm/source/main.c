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
	// visualizer_main();
	cw_init();
	cw_parse_args(argc, argv + 1);
	cw_parser();
	cw_load_map();
	cw_game_loop();
	cw_print_players(g_cw->pd.champs);
	cw_print_winer(g_cw->pd.champs);
	cw_free();
	system("leaks -q corewar");
	return (0);
}
