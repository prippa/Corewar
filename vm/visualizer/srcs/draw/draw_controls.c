/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:52:49 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/03 12:52:52 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_controls(t_arena *arena)
{
	for (int i = 0; i < TOTAL_CHECKBOXES; i++)
		render_checkbox_sprite(arena->checkboxes[i], arena);
	for (int i = 0; i < TOTAL_START_BUTTONS; i++)
		render_button_sprite(arena->start_btns[i], arena);
	int panel_width = SCREEN_HEIGHT - arena->abs_arena_height;
	SDL_Point p = {.x = 0, .y = arena->abs_arena_height};
	SDL_Rect clip = get_rectangle(0, 0, panel_width, panel_width);
	t_rposition pos = get_render_position(0, &p, NULL, &clip);
	render(&pos, arena->move_panel, arena->renderer, SDL_FLIP_NONE);
	for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
		render_button_sprite(arena->move_btns[i], arena);
}

