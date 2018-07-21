/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_button_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:21:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 14:21:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void				render_button_sprite(t_button *btn, t_arena *arena)
{
	if (btn->button_txt)
	{
		render(btn->btn_pos,
				((t_ltexture **)(btn->sprites))[btn->current_sprite],
				arena->renderer,
				SDL_FLIP_NONE);
		render(btn->txt_pos, btn->button_txt,
			arena->renderer,
			SDL_FLIP_NONE);
	}
	else
	{
		render(btn->btn_pos,
			((t_ltexture **)(btn->sprites))[btn->current_sprite],
			arena->renderer,
			SDL_FLIP_NONE);
	}
}
