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
	cw_load_map();
	t_champ_sort_by_order(&g_cw.pd.champs);
	cw_game_loop();
	t_champ_sort_by_champ_number(&g_cw.pd.champs);
	cw_print_players(g_cw.pd.champs);
	cw_print_winer(g_cw.pd.champs);
	cw_free();
	system("leaks -q corewar");
	return (0);
}
