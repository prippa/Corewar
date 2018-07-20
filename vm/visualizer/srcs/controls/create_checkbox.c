/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_checkbox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:36:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/05 13:37:00 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	create_checkbox_text(t_checkbox *cbx,
										const char *text,
										t_arena *arena)
{
	SDL_Point		txt_top_left;
	t_ltexture		*texture;

	if (text != NULL)
	{
		txt_top_left.x = cbx->position.x + CHECKBOX_WIDTH;
		txt_top_left.y = cbx->position.y;
		texture = load_from_rendered_text(get_text_info(ROBOTO_BLACK,
											(CHECKBOX_HEIGHT << 2),
											text,
											BLACK_COLOR),
											arena->renderer);
		cbx->checkbox_txt = texture;
		cbx->txt_position = txt_top_left;
	}
	else
		cbx->checkbox_txt = NULL;
}

t_checkbox			*create_checkbox(SDL_Point position,
									const char *text,
									t_arena *arena)
{
	t_checkbox		*new_checkbox;

	new_checkbox = NULL;
	if (!(new_checkbox = (t_checkbox *)malloc(sizeof(t_checkbox))))
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
									"Error!",
									"Bad allocation",
									NULL);
	else
	{
		new_checkbox->checked = false;
		new_checkbox->position = position;
		new_checkbox->current_sprite = CROSS_MOUSE_OUT;
		create_checkbox_text(new_checkbox, text, arena);
	}
	return (new_checkbox);
}
