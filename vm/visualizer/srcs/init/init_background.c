/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:08:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/03 13:08:15 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

bool			init_background(t_arena *arena)
{
	if ((arena->background = load_from_file(BACK_IMG, arena->renderer, BLACK_COLOR)))
		return (true);
	return (false);
}