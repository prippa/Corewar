#include "visualizer.h"

void	wheel_event(t_arena *arena, int wheel_direction)
{
	int	x;
	int	y;
	
	SDL_GetMouseState(&x, &y);
	if (wheel_direction == 1)
		zoom_in(x, y, arena);
	else
		zoom_out(x, y, arena);
}