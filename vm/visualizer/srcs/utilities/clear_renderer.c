/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 18:51:47 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 18:51:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	clear_renderer(t_arena *arena)
{
	draw_fillrect(arena->viewport, BLACK_COLOR, arena->renderer);
}
