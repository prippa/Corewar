#include "visualizer.h"

void	draw_framerate(t_arena *arena)
{
	if (arena->show_fps)
		sdl_putnbr(arena->old_fps, get_rectangle(SCREEN_WIDTH - 90, SCREEN_HEIGHT - 60, 90, 60), arena, RED_COLOR, 3);
}