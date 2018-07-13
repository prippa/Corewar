/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:51:47 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 18:51:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	clear_renderer(t_arena *arena)
{
	SDL_SetRenderDrawColor(arena->renderer, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(arena->renderer);
	//SDL_RenderFillRect(arena->renderer, &(arena->viewport));
}
