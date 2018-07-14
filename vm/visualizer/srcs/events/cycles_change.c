#include "visualizer.h"

void		increase_cycles(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	if (arena->cycles_per_tact != 1024)
		arena->cycles_per_tact <<= 1;
}

void		decrease_cycles(void *data)
{
	t_arena	*arena;

	arena = (t_arena *)data;
	if (arena->cycles_per_tact != 1)
		arena->cycles_per_tact >>= 1;
}