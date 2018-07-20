/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button_panel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:43:12 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 16:43:14 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			draw_button_panel(t_arena *arena)
{
	SDL_Rect	clip;

	clip = get_rectangle(0,
			arena->abs_arena_height,
			arena->abs_arena_width,
			arena->abs_arena_height);
	draw_fillrect(clip, arena->leader_color, arena->renderer);
}
