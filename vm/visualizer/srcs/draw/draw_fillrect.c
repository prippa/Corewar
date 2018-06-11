/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fillrect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:42:40 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 12:42:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			draw_fillrect(t_arena *arena,
								int i, int j,
								SDL_Rect rect)
{

	t_rposition	position;
	SDL_Point	left_corner = {.x = rect.x, .y = rect.y};
	int	cell = arena->bytes[i * ARENA_TILE_HEIGHT + j];
	int ff = 0;
	int sf = 0;
	ff = (cell >> 4);
	sf = ((ff << 4) ^ cell);

	position = get_render_position(0, &left_corner, NULL, &rect);
	set_color(arena->colors[i * ARENA_WIDTH + j], arena->tile_block);
	render(&position, arena->tile_block, arena->renderer, SDL_FLIP_NONE);
	//SDL_Color c = arena->colors[i * ARENA_WIDTH + j];
	//SDL_SetRenderDrawColor(arena->renderer, 0x00, 0x00, 0x00, 0xff);
	//SDL_RenderFillRect(arena->renderer, &rect);
	rect.w /= 2;
	position = get_render_position(0, &left_corner, NULL, &rect);
	render(&position, arena->figures[ff], arena->renderer, SDL_FLIP_NONE);
	rect.x += rect.w;
	left_corner.x += rect.w;
	position = get_render_position(0, &left_corner, NULL, &rect);
	render(&position, arena->figures[sf], arena->renderer, SDL_FLIP_NONE);
}
