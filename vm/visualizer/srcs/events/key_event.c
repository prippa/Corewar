/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:09:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 16:09:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	move_arena(t_arena *arena, SDL_Keycode sym)
{
	if (sym == SDLK_UP)
		move_up(arena);
	else if (sym == SDLK_DOWN)
		move_down(arena);
	else if (sym == SDLK_LEFT)
		move_left(arena);
	else if (sym == SDLK_RIGHT)
		move_right(arena);
}

static inline void	escape_catch(t_arena *arena)
{
	int				buttonid;

	if (arena->is_fullscreen == false)
		exit_event(arena);
	else
		change_screen_mode(arena);
}

static inline void	zoom_event(t_arena *arena, SDL_Keycode sym)
{
	int				x;
	int				y;

	if (sym == SDLK_i)
	{
		SDL_GetMouseState(&x, &y);
		zoom_in(x, y, arena);
	}
	else if (sym == SDLK_o)
	{
		SDL_GetMouseState(&x, &y);
		zoom_out(x, y, arena);
	}
}

void				key_event(t_arena *arena, SDL_Keycode sym)
{
	if (sym == SDLK_ESCAPE)
		escape_catch(arena);
	else if (sym == SDLK_f)
		change_screen_mode(arena);
	else if (sym == SDLK_i || sym == SDLK_o)
		zoom_event(arena, sym);
	else if ((sym == SDLK_UP || sym == SDLK_DOWN ||
				sym == SDLK_LEFT || sym == SDLK_RIGHT))
		move_arena(arena, sym);
	else if (sym == SDLK_SPACE)
		arena->pause = !(arena->pause);
	else if (sym == SDLK_q)
	{
		arena->zoom = 1.0;
		arena->top_left.x = 0;
		arena->top_left.y = 0;
	}
}