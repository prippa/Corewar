/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_outlinerect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:42:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 12:43:01 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_outlinerect(t_arena *arena, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(arena->renderer, 0x0, 0x0, 0x0, 0xff);
	SDL_RenderDrawRect(arena->renderer, &rect);
}
