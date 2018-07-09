#include "visualizer.h"

bool		init_infopanel(t_arena *arena)
{
	t_text	info;

	if (!(arena->infopanel = load_from_file(INFO_PANEL, arena->renderer, BLACK_COLOR)))
		return (false);
	info = get_text_info(WESTERN_SWING, 0.15 * SCREEN_WIDTH, "COREWAR", RED_COLOR);
	if (!(arena->infopanel_title = load_from_rendered_text(info, arena->renderer)))
		return (false);
	return (true);
}