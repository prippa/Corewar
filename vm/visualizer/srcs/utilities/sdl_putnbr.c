/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:17:41 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/21 16:17:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				get_width(t_nbrinfo rnbr)
{
	int			figure_count;
	int			tmp;

	tmp = rnbr.nbr;
	figure_count = 1;
	while ((tmp /= 10))
		figure_count++;
	if (figure_count < rnbr.min_width)
		figure_count = rnbr.min_width;
	return (figure_count);
}

void			sdl_putnbr(t_nbrinfo rnbr, SDL_Rect clip, t_arena *arena)
{
	SDL_Point	top_left;
	int			figure_count;
	int			figure_width;
	int			figure_height;
	int			figure;

	figure_count = get_width(rnbr);
	figure_height = clip.h;
	figure_width = clip.w / figure_count;
	top_left.x = clip.x + clip.w - figure_width;
	top_left.y = clip.y;
	while (figure_count--)
	{
		figure = rnbr.nbr % 10;
		rnbr.nbr /= 10;
		set_color(rnbr.c, arena->bold_figures[figure]);
		render(get_render_position(0,
		top_left, top_left,
		get_point(figure_width, figure_height)),
		arena->bold_figures[figure], arena->renderer, SDL_FLIP_NONE);
		top_left.x -= figure_width;
	}
}
