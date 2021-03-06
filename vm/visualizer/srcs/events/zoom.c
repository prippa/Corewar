/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:07:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 19:08:01 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	zoom_in(const int x,
				const int y,
				t_arena *arena)
{
	if (arena->zoom < MAX_ZOOM)
	{
		arena->zoom *= 1.1;
		arena->top_left.x -= 0.1 *
							(x - arena->top_left.x);
		arena->top_left.y -= 0.1 *
							(y - arena->top_left.y);
	}
}

void	zoom_out(const int x,
				const int y,
				t_arena *arena)
{
	if (arena->zoom > MIN_ZOOM)
	{
		arena->zoom *= 0.9;
		arena->top_left.x += 0.1 *
							(x - arena->top_left.x);
		arena->top_left.y += 0.1 *
							(y - arena->top_left.y);
	}
}
