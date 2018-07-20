/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fillrect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:55:36 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 16:55:38 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_fillrect(SDL_Rect rect, SDL_Color rgb, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, rgb.r, rgb.g, rgb.b, rgb.a);
	SDL_RenderFillRect(renderer, &rect);
}
