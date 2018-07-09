#include "visualizer.h"

bool	init_music(t_arena *arena)
{
	if ((arena->theme = Mix_LoadMUS(MAIN_THEME)))
		return (true);
	return (false);
}