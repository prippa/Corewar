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
	{
		move_up(arena);
	}
	else if (sym == SDLK_DOWN)
	{
		move_down(arena);
	}
	else if (sym == SDLK_LEFT)
	{
		arena->top_left.x -= ARENA_TILE_WIDTH * arena->zoom;
	}
	else if (sym == SDLK_RIGHT)
	{
		arena->top_left.x += ARENA_TILE_WIDTH * arena->zoom;
	}
}

void	key_event(t_arena *arena, SDL_Keycode sym)
{
	int	buttonid;
	int	x;
	int	y;

	if (sym == SDLK_ESCAPE)
	{
		if (arena->is_fullscreen == false)
		{
			buttonid = exit_dialog(arena);
			if (buttonid == YES_BUTTON_ID)
				arena->quit = true;
		}
		else
		{
			arena->is_fullscreen = false;
			arena->full_btn->checked = false;
			arena->full_btn->current_sprite = CROSS_MOUSE_OUT;
			SDL_SetWindowFullscreen(arena->window, 0);
		}
	}
	else if (sym == SDLK_f)
	{
		arena->full_btn->checked = true;
		arena->is_fullscreen = true;
		arena->full_btn->current_sprite = CHECK_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window,
								 SDL_WINDOW_FULLSCREEN);
	}
	else if (sym == SDLK_h)
	{
		arena->full_btn->checked = false;
		arena->is_fullscreen = false;
		arena->full_btn->current_sprite = CROSS_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window, 0);
	}
	else if (sym == SDLK_i)
	{
		SDL_GetMouseState(&x, &y);
		zoom_in(x, y, arena);
	}
	else if (sym == SDLK_o)
	{
		SDL_GetMouseState(&x, &y);
		zoom_out(x, y, arena);
	}
	else if ((sym == SDLK_UP || sym == SDLK_DOWN ||
				sym == SDLK_LEFT || sym == SDLK_RIGHT))
	{
		move_arena(arena, sym);
	}
	else if (sym == SDLK_SPACE)
	{
		arena->pause = !(arena->pause);
	}
	else if (sym == SDLK_q)
	{
		arena->zoom = 1.0;
		arena->top_left.x = 0;
		arena->top_left.y = 0;
	}
}