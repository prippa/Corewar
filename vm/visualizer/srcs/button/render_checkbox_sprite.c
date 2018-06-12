/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_checkbox_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:17:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/05 14:17:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_ltexture		*g_full_sprites[TOTAL_FULL_SPRITES];
t_checkbox		*g_full_btn;

void				render_checkbox_sprite(t_checkbox *cbx,
											SDL_Renderer *renderer)
{
	t_rposition		cbx_pos;
	t_rposition		txt_pos;
	SDL_Rect		clip;

	clip = get_rectangle(cbx->position.x,
							cbx->position.y,
							CHECKBOX_WIDTH,
							CHECKBOX_HEIGHT);
	cbx_pos = get_render_position(0, &(cbx->position), NULL, &clip);
	render(&cbx_pos, g_full_sprites[cbx->current_sprite],
			renderer, SDL_FLIP_NONE);
	if (cbx->checkbox_txt)
	{
		txt_pos = get_render_position(0, &(cbx->txt_position), NULL, NULL);
		render(&txt_pos, cbx->checkbox_txt,
				renderer, SDL_FLIP_NONE);
		
	}
}
