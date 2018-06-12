/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:02:52 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 18:02:54 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

SDL_Texture		*load_texture(const char *path,
							SDL_PixelFormat *screen_format,
							SDL_Renderer **renderer)
{
	SDL_Texture	*new_texture;
	SDL_Surface	*loaded_surface;

	loaded_surface = load_surface(path, screen_format);
	new_texture = NULL;
	if (!(new_texture = SDL_CreateTextureFromSurface(*renderer,
												loaded_surface)))
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
									"Unable to create texture",
									SDL_GetError(),
									NULL);
		SDL_FreeSurface(loaded_surface);
	}
	return (new_texture);
}
