/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:03:27 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 19:03:29 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	info(void *arena)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
	"Corewar project",
	INFO_TXT,
	((t_arena *)arena)->window);
}
