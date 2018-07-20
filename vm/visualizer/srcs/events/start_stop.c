/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:06:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/20 19:06:15 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		start(void *arena)
{
	t_arena	*a;

	a = (t_arena *)arena;
	a->pause = false;
}

void		stop(void *arena)
{
	t_arena	*a;

	a = (t_arena *)arena;
	a->pause = true;
}
