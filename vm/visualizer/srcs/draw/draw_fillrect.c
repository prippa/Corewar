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

void			draw_fillrect(t_arena *arena,
								int i, int j,
								SDL_Rect rect)
{

	t_rposition	position;
	SDL_Point	left_corner = {.x = rect.x, .y = rect.y};
	int	cell = arena->bytes[i * ARENA_TILE_HEIGHT + j];
	int ff = 0;
	int sf = 0;
	get_digits(cell, &ff, &sf);
	t_ltexture *f;
	t_ltexture *s;
	SDL_Color c = (SDL_Color){};
	if (arena->is_bold[cell])
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
	position = get_render_position(0, &left_corner, NULL, &rect);
	//set_color(arena->colors[i * ARENA_WIDTH + j], arena->tile_block);
	set_color((SDL_Color){}, arena->tile_block);
	render(&position, arena->tile_block, arena->renderer, SDL_FLIP_NONE);
	c = arena->colors[i * ARENA_WIDTH + j];
	/*c.r ^= 0xff;
	c.g ^= 0xff;
	c.b ^= 0xff;*/
	set_color(c, f);
	set_color(c, s);
	rect.w /= 2;
	position = get_render_position(0, &left_corner, NULL, &rect);
	render(&position, f, arena->renderer, SDL_FLIP_NONE);
	rect.x += rect.w;
	left_corner.x += rect.w;
	position = get_render_position(0, &left_corner, NULL, &rect);
	render(&position, s, arena->renderer, SDL_FLIP_NONE);
}
