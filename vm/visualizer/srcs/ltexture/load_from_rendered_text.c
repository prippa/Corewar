/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_from_rendered_text.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:14:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/30 19:14:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#ifdef _SDL_TTF_H

t_text			get_text_info(const char *font_name,
								int font_weight,
								const char *txt,
								SDL_Color txt_color)
{
	t_text		info;

	info.font_name = font_name;
	info.font_weight = font_weight;
	info.txt = txt;
	info.txt_color = txt_color;
	return (info);
}

t_ltexture		*load_from_rendered_text(t_text info,
										SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	TTF_Font	*font;
	t_ltexture	*lt;

	surface = NULL;
	font = NULL;
	if (!(lt = (t_ltexture *)malloc(sizeof(t_ltexture))))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!",
									"Bad allocating", NULL);
	else if (!(font = TTF_OpenFont(info.font_name, info.font_weight)))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!",
									TTF_GetError(), NULL);
	else if (!(surface = TTF_RenderText_Solid(font, info.txt, info.txt_color)))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!",
									TTF_GetError(), NULL);
	else if (!(lt->texture = SDL_CreateTextureFromSurface(renderer, surface)))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!",
									TTF_GetError(), NULL);
	else
	{
		lt->width = surface->w;
    	lt->height = surface->h;
		SDL_FreeSurface(surface);
		free(font);
	}
	return ((lt->texture) ? lt : NULL);
}

#endif
