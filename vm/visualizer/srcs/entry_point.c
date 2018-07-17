/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:44:23 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/22 15:44:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	close_all(t_arena arena)
{
	int				i;

	i = -1;
	while (++i < FIGURES_COUNT)
	{
		free_ltexture(arena.figures[i]);
		free_ltexture(arena.bold_figures[i]);
	}
	i = -1;
	while (++i < TOTAL_SPRITES)
		free_ltexture(arena.start_btn_sprites[i]);
	i = -1;
	while (++i < TOTAL_START_BUTTONS)
	{
		free_ltexture(arena.start_btns[i]->button_txt);
		free(arena.start_btns[i]);
	}
	i = -1;
	while (++i < FULL_SPRITES)
		free_ltexture(arena.full_sprites[i]);

	free_ltexture(arena.hail);
	free_ltexture(arena.processes_txt);
	free_ltexture(arena.delta_txt);
	free_ltexture(arena.nbr_txt);
	free_ltexture(arena.checks_txt);
	free_ltexture(arena.cycles_txt);
	free_ltexture(arena.cycles_to_die_txt);
	free_ltexture(arena.speed_txt);
	free_ltexture(arena.duration_txt);
	free_ltexture(arena.infopanel_title);
	Mix_FreeChunk(arena.exit_sound);
	Mix_FreeChunk(arena.btn_move);
	Mix_FreeChunk(arena.btn_press);
	Mix_FreeMusic(arena.theme);
	SDL_DestroyRenderer(arena.renderer);
	SDL_DestroyWindow(arena.window);
	Mix_Quit();
	TTF_Quit();
    IMG_Quit();
    SDL_Quit();
	system("leaks corewar > leaks");
}

int					visualizer_main(void)
{
	t_arena			arena;

	init(&arena);
	events_handler(&arena);
	close_all(arena);
	return (0);
}
