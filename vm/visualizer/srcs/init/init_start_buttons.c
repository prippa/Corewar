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
	int				i;


	bzero(arena->start_btn_sprites, sizeof(arena->start_btn_sprites));
	if (!init_sprites(arena))
		return (false);
	const char *labels[TOTAL_START_BUTTONS] = {"START", "STOP", "INFO", "EXIT",
												"D+", "D-", "C+", "C-", "BACK"};
	void (*action_funcs[TOTAL_START_BUTTONS])(void *) = {&start, &stop, &info, &exit_event,
																&increase_duration, &decrease_duration,
															&increase_cycles, &decrease_cycles, &reset};
	t_rposition btn_pos = get_render_position(0,
											(SDL_Point){.x = 2 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
											(SDL_Point){.x = 2 * BUTTON_WIDTH, .y = SCREEN_HEIGHT - BUTTON_HEIGHT},
											(SDL_Point){.x = BUTTON_WIDTH, .y = BUTTON_HEIGHT});
	i = -1;
	while (++i < TOTAL_START_BUTTONS)
	{
		arena->start_btns[i] =	create_button(btn_pos, labels[i], arena->renderer, arena->start_btn_sprites);
		arena->start_btns[i]->action = action_funcs[i];
		btn_pos.left_corner.x += BUTTON_WIDTH;
		btn_pos.center.x += BUTTON_WIDTH;
	}
	return (true);
}
