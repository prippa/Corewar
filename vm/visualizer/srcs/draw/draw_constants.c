/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_constants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:22:18 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 17:22:20 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	draw_nbr(t_arena *arena, t_rposition *txt_pos)
{
	sdl_putnbr((t_nbrinfo){.nbr = NBR_LIVE, .c = WHITE_COLOR, .min_width = 4},
				get_rectangle(arena->viewport.w,
					(float)SCREEN_HEIGHT * 0.85,
					BUTTON_WIDTH,
					BUTTON_HEIGHT << 1),
					arena);
	*txt_pos = get_render_position(0,
		get_point(arena->viewport.w,
		(float)SCREEN_HEIGHT * 0.8),
		get_point(0, 0),
		get_point((float)INFOPANEL_WIDTH / 3, BUTTON_HEIGHT << 1));
	render(*txt_pos, arena->nbr_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos->left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos->width *= 1.7;
}

static inline void	draw_checks(t_arena *arena, t_rposition *txt_pos)
{
	render(*txt_pos, arena->checks_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr((t_nbrinfo){.nbr = MAX_CHECKS, .c = WHITE_COLOR, .min_width = 4},
				get_rectangle(txt_pos->left_corner.x,
					(float)SCREEN_HEIGHT * 0.85,
					BUTTON_WIDTH,
					BUTTON_HEIGHT << 1), arena);
	*txt_pos = get_render_position(0,
		get_point(arena->viewport.w, SCREEN_HEIGHT * 0.9),
		get_point(0, 0), get_point((float)INFOPANEL_WIDTH / 3,
							BUTTON_HEIGHT << 1));
}

static inline void	draw_delta(t_arena *arena, t_rposition *txt_pos)
{
	render(*txt_pos, arena->delta_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr((t_nbrinfo){.nbr = CYCLE_DELTA,
				.c = WHITE_COLOR, .min_width = 4},
				get_rectangle(arena->viewport.w,
					(float)SCREEN_HEIGHT * 0.95,
					BUTTON_WIDTH,
					BUTTON_HEIGHT << 1), arena);
	txt_pos->left_corner.x += (float)INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos->width *= 1.7;
}

static inline void	draw_processes(t_arena *arena, t_rposition *txt_pos)
{
	render(*txt_pos, arena->processes_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr((t_nbrinfo){.nbr = g_cw.proc_counter,
				.c = WHITE_COLOR, .min_width = 4},
				get_rectangle(txt_pos->left_corner.x,
					(float)SCREEN_HEIGHT * 0.95,
					BUTTON_WIDTH,
					BUTTON_HEIGHT << 1), arena);
}

void				draw_constants(t_arena *arena)
{
	t_rposition		txt_pos;

	draw_nbr(arena, &txt_pos);
	draw_checks(arena, &txt_pos);
	draw_delta(arena, &txt_pos);
	draw_processes(arena, &txt_pos);
}
