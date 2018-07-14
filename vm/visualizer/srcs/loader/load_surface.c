/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:32:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 17:32:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

SDL_Surface		*load_surface(const char *path,
								SDL_PixelFormat *screen_format)
{
	SDL_Surface	*optimized_surface;
	SDL_Surface	*loaded_surface;

	optimized_surface = NULL;
	loaded_surface = NULL;
	if (!(loaded_surface = IMG_Load(path)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
									"Missing file",
									SDL_GetError(),
									NULL);
	}
	else
	{
		if (!(optimized_surface = SDL_ConvertSurface(
								loaded_surface, screen_format, 0)))
		{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
									"Unable to optimize image",
									SDL_GetError(),
									NULL);
		}
		SDL_FreeSurface(loaded_surface);
	}
	return (optimized_surface);
}
