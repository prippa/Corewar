#include "visualizer.h"

bool	init_music(t_arena *arena)
{
	arena->theme = Mix_LoadMUS(MAIN_THEME);
	return (true);
}