/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_statuses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:48:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/21 15:48:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline const char	*get_name(int index)
{
	int						i;
	t_champ					*tmp;

	tmp = g_cw.pd.champs;
	i = -1;
	while (++i < index)
		tmp = tmp->next;
	return (tmp->head.prog_name);
}

SDL_Color					get_color(int i)
{
	SDL_Color				c;

	if (i == RED_CHAMP)
		c = RED_COLOR;
	else if (i == BLUE_CHAMP)
		c = BLUE_COLOR;
	else if (i == GREEN_CHAMP)
		c = GREEN_COLOR;
	else
		c = CYAN_COLOR;
	return (c);
}

static inline void			init_one_status(t_arena *arena,
								SDL_Color c,
								char *top,
								int i)
{
	arena->statuses[i].top_wrapper = load_from_rendered_text(
		get_text_info(ROBOTO_BOLD, 10, top, BLACK_COLOR), arena->renderer);
	arena->statuses[i].first_row =
		load_from_rendered_text(get_text_info(ROBOTO_BOLD,
		(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
		arena->statuses[i].text,
		c),
		arena->renderer);
	arena->statuses[i].second_row =
		load_from_rendered_text(get_text_info(ROBOTO_BOLD,
		(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
		"****************************************************************",
		BLACK_COLOR),
		arena->renderer);
}

void						check_over(t_arena *arena,
							int i)
{
	if (arena->statuses[i].text_len > 60)
	{
		arena->statuses[i].text[59] = '*';
		arena->statuses[i].text[60] = '\0';
		arena->statuses[i].text_len = ft_strlen(arena->statuses[i].text);
	}
}

bool						init_statuses(t_arena *arena)
{
	char					top[64];
	SDL_Color				c;
	int						wrap_length;
	int						i;
	int						j;

	i = -1;
	while (++i < g_cw.pd.champs_count)
	{
		c = get_color(i);
		ft_bzero(top, 64);
		arena->statuses[i].text = ft_strdup(get_name(i));
		arena->statuses[i].text_len = ft_strlen(arena->statuses[i].text);
		check_over(arena, i);
		wrap_length = (64 - arena->statuses[i].text_len) / 2;
		arena->statuses[i].top_wrap_length = wrap_length;
		j = -1;
		while (++j < wrap_length)
			top[j] = 32;
		init_one_status(arena, c, top, i);
		free(arena->statuses[i].text);
	}
	return (true);
}
