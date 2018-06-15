/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:23:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 14:23:21 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

bool			init_controls(t_arena *arena)
{
	bool		success;
	int wd = SCREEN_WIDTH - BUTTON_WIDTH - (SCREEN_WIDTH >> 6);
	
	success = true;
	bzero(arena->full_sprites, sizeof(arena->full_sprites));
	if (!(arena->full_sprites[CHECK_MOUSE_OUT] =
			load_from_file(CHECK_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->full_sprites[CHECK_MOUSE_IN] =
			load_from_file(CHECK_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->full_sprites[CROSS_MOUSE_OUT] =
			load_from_file(CROSS_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->full_sprites[CROSS_MOUSE_IN] =
			load_from_file(CROSS_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})))
	{
		success = false;
	}
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, arena->full_sprites[CHECK_MOUSE_IN]);
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, arena->full_sprites[CROSS_MOUSE_IN]);
	if (!init_start_buttons(arena))
		success = false;
	if (!init_move_buttons(arena))
		success = false;
	if (!(arena->full_btn = create_checkbox((SDL_Point){.x = wd, .y = 20},
									"FULLSCREEN",
									arena->renderer)))
		success = false;
	if (!success)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Error!",
								SDL_GetError(),
								NULL);
	}
	return (success);
}
