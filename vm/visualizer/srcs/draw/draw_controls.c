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
	render_checkbox_sprite(arena->full_btn, arena);
	for (int i = 0; i < BUTTON_TOTAL; i++)
		render_button_sprite(arena->start_btns[i], arena);
	SDL_Point p = {.x = SCREEN_WIDTH - BUTTON_WIDTH - ((SCREEN_WIDTH >> 6)), .y = 10 * BUTTON_HEIGHT};
	SDL_Rect clip = (SDL_Rect){.x=0,.y=0,.w=BUTTON_WIDTH,.h=BUTTON_WIDTH};
	t_rposition pos = get_render_position(0, &p, NULL, &clip);
	render(&pos, arena->move_panel, arena->renderer, SDL_FLIP_NONE);
	for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
		render_button_sprite(arena->move_btns[i], arena);
}

