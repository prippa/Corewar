/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_checkbox_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:53:08 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/05 13:53:10 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline bool	is_mouse_event_happened(int type)
{
	return (type == SDL_MOUSEMOTION ||
			type == SDL_MOUSEBUTTONDOWN ||
			type == SDL_MOUSEBUTTONUP);
}

static inline bool	is_mouse_outside_checkbox(int x, int y,
											SDL_Point position,
											t_arena *arena)
{
	return (x < position.x ||
			x > position.x + CHECKBOX_WIDTH ||
			y < position.y ||
			y > position.y + CHECKBOX_HEIGHT);
}

void				handle_checkbox_event(SDL_Event *e,
										t_checkbox *cbx,
										t_arena *arena)
{
	int				x;
	int				y;

	if (is_mouse_event_happened(e->type))
	{
		SDL_GetMouseState(&x, &y);
		if (is_mouse_outside_checkbox(x, y, cbx->position, arena))
		{
			cbx->current_sprite = (cbx->checked) ? CHECK_MOUSE_OUT :
													CROSS_MOUSE_OUT;
		}
		else if (e->type == SDL_MOUSEMOTION)
			cbx->current_sprite = (cbx->checked) ? CHECK_MOUSE_IN : CROSS_MOUSE_IN;
		else if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			cbx->checked = (cbx->checked) ? false : true;
			cbx->current_sprite = (cbx->checked) ? CHECK_MOUSE_IN : CROSS_MOUSE_IN;
		}
		else if (e->type == SDL_MOUSEBUTTONUP)
		{
			cbx->current_sprite = (cbx->checked) ? CHECK_MOUSE_IN : CROSS_MOUSE_IN;
			change_screen_mode(arena);
		}
	}
}
