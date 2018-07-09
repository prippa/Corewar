/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:51:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 15:51:53 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline bool	init_window(t_arena *arena)
{
	if (!(arena->window = SDL_CreateWindow("Digital Coliseum",
											SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											SCREEN_WIDTH,
											SCREEN_HEIGHT,
											SDL_WINDOW_SHOWN)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window init error", SDL_GetError(), NULL);
		return (false);
	}
	arena->zoom = 0.9;
	if (!(arena->renderer = SDL_CreateRenderer(arena->window, -1, SDL_RENDERER_SOFTWARE)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer init error", SDL_GetError(), NULL);
		return (false);
	}
	SDL_SetRenderDrawColor(arena->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	if (!(arena->screen_surface = SDL_GetWindowSurface(arena->window)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Screen surface init error", SDL_GetError(), NULL);
		return (false);
	}
	return (true);
}

static inline void	init_msg_buttons(t_arena *arena)
{
	arena->msgbox_buttons[NO_BUTTON_ID] = (SDL_MessageBoxButtonData)NO_BUTTON;
	arena->msgbox_buttons[YES_BUTTON_ID] = (SDL_MessageBoxButtonData)YES_BUTTON;
	arena->msgbox_buttons[CANSEL_BUTTON_ID] = (SDL_MessageBoxButtonData)CANSEL_BUTTON;
}

static inline void	init_viewport(t_arena *arena)
{
	arena->viewport = get_rectangle(0,
									0,
									SCREEN_WIDTH - (BUTTON_WIDTH << 1) - (SCREEN_WIDTH >> 5),
									SCREEN_HEIGHT);
}

static inline bool	init_display_mode(t_arena *arena)
{
	if (SDL_GetDesktopDisplayMode(0, &(arena->d_mode)) != GET_DMODE_SUCCESS)
	{
		force_error(SDL_GetError());
        return (false);
	}
	arena->arena_tile_height = (SCREEN_HEIGHT >> 6) + 3;
	arena->arena_tile_width = (((int)((0.9 * SCREEN_WIDTH) - BUTTON_WIDTH)) >> 6) + 1;
	return (true);
}

bool				init(t_arena *arena)
{
	if (!init_devices())
		return (false);
	bzero(arena, sizeof(t_arena));
	if (!init_display_mode(arena) || !init_music(arena))
		return (false);
	init_viewport(arena);
	init_msg_buttons(arena);
	if (!init_window(arena))
		return (false);
	init_figures(arena);
	init_infopanel(arena);
	if (!init_controls(arena))
		return (false);
	return (true);
}
