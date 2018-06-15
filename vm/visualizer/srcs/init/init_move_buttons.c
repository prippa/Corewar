/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_move_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:43:41 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 17:43:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

bool	init_move_buttons(t_arena *arena)
{
	int wd = SCREEN_WIDTH - BUTTON_WIDTH - ((SCREEN_WIDTH >> 6));
	bzero(arena->move_btn_sprites, sizeof(arena->move_btn_sprites));
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OUT] = load_from_file(ARROW_IMG,
																arena->renderer,
																DEFAULT_COLOR_KEY);
	set_alpha_mode(100, arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OUT]);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION] = load_from_file(ARROW_IMG,
																arena->renderer,
																DEFAULT_COLOR_KEY);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN] = load_from_file(ARROW_IMG,
																arena->renderer,
																DEFAULT_COLOR_KEY);
	set_color((SDL_Color){.g=0xff},
				arena->move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN]);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_UP] = load_from_file(ARROW_IMG,
																arena->renderer,
																DEFAULT_COLOR_KEY);
	if (!(arena->move_btns[UP_MENU_BTN] =
			create_button(-90, (SDL_Point){.x = wd, .y = 150 + MOVE_BTN_HEIGHT},
							NULL, arena->renderer,
							(SDL_Point){.x=MOVE_BTN_WIDTH, .y=MOVE_BTN_HEIGHT},
							arena->move_btn_sprites)) ||
		!(arena->move_btns[RIGHT_MENU_BTN] =
			create_button(0, (SDL_Point){.x = wd + 100, .y = 250 + MOVE_BTN_HEIGHT},
							NULL, arena->renderer,
							(SDL_Point){.x=MOVE_BTN_WIDTH, .y=MOVE_BTN_HEIGHT},
							arena->move_btn_sprites)) ||
		!(arena->move_btns[DOWN_MENU_BTN] =
			create_button(90, (SDL_Point){.x = wd, .y = 350 + MOVE_BTN_HEIGHT},
							NULL, arena->renderer,
							(SDL_Point){.x=MOVE_BTN_WIDTH, .y=MOVE_BTN_HEIGHT},
							arena->move_btn_sprites)) ||
		!(arena->move_btns[LEFT_MENU_BTN] =
			create_button(180, (SDL_Point){.x = wd - 100, .y = 250 + MOVE_BTN_HEIGHT},
							NULL, arena->renderer,
							(SDL_Point){.x=MOVE_BTN_WIDTH, .y=MOVE_BTN_HEIGHT},
							arena->move_btn_sprites)))
		return (false);
	return (true);
}