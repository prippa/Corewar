/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:56:08 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/29 12:56:10 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			render(t_rposition *position,
						t_ltexture *ltexture,
						SDL_Renderer *renderer,
						SDL_RendererFlip flip)
{
	SDL_Rect	render_quad;
	SDL_Rect	*clip;

	render_quad = get_rectangle(position->left_corner->x,
								position->left_corner->y,
								ltexture->width,
								ltexture->height);
	clip = NULL;
	if (position->clip != NULL)
	{
		render_quad.w = position->clip->w;
		render_quad.h = position->clip->h;
	}
	if (SDL_RenderCopyEx(renderer,
						ltexture->texture,
						clip,
						&render_quad,
						position->angle,
						position->center,
						flip) < 0)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Render copy action failed",
								SDL_GetError(),
								NULL);
	}
}
