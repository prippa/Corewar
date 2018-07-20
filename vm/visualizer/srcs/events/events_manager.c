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
	int				i;

	while (SDL_PollEvent(&(arena->e)))
	{
		if (arena->e.type == SDL_QUIT)
			exit_event(arena);
		else if (arena->e.type == SDL_KEYDOWN)
			key_event(arena, arena->e.key.keysym.sym);
		else if (arena->e.type == SDL_MOUSEWHEEL)
			wheel_event(arena, arena->e.wheel.y);
		i = -1;
		while (++i < TOTAL_START_BUTTONS)
			handle_button_event(&(arena->e), arena->start_btns[i], arena);
		i = -1;
		while (++i < MOVE_BUTTON_TOTAL)
			handle_movebutton_event(&(arena->e), arena->move_btns[i], arena);
		i = -1;
		while (++i < TOTAL_CHECKBOXES)
			handle_checkbox_event(&(arena->e), arena->checkboxes[i], arena, i);
	}
	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		handle_movebutton_event(NULL, arena->move_btns[i], arena);
}

static inline void	game_over(t_arena *arena)
{
	t_champ			*champion;
	char			*hail;
	SDL_Color		c;

	g_cw.game_over = false;
	g_cw.cycle_to_die = 0;
	champion = t_champ_find(g_cw.last_reported_to_be_alive, g_cw.pd.champs);
	hail = ft_strdup("Contestant 0 won!");
	hail[11] = champion->champ_number * (-1) + '0';
	if (champion->color == 1)
		c = LIGHT_GREEN;
	else if (champion->color == 2)
		c = LIGHT_BLUE;
	else if (champion->color == 3)
		c = LIGHT_RED;
	else
		c = CYAN_COLOR;
	arena->hail = load_from_rendered_text(
		get_text_info(WESTERN_SWING, 1200, hail, c),
		arena->renderer);
	free(hail);
	t_processes_free(&g_cw.proc_start, &g_cw.proc_end);
	cw_vis_update_map();
}

static inline void	handle_arena_rendering(t_arena *arena, clock_t diff)
{
	static int		tacts_before_update;
	int				i;

	if (arena->pause == false)
	{
		tacts_before_update += diff;
		if (tacts_before_update >= arena->tact_duration && g_cw.game_over)
		{
			i = -1;
			while (++i < arena->cycles_per_tact)
			{
				if (!cw_visu_game_loop())
				{
					game_over(arena);
					break ;
				}
				cw_vis_update_map();
			}
			tacts_before_update = 0;
		}
	}
}

static inline void	handle_fps(t_arena *arena, clock_t diff)
{
	static int tacts_per_second = 0;

	tacts_per_second -= diff;
	arena->fps++;
	if (tacts_per_second <= 0)
	{
		tacts_per_second = 1000000;
		arena->old_fps = arena->fps;
		arena->fps = 0;
	}
}

void				events_handler(t_arena *arena)
{
	clock_t			diff;

	Mix_PlayMusic(arena->theme, -1);
	cw_vis_update_map();
	while (!arena->quit)
	{
		diff = clock();
		clear_renderer(arena);
		dequeue_events(arena);
		draw_arena(arena);
		draw_winner(arena);
		draw_infopanel(arena);
		draw_button_panel(arena);
		draw_controls(arena);
		draw_statuses(arena);
		draw_framerate(arena);
		handle_arena_rendering(arena, clock() - diff);
		handle_fps(arena, clock() - diff);
		SDL_RenderPresent(arena->renderer);
	}
}
