/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:25:03 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 14:25:05 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline bool	init_sprites(t_arena *arena)
{
	if (!(arena->start_btn_sprites[BUTTON_MOUSE_OUT] =
			load_from_file(MENU_OUT_IMG,
							arena->renderer,
							DEFAULT_COLOR_KEY)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_OVER_MOTION] =
			load_from_file(MENU_ON_IMG,
							arena->renderer,
							DEFAULT_COLOR_KEY)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_DOWN] =
			load_from_file(MENU_DOWN_IMG,
							arena->renderer,
							DEFAULT_COLOR_KEY)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_UP] =
			load_from_file(MENU_UP_IMG,
							arena->renderer,
							DEFAULT_COLOR_KEY)))
		return (false);
	return (true);
}

bool				init_start_buttons(t_arena *arena)
{
	int				wd;

	bzero(arena->start_btn_sprites, sizeof(arena->start_btn_sprites));
	wd = SCREEN_WIDTH - BUTTON_WIDTH - ((SCREEN_WIDTH >> 6));
	if (!init_sprites(arena))
		return (false);
	if (!(arena->start_btns[START_MENU_BTN] =
			create_button(0, (SDL_Point){.x = wd, .y = 2 * BUTTON_HEIGHT},
							"START", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[STOP_MENU_BTN] =
			create_button(0, (SDL_Point){.x = wd, .y = 4 * BUTTON_HEIGHT},
							"STOP", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[INFO_MENU_BTN] =
			create_button(0, (SDL_Point){.x = wd, .y = 6 * BUTTON_HEIGHT},
							"INFO", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[EXIT_MENU_BTN] =
			create_button(0, (SDL_Point){.x = wd, .y = 8 * BUTTON_HEIGHT},
							"EXIT", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)))
		return (false);
	return (true);
}
