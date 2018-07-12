/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:45:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 18:45:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	draw_top_raw(t_arena *arena, int width, int height)
{
	SDL_Point		top_left;
	Uint8			i;
	int				ff;
	int				sf;
	Uint8			high;

	top_left = arena->top_left;
	top_left.x += width;
	i = -1;
	high = ARENA_WIDTH;
	if (top_left.y < 0 || top_left.y >= arena->viewport.h - (height << 1))
	{
		i = 0;
		high = 0;
	}
	while (++i < high)
	{
		if (top_left.x >= arena->viewport.w - width)
			break ;
		int x_init = top_left.x;
		get_digits(i, &ff, &sf);
		SDL_Rect rect = get_rectangle(top_left.x + 1,
										top_left.y + 1,
										width - 2,
										height - 2);
		SDL_SetRenderDrawColor(arena->renderer, 0xff, 0x0, 0x0, 0xff);
		SDL_RenderFillRect(arena->renderer, &rect);
		set_color(WHITE_COLOR, arena->bold_figures[sf]);
		set_color(WHITE_COLOR, arena->bold_figures[ff]);
		rect.w /= 2;
		t_rposition position = get_render_position(0, &top_left, NULL, &rect);
		render(&position, arena->bold_figures[ff], arena->renderer, SDL_FLIP_NONE);
		top_left.x += rect.w;
		rect.x += rect.w;
		render(&position, arena->bold_figures[sf], arena->renderer, SDL_FLIP_NONE);
		top_left.x = x_init + width;
	}
}

static inline void	draw_numbers(t_arena *arena, int width, int height)
{
	SDL_Point		top_left;
	Uint8			i;
	int				ff;
	int				sf;

	draw_top_raw(arena, width, height);
	top_left = arena->top_left;
	top_left.y += height;
	i = -1;
	while (++i < ARENA_HEIGHT)
	{
		int y_init = top_left.y;
		int ff = (i >> 4);
		int sf = ((ff << 4) ^ i);
		set_color(WHITE_COLOR, arena->bold_figures[sf]);
		set_color(WHITE_COLOR, arena->bold_figures[ff]);
		SDL_Rect rect = get_rectangle(top_left.x,
										top_left.y + 1,
										width - 2,
										height - 2);
		SDL_SetRenderDrawColor(arena->renderer, 0xff, 0x0, 0x0, 0xff);
		SDL_RenderFillRect(arena->renderer, &rect);
		rect.w /= 2;
		t_rposition position = get_render_position(0,
												&top_left,
												NULL,
												&rect);
		render(&position, arena->bold_figures[ff], arena->renderer, SDL_FLIP_NONE);
		top_left.x += rect.w;
		rect.x += rect.w;
		render(&position, arena->bold_figures[sf], arena->renderer, SDL_FLIP_NONE);
		top_left.x -= rect.w;
		top_left.y = y_init + height;
	}
}

void			draw_arena(t_arena *arena)
{
	int			top_x;
	int			width;
	int			height;
	int			top_y;
	int			i;
	int			j;

	i = -1;
	width = ARENA_TILE_WIDTH * arena->zoom;
	height = ARENA_TILE_HEIGHT * arena->zoom;
	draw_numbers(arena, width, height);
	top_y = arena->top_left.y + height + 1;
	while (++i < ARENA_HEIGHT)
	{
		if (top_y < arena->viewport.y - height)
		{
			top_y += height;
			continue ;
		}
		else if (top_y > arena->viewport.h - height)
			break ;
		j = -1;
		top_x = arena->top_left.x + width + 1;
		while (++j < ARENA_WIDTH)
		{
			if (top_x < arena->viewport.x - width)
			{
				top_x += width;
				continue ;
			}
			else if (top_x > arena->viewport.x + arena->viewport.w - width)
				break ;
			draw_fillrect(arena, i, j, get_rectangle(top_x + 1,
												top_y + 1,
												width - 2,
												height - 2));
			top_x += width;
		}
		top_y += height;
	}
}
