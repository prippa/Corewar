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

void	set_random(t_arena *arena)
{
	int	i;

	i = -1;
	bzero(arena->territory, sizeof(int) * TOTAL_CHAMP);
	while (++i < MAP_SIZE)
	{
		arena->is_bold[i] = rand() % 2;
		arena->bytes[i] = rand() % 0x100;
		int r = rand() % 6;
		if (r == 0 || r == 4 || r == 5)
		{
			arena->colors[i] = RED_COLOR;
			arena->territory[RED_CHAMP]++;
		}
		else if (r == 1)
		{
			arena->colors[i] = GREEN_COLOR;
			arena->territory[GREEN_CHAMP]++;
		}
		else if (r == 2)
		{
			arena->colors[i] = BLUE_COLOR;
			arena->territory[BLUE_CHAMP]++;
		}
		else
		{
			arena->colors[i] = CYAN_COLOR;
			arena->territory[CYAN_CHAMP]++;
		}
		//arena->colors[i] = (SDL_Color){.r = 0, .g = 0, .b = 0};
	}
	/*printf("%d %d %d %d\n", arena->territory[RED_CHAMP],
		arena->territory[GREEN_CHAMP],
		arena->territory[BLUE_CHAMP],
		arena->territory[CYAN_CHAMP]);*/
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
