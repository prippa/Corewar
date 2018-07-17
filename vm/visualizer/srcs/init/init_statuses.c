#include "visualizer.h"

//g_cw.pd.champs->next->head.prog_name

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

bool						init_statuses(t_arena *arena)
{
	char					top[64];

	for (int i = 0; i < g_cw.pd.champs_count; ++i)
	{
		SDL_Color c;
		if (i == RED_CHAMP)
			c = RED_COLOR;
		else if (i == BLUE_CHAMP)
			c = BLUE_COLOR;
		else if (i == GREEN_CHAMP)
			c = GREEN_COLOR;
		else 
			c = CYAN_COLOR;
		ft_bzero(top, 64);
		arena->statuses[i].text = ft_strdup(get_name(i));
		arena->statuses[i].text_len = ft_strlen(arena->statuses[i].text);
		if (arena->statuses[i].text_len > 60)
		{
			arena->statuses[i].text[59] = '*';
			arena->statuses[i].text[60] = '\0';
			arena->statuses[i].text_len = ft_strlen(arena->statuses[i].text);
		}
		if (arena->statuses[i].text_len <= 64)
		{
			int wrap_length = (64 - arena->statuses[i].text_len) / 2;
			arena->statuses[i].top_wrap_length = wrap_length;
			for (int j = 0; j < wrap_length; j++)
				top[j] = 32;
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
			free(arena->statuses[i].text);
		}
	}
	return (true);
}