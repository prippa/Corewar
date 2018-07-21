/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:09:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/21 16:09:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		reset(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	arena->zoom = 1.0;
	arena->top_left.x = 0;
	arena->top_left.y = 0;
}
