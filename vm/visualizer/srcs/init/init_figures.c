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

bool		init_figures(t_arena *arena)
{
	int		font_weight;
	int		i;
	char	buf[2];

	buf[1] = 0;
	i = -1;
	font_weight = ARENA_TILE_WIDTH * MAX_ZOOM;
	while (++i < 0x10)
	{
		buf[0] = (i < 0xa) ? i + 48 : 'F' - (0xf - i);
		if (!(arena->figures[i] = load_from_rendered_text(get_text_info(
									ROBOTO,
									font_weight,
									buf,
									WHITE_COLOR),
									arena->renderer)))
			return (false);
		if (!(arena->bold_figures[i] = load_from_rendered_text(get_text_info(
									ROBOTO_BLACK,
									font_weight,
									buf,
									WHITE_COLOR),
									arena->renderer)))
			return (false);
	}
	return (true);
}
