/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infopanel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:15:24 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 19:15:26 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	stupid_func_for_norm(t_arena *arena)
{
	arena->speed_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	SPEED_TXT, BLACK_COLOR), arena->renderer);
	arena->duration_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	DURATION_TXT, BLACK_COLOR), arena->renderer);
	arena->cycles_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	CYCLES_TXT, BLACK_COLOR), arena->renderer);
	arena->cycles_to_die_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	CYCLES_TO_DIE_TXT, BLACK_COLOR), arena->renderer);
	arena->nbr_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	NBR_TXT, BLACK_COLOR), arena->renderer);
}

bool		init_infopanel(t_arena *arena)
{
	t_text	info;

	info = get_text_info(WESTERN_SWING, 0.08 * SCREEN_HEIGHT,
				"COREWAR", BLACK_COLOR);
	arena->infopanel_title = load_from_rendered_text(info, arena->renderer);
	stupid_func_for_norm(arena);
	arena->checks_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	CHECKS_TXT, BLACK_COLOR), arena->renderer);
	arena->delta_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	CYCLE_DELTA_TXT, BLACK_COLOR), arena->renderer);
	arena->processes_txt =
	load_from_rendered_text(get_text_info(ROBOTO_BLACK,
	(ARENA_TILE_WIDTH * MAX_ZOOM),
	PROCESSES_TXT, BLACK_COLOR), arena->renderer);
	return (true);
}
