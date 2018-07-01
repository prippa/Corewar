/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:21:41 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 16:21:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "base.h"

/*
** Main event loop
*/
void	events_handler(t_arena *arena);

/*
** Events on key press
*/
void	key_event(t_arena *arena, SDL_Keycode sym);

/*
** Events on exit actions
*/
void	exit_event(t_arena *arena);

/*
** Events on wheel actions
*/
void	wheel_event(t_arena *arena, int wheel_direction);

/*
** Zoom in arena
*/
void	zoom_in(const int x,
				const int y,
				t_arena *arena);

/*
** Zoom out arena
*/
void	zoom_out(const int x,
				const int y,
				t_arena *arena);

void	move_up(t_arena *arena);
void	move_down(t_arena *arena);
#endif
