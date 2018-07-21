/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_statuses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:22:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 18:22:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

const SDL_Color	g_pairs[MAX_PLAYERS << 1] = STATUS_PAIRS;

static inline void	draw_status_txt(t_arena *arena,
						t_rposition *name_pos,
						int i)
{
	name_pos->width =
	INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
	render(*name_pos,
	arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x += name_pos->width;
	name_pos->width =
	INFOPANEL_WIDTH * (arena->statuses[i].text_len / (float)64);
	render(*name_pos,
	arena->statuses[i].first_row, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x += name_pos->width;
	name_pos->width =
	INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
	render(*name_pos,
	arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x = INFOPANEL_TOP_LEFT.x;
	name_pos->left_corner.y += BUTTON_HEIGHT;
	name_pos->width = INFOPANEL_WIDTH;
	render(*name_pos,
	arena->statuses[i].second_row,
	arena->renderer,
	SDL_FLIP_NONE);
}

void				set_color_pair(t_arena *arena, int i, int max, int live)
{
	if (max == live && live)
		arena->leader_color = g_pairs[i << 1];
	arena->regular_color = g_pairs[(i << 1) + 1];
	set_render_color(arena->renderer, arena->regular_color);
}

void				draw_inner_status(t_arena *arena,
					int live,
					int sum,
					t_rposition *name_pos)
{
	SDL_Rect		r;
	float			p;
	float			w;
	SDL_Rect		in_rect;

	r = get_rectangle(INFOPANEL_TOP_LEFT.x + ((float)BUTTON_WIDTH * 2 / 3),
			name_pos->left_corner.y + BUTTON_HEIGHT,
			INFOPANEL_WIDTH - (BUTTON_WIDTH),
			BUTTON_HEIGHT);
	draw_fillrect(r, (SDL_Color){.r = 100}, arena->renderer);
	p = live / (float)sum;
	w = r.w * p;
	in_rect = get_rectangle(r.x, r.y, w, r.h);
	draw_fillrect(in_rect, arena->regular_color, arena->renderer);
	draw_outlinerect(arena, r);
	name_pos->left_corner.y += BUTTON_HEIGHT * 3;
}

void				draw_statuses(t_arena *arena)
{
	int				i;
	t_rposition		name_pos;
	int				max;
	int				sum;
	int				live;

	i = -1;
	name_pos = get_render_position(0,
		get_point(INFOPANEL_TOP_LEFT.x, 0.12 * SCREEN_HEIGHT),
		get_point(0, 0), get_point(INFOPANEL_WIDTH, BUTTON_HEIGHT));
	max = get_max();
	sum = get_live_sum();
	while (++i < g_cw.pd.champs_count)
	{
		draw_status_txt(arena, &name_pos, i);
		live = get_live(i);
		set_color_pair(arena, i, max, live);
		sdl_putnbr((t_nbrinfo){.nbr = live,
		.c = arena->regular_color, .min_width = 6},
			get_rectangle(INFOPANEL_TOP_LEFT.x,
				name_pos.left_corner.y + BUTTON_HEIGHT,
				BUTTON_WIDTH >> 1,
				BUTTON_HEIGHT), arena);
		draw_inner_status(arena, live, sum, &name_pos);
	}
}
