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

static inline void	draw_move_panel(t_arena *arena)
{
	int				panel_width;
	t_rposition		pos;
	SDL_Point		p;

	panel_width = SCREEN_HEIGHT - arena->abs_arena_height;
	p = get_point(0, arena->abs_arena_height);
	pos = get_render_position(0, p, p, get_point(panel_width, panel_width));
	render(pos, arena->move_panel, arena->renderer, SDL_FLIP_NONE);
}

void				draw_controls(t_arena *arena)
{
	int				i;

	i = -1;
	while (++i < TOTAL_CHECKBOXES)
		render_checkbox_sprite(arena->checkboxes[i], arena);
	i = -1;
	while (++i < TOTAL_START_BUTTONS)
		render_button_sprite(arena->start_btns[i], arena);
	draw_move_panel(arena);
	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		render_button_sprite(arena->move_btns[i], arena);
}
