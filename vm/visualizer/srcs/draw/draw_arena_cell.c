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

const bool			g_boldstates[25] = BOLD_STATES;

const SDL_Color		g_backcolors[25] = BACK_COLORS;

const SDL_Color		g_fontcolors[25] = FONT_COLORS;

bool				get_colors(t_colors st,
						SDL_Color *back,
						SDL_Color *font_color)
{
	bool			result;

	result = g_boldstates[st - 1];
	*back = g_backcolors[st - 1];
	*font_color = g_fontcolors[st - 1];
	return (result);
}

static inline void	draw_number_in_cell(SDL_Color color[2],
										t_ltexture *pair[2],
										t_rposition position,
										t_arena *arena)
{
	set_color(color[1], pair[0]);
	set_color(color[1], pair[1]);
	position.width >>= 1;
	render(position, pair[0], arena->renderer, SDL_FLIP_NONE);
	position.left_corner.x += position.width;
	render(position, pair[1], arena->renderer, SDL_FLIP_NONE);
}

void				draw_arena_cell(t_arena *arena, int i, int j, SDL_Rect r)
{
	t_rposition		position;
	int				index;
	int				digits[2];
	t_ltexture		*pair[2];
	SDL_Color		color[2];

	index = i * ARENA_HEIGHT + j;
	get_digits(g_cw.mp.map[index], &digits[0], &digits[1]);
	if (get_colors(g_cw.mp.colors[index], &color[0], &color[1]))
	{
		pair[0] = arena->bold_figures[digits[0]];
		pair[1] = arena->bold_figures[digits[1]];
	}
	else
	{
		pair[0] = arena->figures[digits[0]];
		pair[1] = arena->figures[digits[1]];
		set_alpha_mode(200, pair[0]);
		set_alpha_mode(200, pair[1]);
	}
	position = get_render_position(0,
				get_point(r.x, r.y), get_point(0, 0), get_point(r.w, r.h));
	draw_fillrect(r, color[0], arena->renderer);
	draw_number_in_cell(color, pair, position, arena);
}
