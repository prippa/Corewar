#include "visualizer.h"

void		reset(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	arena->zoom = 1.0;
	arena->top_left.x = 0;
	arena->top_left.y = 0;
}