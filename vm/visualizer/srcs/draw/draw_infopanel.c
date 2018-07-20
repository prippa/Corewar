/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infopanel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:58:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 16:58:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void		draw_text_background(t_arena *arena)
{
	double				k;

	k = 0.6;
	while (k <= 0.9)
	{
		draw_fillrect(get_rectangle(arena->viewport.w,
						SCREEN_HEIGHT * k,
						INFOPANEL_WIDTH,
						BUTTON_HEIGHT << 1),
						WHITE_COLOR,
						arena->renderer);
		draw_fillrect(get_rectangle(arena->viewport.w,
						SCREEN_HEIGHT * (k + 0.05),
						INFOPANEL_WIDTH,
						BUTTON_HEIGHT << 1),
						BLACK_COLOR,
						arena->renderer);
		k += 0.1;
	}
}

static inline void		draw_cycles_count_duration(t_arena *arena)
{
	t_rposition			txt_pos;

	sdl_putnbr((t_nbrinfo){.nbr = arena->cycles_per_tact,
				.c = WHITE_COLOR, .min_width = 4},
				get_rectangle(arena->viewport.w,
							SCREEN_HEIGHT * 0.65,
							BUTTON_WIDTH,
							BUTTON_HEIGHT << 1),
							arena);
	txt_pos = get_render_position(0,
			get_point(arena->viewport.w, SCREEN_HEIGHT * 0.6),
			(SDL_Point){0}, get_point(INFOPANEL_WIDTH / 3, BUTTON_HEIGHT << 1));
	render(txt_pos, arena->speed_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7;
	render(txt_pos, arena->duration_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr((t_nbrinfo){.nbr = arena->tact_duration / 1000,
				.c = WHITE_COLOR, .min_width = 4},
				get_rectangle(txt_pos.left_corner.x,
							SCREEN_HEIGHT * 0.65,
							BUTTON_WIDTH,
							BUTTON_HEIGHT << 1),
							arena);
}

static inline void		draw_cycles(t_arena *arena)
{
	t_rposition			txt_pos;

	sdl_putnbr((t_nbrinfo){.nbr = g_cw.cycle, .c = WHITE_COLOR, .min_width = 4},
				get_rectangle(arena->viewport.w,
							SCREEN_HEIGHT * 0.75,
							BUTTON_WIDTH,
							BUTTON_HEIGHT << 1),
							arena);
	txt_pos = get_render_position(0,
				get_point(arena->viewport.w, SCREEN_HEIGHT * 0.7),
				(SDL_Point){0},
				get_point(INFOPANEL_WIDTH / 3, BUTTON_HEIGHT << 1));
	render(txt_pos, arena->cycles_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7;
	render(txt_pos, arena->cycles_to_die_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr((t_nbrinfo){.nbr = g_cw.cycle_to_die,
				.c = WHITE_COLOR, .min_width = 4},
				get_rectangle(txt_pos.left_corner.x,
							SCREEN_HEIGHT * 0.75,
							BUTTON_WIDTH,
							BUTTON_HEIGHT << 1),
							arena);
}

void					draw_infopanel(t_arena *arena)
{
	draw_fillrect(INFOPANEL_RECTANGLE, arena->leader_color, arena->renderer);
	render(get_render_position(0,
			INFOPANEL_TOP_LEFT,
			INFOPANEL_TOP_LEFT,
			INFOPANEL_LABEL_PARAMS),
			arena->infopanel_title,
			arena->renderer,
			SDL_FLIP_NONE);
	draw_text_background(arena);
	draw_cycles_count_duration(arena);
	draw_cycles(arena);
	draw_constants(arena);
}
