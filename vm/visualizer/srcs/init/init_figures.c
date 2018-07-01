/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:26:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 17:26:26 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		init_figures(t_arena *arena)
{
	int		font_weight;
	int		i;
	char	buf[2];

	buf[1] = 0;
	font_weight = ARENA_TILE_WIDTH * MAX_ZOOM;
	double k = ((double)(arena->d_mode.w) / (double)(SCREEN_WIDTH));
	font_weight *= k;
	i = -1;
	while (++i < 0x10)
	{
		buf[0] = (i < 0xa) ? i + 48 : 'F' - (0xf - i);
		arena->figures[i] =
			load_from_rendered_text(get_text_info(
									ROBOTO_REGULAR,
									font_weight,
									buf,
									(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff, .a = 0xff}),
									arena->renderer);
	}
}
