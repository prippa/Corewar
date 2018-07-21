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

const char *g_labels[TOTAL_START_BUTTONS] = LABELS;
void (*g_actionfuncs[TOTAL_START_BUTTONS])(void *) = ACTIONS;

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
	t_rposition		btn_pos;

	bzero(arena->start_btn_sprites, sizeof(arena->start_btn_sprites));
	if (!init_sprites(arena))
		return (false);
	btn_pos = get_render_position(0,
	get_point(BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT),
	get_point(BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT),
	get_point(BUTTON_WIDTH, BUTTON_HEIGHT));
	i = -1;
	while (++i < TOTAL_START_BUTTONS)
	{
		arena->start_btns[i] = create_button(btn_pos,
			g_labels[i],
			arena->renderer,
			arena->start_btn_sprites);
		arena->start_btns[i]->action = g_actionfuncs[i];
		btn_pos.left_corner.x += BUTTON_WIDTH;
		btn_pos.center.x += BUTTON_WIDTH;
	}
	return (true);
}
