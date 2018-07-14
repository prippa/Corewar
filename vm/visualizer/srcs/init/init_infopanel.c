#include "visualizer.h"

bool		init_infopanel(t_arena *arena)
{
	t_text	info;

	info = get_text_info(WESTERN_SWING, 0.15 * SCREEN_WIDTH, "COREWAR", BLACK_COLOR);
	if (!(arena->infopanel_title = load_from_rendered_text(info, arena->renderer)))
		return (false);
	arena->speed_txt = load_from_rendered_text(get_text_info(ROBOTO_BLACK,
											(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
											SPEED_TXT,
											BLACK_COLOR),
											arena->renderer);
	arena->duration_txt = load_from_rendered_text(get_text_info(ROBOTO_BLACK,
											(ARENA_TILE_WIDTH * MAX_ZOOM << 1),
											DURATION_TXT,
											BLACK_COLOR),
											arena->renderer);									
	return (true);
}