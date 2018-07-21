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

void			render(t_rposition position,
						t_ltexture *ltexture,
						SDL_Renderer *renderer,
						SDL_RendererFlip flip)
{
	SDL_Rect	render_quad;

	render_quad = get_rectangle(position.left_corner.x,
								position.left_corner.y,
								position.width,
								position.height);
	SDL_RenderCopyEx(renderer, ltexture->texture, NULL,
					&render_quad, position.angle, NULL, flip);
}
