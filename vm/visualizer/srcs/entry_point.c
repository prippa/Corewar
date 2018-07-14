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
		free_ltexture(arena.figures[i]);
	i = -1;
	while (++i < TOTAL_SPRITES)
		free_ltexture(arena.start_btn_sprites[i]);
	i = -1;
	while (++i < TOTAL_BUTTONS)
	{
		free_ltexture(arena.start_btns[i]->button_txt);
		free(arena.start_btns[i]);
	}
	i = -1;
	while (++i < FULL_SPRITES)
		free_ltexture(arena.full_sprites[i]);
	//SDL_FreeSurface(arena.screen_surface);
	SDL_DestroyRenderer(arena.renderer);
	SDL_DestroyWindow(arena.window);
	SDL_Quit();
}

int					visualizer_main(void)
{
	t_arena			arena;

	if (!init(&arena))
		printf("Error\n");
	events_handler(&arena);
	close_all(arena);
	return (0);
}
