#include "visualizer.h"

void		start(void *arena)
{
	t_arena	*a;

	a = (t_arena *)arena;
	a->pause = false;
}

void		stop(void *arena)
{
	t_arena	*a;

	a = (t_arena *)arena;
	a->pause = true;
}