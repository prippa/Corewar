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
							WHITE_COLOR)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_OVER_MOTION] =
			load_from_file(MENU_ON_IMG,
							arena->renderer,
							WHITE_COLOR)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_DOWN] =
			load_from_file(MENU_DOWN_IMG,
							arena->renderer,
							WHITE_COLOR)) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_UP] =
			load_from_file(MENU_UP_IMG,
							arena->renderer,
							WHITE_COLOR)))
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
			create_button(0, (SDL_Point){.x = 2 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"START", arena->renderer,
							(SDL_Point){.x= BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[STOP_MENU_BTN] =
			create_button(0, (SDL_Point){.x = 3 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"STOP", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[INFO_MENU_BTN] =
			create_button(0, (SDL_Point){.x = 4 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"INFO", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)) ||
		!(arena->start_btns[EXIT_MENU_BTN] =
			create_button(0, (SDL_Point){.x = 5 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"EXIT", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites)))
		return (false);
	arena->start_btns[DUR_PLUS_BTN] =
			create_button(0, (SDL_Point){.x = 6 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"D+", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites);
	arena->start_btns[DUR_MIN_BTN] =
			create_button(0, (SDL_Point){.x = 7 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"D-", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites);
	arena->start_btns[CYCLE_PLUS_BTN] =
			create_button(0, (SDL_Point){.x = 8 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"C+", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites);
	arena->start_btns[CYCLE_MIN_BTN] =
			create_button(0, (SDL_Point){.x = 9 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"C-", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites);
	arena->start_btns[BACK_BTN] =
			create_button(0, (SDL_Point){.x = 10 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
							"BACK", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT},
							arena->start_btn_sprites);
	void (*action_funcs[TOTAL_START_BUTTONS])(void *) = {&start, &stop, &info, &exit_event,
																&increase_duration, &decrease_duration,
																&increase_cycles, &decrease_cycles, &reset};
	int i = -1;
	while (++i < (int)TOTAL_START_BUTTONS)
		arena->start_btns[i]->action = action_funcs[i];
	return (true);
}
