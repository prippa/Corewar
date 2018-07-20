/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:14:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 16:14:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		exit_event(void *data)
{
	int		buttonid;
	t_arena	*arena;

	arena = (t_arena *)data;
	buttonid = exit_dialog(arena);
	if (arena->is_fullscreen)
		change_screen_mode(arena);
	if (buttonid == YES_BUTTON_ID)
	{
		Mix_PauseMusic();
		Mix_PlayChannel(-1, arena->exit_sound, 0);
		arena->quit = true;
	}
}
