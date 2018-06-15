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
	SDL_Point		bp;
	
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
		while (SDL_PollEvent(&(arena->e)))
		{
			if (arena->e.type == SDL_QUIT)
				exit_event(arena);
			else if (arena->e.type == SDL_KEYDOWN)
				key_event(arena, arena->e.key.keysym.sym);
			else if (arena->e.type == SDL_MOUSEWHEEL)
				wheel_event(arena, arena->e.wheel.y);
			for (int i = 0; i < BUTTON_TOTAL; i++)
				handle_button_event(&(arena->e), arena->start_btns[i], arena, i);
			for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
				handle_movebutton_event(&(arena->e), arena->move_btns[i], arena, i);
			handle_checkbox_event(&(arena->e), arena->full_btn, arena);
		}
		render_checkbox_sprite(arena->full_btn, arena);
		for (int i = 0; i < BUTTON_TOTAL; i++)
			render_button_sprite(arena->start_btns[i], arena);
		for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
			render_button_sprite(arena->move_btns[i], arena);
		if (arena->is_rendered)
		{
			if (arena->pause == false)
				set_random(arena);
			draw_arena(arena);
		}
		SDL_RenderPresent(arena->renderer);
	}
}
