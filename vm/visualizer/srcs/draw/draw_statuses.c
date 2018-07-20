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

static inline void	draw_status_txt(t_arena *arena,
						t_rposition *name_pos,
						int i)
{
	name_pos->width = INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
	render(*name_pos, arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x += name_pos->width;
	name_pos->width = INFOPANEL_WIDTH * (arena->statuses[i].text_len / (float)64);
	render(*name_pos, arena->statuses[i].first_row, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x += name_pos->width;
	name_pos->width = INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
	render(*name_pos, arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
	name_pos->left_corner.x = INFOPANEL_TOP_LEFT.x;
	name_pos->left_corner.y += BUTTON_HEIGHT;
	name_pos->width = INFOPANEL_WIDTH;
	render(*name_pos, arena->statuses[i].second_row, arena->renderer, SDL_FLIP_NONE);
}

void			draw_statuses(t_arena *arena)
{
	int			i;
	t_rposition	name_pos;
	int			max;
	int			sum;
	SDL_Color	c;
	int			live;

	i = -1;
	name_pos = get_render_position(0, (SDL_Point){.x = INFOPANEL_TOP_LEFT.x, .y = 0.12 * SCREEN_HEIGHT}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH, .y = BUTTON_HEIGHT});
	max = get_max();
	sum = get_live_sum();
	while (++i < g_cw.pd.champs_count)
	{
		draw_status_txt(arena, &name_pos, i);
		live = get_live(i);
		if (i == RED_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_RED;
			c = RED_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0xff, 0, 0, 0xff);
		}
		else if (i == BLUE_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_BLUE;
			c = BLUE_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0xff, 0xff);
		}
		else if (i == GREEN_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_GREEN;
			c = GREEN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0, 0xff);
		}
		else
		{
			if (max == live && live)
				arena->leader_color = LIGHT_CYAN;
			c = CYAN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0xff, 0xff);
		}
		sdl_putnbr((t_nbrinfo){.nbr = live, .c = c, .min_width = 6},
			get_rectangle(INFOPANEL_TOP_LEFT.x,
				name_pos.left_corner.y + BUTTON_HEIGHT,
				BUTTON_WIDTH >> 1,
				BUTTON_HEIGHT), arena);
		SDL_Rect r = get_rectangle(INFOPANEL_TOP_LEFT.x + (BUTTON_WIDTH * (float)2/3), name_pos.left_corner.y + BUTTON_HEIGHT, INFOPANEL_WIDTH - (BUTTON_WIDTH), BUTTON_HEIGHT);
		draw_fillrect(r, (SDL_Color){.r = 100}, arena->renderer);
		float p = live / (float)sum;
		float w = r.w * p;
		SDL_Rect in_rect = get_rectangle(r.x, r.y, w, r.h);
		draw_fillrect(in_rect, c, arena->renderer);
		draw_outlinerect(arena, r);
		name_pos.left_corner.y += BUTTON_HEIGHT * 3;
	}
}
