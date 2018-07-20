/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_winner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:40:31 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 18:40:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_winner(t_arena *arena)
{
	if (g_cw.game_over == false)
	{
		render(get_render_position(0,
		(SDL_Point){.x = BUTTON_WIDTH}, (SDL_Point){0},
		(SDL_Point){arena->viewport.w - (BUTTON_WIDTH << 1),
		SCREEN_WIDTH >> 2}),
		arena->hail,
		arena->renderer,
		SDL_FLIP_NONE);
	}
}
