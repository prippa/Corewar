/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_render_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:56:39 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/30 15:56:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_rposition		get_render_position(double angle,
					SDL_Point left_corner,
					SDL_Point center,
					SDL_Point params)
{
	return ((t_rposition){.angle = angle,
				.left_corner = left_corner,
				.center = center,
				.width = params.x,
				.height = params.y});
}
