#include "visualizer.h"

bool	init_music(t_arena *arena)
{
	if (!(arena->theme = Mix_LoadMUS(MAIN_THEME)))
		return (false);
	if (!(arena->btn_move = Mix_LoadWAV(BUTTON_MOVE_SOUND)))
		return (false);
	if (!(arena->btn_press = Mix_LoadWAV(BUTTON_PRESS_SOUND)))
		return (false);
	if (!(arena->exit_sound = Mix_LoadWAV(EXIT_SOUND)))
		return (false);
	return (true);
}