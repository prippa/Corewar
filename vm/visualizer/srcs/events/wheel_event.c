/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:06:34 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 19:06:36 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	wheel_event(t_arena *arena, int wheel_direction)
{
	int	x;
	int	y;

	SDL_GetMouseState(&x, &y);
	if (wheel_direction == 1)
		zoom_in(x, y, arena);
	else
		zoom_out(x, y, arena);
}
