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
	for (int i = 0; i < g_cw.pd.champs_count; ++i)
	{
		arena->statuses[i].txt =
		load_from_rendered_text(get_text_info(ROBOTO_BOLD,
											(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
											get_name(g_cw.pd.champs_count - i - 1),
											BLACK_COLOR),
											arena->renderer);
	}
	return (true);
}