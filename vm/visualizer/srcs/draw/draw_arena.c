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
	Uint8			i;
	SDL_Rect		rect;

	i = -1;
	rect = get_rectangle(arena->top_left.x + width,
			arena->top_left.y,
			width - 2,
			height - 2);
	if (rect.y < -height || rect.y >= arena->viewport.h - (height << 1))
		return ;
	while (++i < ARENA_WIDTH)
	{
		if (rect.x > arena->viewport.w)
			break ;
		SDL_RenderFillRect(arena->renderer, &rect);
		sdl_putnbr((t_nbrinfo){.nbr = i + 1, .c = WHITE_COLOR, .min_width = 2},
			rect,
			arena);
		rect.x += width;
	}
}

static inline void	draw_left_column(t_arena *arena, int width, int height)
{
	Uint8			i;
	SDL_Rect		rect;

	i = -1;
	rect = get_rectangle(arena->top_left.x,
			arena->top_left.y + height,
			width - 2,
			height - 2);
	if (rect.x < -width || rect.x >= arena->viewport.w - (width << 1))
		return ;
	while (++i < ARENA_HEIGHT)
	{
		if (rect.y > arena->viewport.h)
			break ;
		SDL_RenderFillRect(arena->renderer, &rect);
		sdl_putnbr((t_nbrinfo){.nbr = i + 1, .c = WHITE_COLOR, .min_width = 2},
			rect,
			arena);
		rect.y += height;
	}
}

static inline void	draw_numbers(t_arena *arena, int width, int height)
{
	SDL_SetRenderDrawColor(arena->renderer,
		arena->leader_color.r,
		arena->leader_color.g,
		arena->leader_color.b,
		arena->leader_color.a);
	draw_top_raw(arena, width, height);
	draw_left_column(arena, width, height);
}

static inline void	draw_row(int i,
						SDL_Point top,
						SDL_Point params,
						t_arena *arena)
{
	int				j;

	j = -1;
	while (++j < ARENA_WIDTH)
	{
		if (top.x < arena->viewport.x - (params.x << 1))
		{
			top.x += params.x;
			continue ;
		}
		else if (top.x > arena->viewport.x + arena->viewport.w)
			break ;
		draw_arena_cell(arena, i, j,
			get_rectangle(top.x + 1,
				top.y + 1,
				params.x - 2,
				params.y - 2));
		top.x += params.x;
	}
}

void				draw_arena(t_arena *arena)
{
	int				i;
	int				j;
	SDL_Point		top;
	SDL_Point		params;

	i = -1;
	params.x = ARENA_TILE_WIDTH * arena->zoom;
	params.y = ARENA_TILE_HEIGHT * arena->zoom;
	draw_numbers(arena, params.x, params.y);
	top.y = arena->top_left.y + params.y + 1;
	top.x = arena->top_left.x + params.x + 1;
	while (++i < ARENA_HEIGHT)
	{
		if (top.y < arena->viewport.y - (params.y << 1))
		{
			top.y += params.y;
			continue ;
		}
		else if (top.y > arena->viewport.h)
			break ;
		j = -1;
		draw_row(i, top, params, arena);
		top.y += params.y;
	}
}
