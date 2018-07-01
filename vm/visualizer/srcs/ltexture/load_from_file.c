/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:55:47 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 12:55:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_ltexture		*load_from_file(const char *path,
							SDL_Renderer *renderer,
							SDL_Color ckey)
{
	SDL_Texture	*new_texture;
	SDL_Surface	*loaded_surface;
	t_ltexture	*ltexture;

	new_texture = NULL;
	loaded_surface = NULL;
	ltexture = NULL;
	if (!(ltexture = (t_ltexture *)malloc(sizeof(t_ltexture))))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
								"Bad allocation", NULL);
	else if (!(loaded_surface = IMG_Load(path)))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
								IMG_GetError(), NULL);
	else
	{
		SDL_SetColorKey(loaded_surface, SDL_TRUE,
					SDL_MapRGB(loaded_surface->format, ckey.r, ckey.g, ckey.b));
		new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
		ltexture->width = loaded_surface->w;
		ltexture->height = loaded_surface->h;
		SDL_FreeSurface(loaded_surface);
		ltexture->texture = new_texture;
	}
	return ((ltexture->texture) ? ltexture : NULL);
}
