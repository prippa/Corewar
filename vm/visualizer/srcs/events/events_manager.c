/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:49:47 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 17:49:49 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void				events_handler(t_arena *arena)
{
	SDL_Event		*e;
	SDL_Point		bp;
	
	e = &(arena->e);
	bzero(&bp, sizeof(SDL_Point));
	t_ltexture *background = load_from_file(BACK_IMG,
											arena->renderer,
											(SDL_Color){.r=0,.g=0,.b=0});
	SDL_Rect clip = get_rectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	t_rposition pos = get_render_position(0, NULL, NULL, &clip);
	while (!arena->quit)
	{
		clear_renderer(arena->renderer);
		render(&pos, background, arena->renderer, SDL_FLIP_NONE);
		while (SDL_PollEvent(e))
		{
			if (e->type == SDL_QUIT)
				exit_event(arena);
			else if (e->type == SDL_KEYDOWN)
				key_event(arena, e->key.keysym.sym);
			else if (e->type == SDL_MOUSEWHEEL)
			{
				wheel_event(arena, e->wheel.y);
			}
			for (int i = 0; i < BUTTON_TOTAL; i++)
				handle_button_event(e, arena->start_btns[i], arena, i);
			handle_checkbox_event(e, g_full_btn, arena);
		}
		render_checkbox_sprite(g_full_btn, arena->renderer);
		for (int i = 0; i < BUTTON_TOTAL; i++)
			render_button_sprite(arena->start_btns[i], arena);
		if (arena->is_rendered)
		{
			if (arena->pause == false)
				set_random(arena);
			draw_arena(arena);
		}
		SDL_RenderPresent(arena->renderer);
	}
}
