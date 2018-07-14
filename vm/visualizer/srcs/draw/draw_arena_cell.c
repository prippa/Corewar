/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fillrect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:42:40 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 12:42:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

const bool	bold_states[25] = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const SDL_Color	back_colors[25] = {BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR,
									BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR,
									BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR,
									BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR,
									GREEN_COLOR, BLUE_COLOR, RED_COLOR, CYAN_COLOR,
									GRAY_COLOR, GREEN_COLOR, BLUE_COLOR, RED_COLOR, CYAN_COLOR};
const SDL_Color	font_colors[25] = {GREEN_COLOR, BLUE_COLOR, RED_COLOR, CYAN_COLOR,
									GREEN_COLOR, BLUE_COLOR, RED_COLOR, CYAN_COLOR,
									YELLOW_COLOR, MAGENTA_COLOR, WHITE_COLOR, GRAY_COLOR,
									GRAY_COLOR, YELLOW_COLOR, MAGENTA_COLOR, WHITE_COLOR,
									BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR, BLACK_COLOR,
									WHITE_COLOR, WHITE_COLOR, WHITE_COLOR, WHITE_COLOR};

bool			get_colors(t_colors st, SDL_Color *back, SDL_Color *font_color)
{
	bool		result;

	result = bold_states[st - 1];
	*back = back_colors[st - 1];
	*font_color = font_colors[st - 1];
	return (result);
}

void			draw_arena_cell(t_arena *arena,
								int i, int j,
								SDL_Rect rect)
{

	t_rposition	position;
	int index = i * ARENA_HEIGHT + j;

	SDL_Point	left_corner = {.x = rect.x, .y = rect.y};
	int cell = g_cw.map[index];
	int ff = 0;
	int sf = 0;
	get_digits(cell, &ff, &sf);
	t_ltexture *f;
	t_ltexture *s;
	SDL_Color back;
	SDL_Color f_color;
	if (get_colors(g_cw.colors[index], &back, &f_color))
	{
		f = arena->bold_figures[ff];
		s = arena->bold_figures[sf];
	}
	else
	{
		f = arena->figures[ff];
		s = arena->figures[sf];
		set_alpha_mode(200, f);
		set_alpha_mode(200, s);
	}
	position = get_render_position(0, left_corner, left_corner, (SDL_Point){.x = rect.w, .y = rect.h});
	set_color(f_color, f);
	set_color(f_color, s);
	SDL_SetRenderDrawColor(arena->renderer, back.r, back.g, back.b, 0x0);
	SDL_RenderFillRect(arena->renderer, &rect);
	rect.w /= 2;
	position = get_render_position(0, left_corner, left_corner, (SDL_Point){.x = rect.w, .y = rect.h});
	render(position, f, arena->renderer, SDL_FLIP_NONE);
	rect.x += rect.w;
	left_corner.x += rect.w;
	position = get_render_position(0, left_corner, left_corner, (SDL_Point){.x = rect.w, .y = rect.h});
	render(position, s, arena->renderer, SDL_FLIP_NONE);
}
