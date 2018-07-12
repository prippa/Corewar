#include "visualizer.h"

bool	init_statuses(t_arena *arena)
{
	arena->statuses[RED_CHAMP].txt =
		load_from_rendered_text(get_text_info(FUTURICA_ITALIC,
											ARENA_TILE_WIDTH * MAX_ZOOM,
											"Red",
											BLACK_COLOR),
											arena->renderer);
	arena->statuses[BLUE_CHAMP].txt =
		load_from_rendered_text(get_text_info(FUTURICA_ITALIC,
											ARENA_TILE_WIDTH * MAX_ZOOM,
											"Blue",
											BLACK_COLOR),
											arena->renderer);
	arena->statuses[GREEN_CHAMP].txt =
		load_from_rendered_text(get_text_info(FUTURICA_ITALIC,
											ARENA_TILE_WIDTH * MAX_ZOOM,
											"Green",
											BLACK_COLOR),
											arena->renderer);
	arena->statuses[CYAN_CHAMP].txt =
		load_from_rendered_text(get_text_info(FUTURICA_ITALIC,
											ARENA_TILE_WIDTH * MAX_ZOOM,
											"Cyan",
											BLACK_COLOR),
											arena->renderer);
}