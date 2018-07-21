/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:23:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 14:23:21 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

bool			init_controls(t_arena *arena)
{
	init_checkboxes(arena);
	init_start_buttons(arena);
	init_move_buttons(arena);
	return (true);
}
