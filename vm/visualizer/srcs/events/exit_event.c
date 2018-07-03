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

void	exit_event(t_arena *arena)
{
	int	buttonid;

	buttonid = exit_dialog(arena);
	if (buttonid == YES_BUTTON_ID)
		arena->quit = true;
}
