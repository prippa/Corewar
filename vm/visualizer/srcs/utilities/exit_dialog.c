/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_dialog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:37:24 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 13:37:26 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void				init_msgbox_data(SDL_MessageBoxData *msgboxdata,
												t_arena *arena)
{
	SDL_MessageBoxColorScheme	color_scheme;

	color_scheme = (SDL_MessageBoxColorScheme)MESSAGE_BOX_COLOR_SCHEME;
	msgboxdata->flags = SDL_MESSAGEBOX_INFORMATION;
	msgboxdata->window = NULL;
	msgboxdata->title = "Exit";
	msgboxdata->message = "Do you really want to exit?";
	msgboxdata->numbuttons = MESSAGE_BOX_BUTTON_NBR;
	msgboxdata->buttons = arena->msgbox_buttons;
	msgboxdata->colorScheme = &(color_scheme);
}

int								exit_dialog(t_arena *arena)
{
	int							dialog_result;
	SDL_MessageBoxData			msgboxdata;

	init_msgbox_data(&msgboxdata, arena);
	SDL_ShowMessageBox(&msgboxdata, &dialog_result);
	Mix_PlayChannel(-1, arena->btn_press, 0);
	return (dialog_result);
}
