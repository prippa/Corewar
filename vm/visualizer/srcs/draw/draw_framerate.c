/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_framerate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:41:04 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 14:41:06 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_framerate(t_arena *arena)
{
	if (arena->show_fps)
		sdl_putnbr((t_nbrinfo){.nbr = arena->old_fps, .c = RED_COLOR, .min_width = 3},
					get_rectangle(SCREEN_WIDTH - 90, SCREEN_HEIGHT - 60, 90, 60),
					arena);
}
