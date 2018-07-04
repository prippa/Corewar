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

static inline void	dequeue_events(t_arena *arena)
{
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
	for (int i = 0; i < MOVE_BUTTON_TOTAL; i++)
		handle_movebutton_event(NULL, arena->move_btns[i], arena, i);
}

static inline void	handle_arena_rendering(t_arena *arena,
											clock_t begin,
											clock_t end,
											int *tacts_before_render)
{
	if (arena->is_rendered)
	{
		*tacts_before_render -= (end - begin);
		if (*tacts_before_render <= 0)
		{
			*tacts_before_render = 200000;
			if (arena->pause == false)
				set_random(arena);
		}
		draw_arena(arena);
	}
}

void				events_handler(t_arena *arena)
{
	clock_t			begin;
	int				tacts_before_render;

	begin = 0;
	tacts_before_render = 0;
	init_background(arena);
	Mix_PlayMusic(arena->theme, -1);
	while (!arena->quit)
	{
		begin = clock();
		clear_renderer(arena->renderer);
		draw_background(arena);
		dequeue_events(arena);
		draw_controls(arena);
		handle_arena_rendering(arena, begin, clock(), &tacts_before_render);	
		SDL_RenderPresent(arena->renderer);
	}
}
