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

static inline bool	create_window(t_arena *arena)
{
	if (!(arena->window = SDL_CreateWindow("Digital Coliseum",
											SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											SCREEN_WIDTH,
											SCREEN_HEIGHT,
											SDL_WINDOW_SHOWN)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Window init error",
								SDL_GetError(),
								NULL);
		return (false);
	}
	arena->zoom = 1.0;
	if (!(arena->renderer = SDL_CreateRenderer(arena->window,
												-1,
												SDL_RENDERER_SOFTWARE)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Renderer init error",
								SDL_GetError(),
								NULL);
		return (false);
	}
	SDL_SetRenderDrawColor(arena->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	if (!(arena->screen_surface = SDL_GetWindowSurface(arena->window)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Screen surface init error",
								SDL_GetError(),
								NULL);
		return (false);
	}
	return (true);
}

bool				init(t_arena *arena)
{
	if (!init_devices())
		return (false);
	bzero(arena, sizeof(t_arena));
	init_music(arena);
	arena->msgbox_buttons[NO_BUTTON_ID] = (SDL_MessageBoxButtonData)NO_BUTTON;
	arena->msgbox_buttons[YES_BUTTON_ID] = (SDL_MessageBoxButtonData)YES_BUTTON;
	arena->msgbox_buttons[CANSEL_BUTTON_ID] = (SDL_MessageBoxButtonData)CANSEL_BUTTON;
	arena->window = NULL;
	if (SDL_GetDesktopDisplayMode(0, &(arena->d_mode)) !=
			GET_DMODE_SUCCESS)
	{
		force_error(SDL_GetError());
        return (false);
	}
	if (!create_window(arena))
		return (false);
	t_ltexture *background = load_from_file(BACK_IMG,
											arena->renderer,
											(SDL_Color){.r=0,.g=0,.b=0});
	SDL_Rect clip = get_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	t_rposition pos = get_render_position(0, NULL, NULL, &clip);
	render(&pos, background, arena->renderer, SDL_FLIP_NONE);
	init_figures(arena);
	if (!init_controls(arena))
		return (false);
	if (!(arena->tile_block =
			load_from_file(TILEBLOCK_IMG,
							arena->renderer,
							(SDL_Color){.r = 0x0, .g = 0x0, .b = 0x0, .a = 0xff})))
		return (false);
	return (true);
}
