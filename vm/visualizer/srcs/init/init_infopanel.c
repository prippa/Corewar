#include "visualizer.h"

bool	init_infopanel(t_arena *arena)
{
	arena->infopanel = load_from_file(INFO_PANEL,
										arena->renderer,
										(SDL_Color){});
	return (true);
}