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
									SDL_Point *left_corner,
									SDL_Point *center,
									SDL_Rect *clip)
{
	t_rposition	rp;

	rp.angle = angle;
	if (left_corner == NULL)
	{
		rp.left_corner = (SDL_Point *)malloc(sizeof(SDL_Point));
		rp.left_corner->x = 0;
		rp.left_corner->y = 0;
	}
	else
		rp.left_corner = left_corner;
	rp.center = center;
	rp.clip = clip;
	return (rp);
}
