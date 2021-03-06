/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duration_change.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:36:28 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 18:36:29 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		increase_duration(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	if (arena->tact_duration < 1000000)
		arena->tact_duration += 50000;
}

void		decrease_duration(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	if (arena->tact_duration > 0)
		arena->tact_duration -= 50000;
}
