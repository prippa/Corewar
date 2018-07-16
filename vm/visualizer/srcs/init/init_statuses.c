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
	char					left[64];
	char					right[64];

	for (int i = 0; i < g_cw.pd.champs_count; ++i)
	{
		ft_bzero(left, 64);
		ft_bzero(right, 64);
		arena->statuses[i].text = get_name(i);
		arena->statuses[i].text_len = ft_strlen(arena->statuses[i].text);
		if (arena->statuses[i].text_len <= 64)
		{
			int wrap_length = (64 - arena->statuses[i].text_len) / 2;
			arena->statuses[i].wrap_length = wrap_length;
			for (int j = 0; j < wrap_length; j++)
			{
				left[j] = 32;
				right[j] = 32;
			}
			arena->statuses[i].left_wrapper = load_from_rendered_text(get_text_info(ROBOTO_BOLD,
										10,
										left,
										BLACK_COLOR),
										arena->renderer);
			arena->statuses[i].right_wrapper = load_from_rendered_text(get_text_info(ROBOTO_BOLD,
										10,
										right,
										BLACK_COLOR),
										arena->renderer);
			arena->statuses[i].first_row =
				load_from_rendered_text(get_text_info(ROBOTO_BOLD,
										(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
										arena->statuses[i].text,
										BLACK_COLOR),
										arena->renderer);
			arena->statuses[i].second_row =
				load_from_rendered_text(get_text_info(ROBOTO_BOLD,
										(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
										"****************************************************************",
										BLACK_COLOR),
										arena->renderer);
		}
	}
	return (true);
}