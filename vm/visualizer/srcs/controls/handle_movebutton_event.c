/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movebutton_event.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 14:16:20 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 14:16:21 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline bool	is_mouse_event_happened(int type)
{
	return (type == SDL_MOUSEMOTION ||
			type == SDL_MOUSEBUTTONDOWN ||
			type == SDL_MOUSEBUTTONUP);
}

static inline bool	is_mouse_outside_movebtn(int x,
											int y,
											SDL_Point position,
											t_arena *arena)
{
	return (x < position.x ||
			x > position.x + MOVE_BTN_WIDTH ||
			y < position.y ||
			y > position.y + MOVE_BTN_WIDTH);
}

static inline void	happened(SDL_Point p,
							t_button *btn,
							t_arena *arena,
							SDL_Event *e)
{
	if (is_mouse_outside_movebtn(p.x, p.y, btn->btn_pos.left_corner, arena))
		btn->current_sprite = MOVE_BUTTON_MOUSE_OUT;
	else if (e->type == SDL_MOUSEMOTION)
	{
		if (btn->current_sprite != BUTTON_MOUSE_OVER_MOTION)
			Mix_PlayChannel(-1, arena->btn_move, 0);
		btn->current_sprite = MOVE_BUTTON_MOUSE_OVER_MOTION;
	}
	else if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		Mix_PlayChannel(-1, arena->btn_press, 0);
		btn->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	}
	else if (e->type == SDL_MOUSEBUTTONUP)
		btn->current_sprite = MOVE_BUTTON_MOUSE_UP;
}

void				handle_movebutton_event(SDL_Event *e,
										t_button *btn,
										t_arena *arena)
{
	SDL_Point		p;
	int				state;

	state = SDL_GetMouseState(&p.x, &p.y);
	if (e == NULL)
	{
		if (is_mouse_outside_movebtn(p.x, p.y, btn->btn_pos.left_corner, arena))
			btn->current_sprite = MOVE_BUTTON_MOUSE_OUT;
		else if (state)
		{
			btn->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
			btn->action(arena);
		}
	}
	else if (is_mouse_event_happened(e->type))
		happened(p, btn, arena, e);
}
