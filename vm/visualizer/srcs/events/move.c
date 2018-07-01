#include "visualizer.h"

void	move_up(t_arena *arena)
{
	int	max_y;

	arena->move_btns[UP_MENU_BTN]->current_sprite =
		MOVE_BUTTON_MOUSE_DOWN;
	max_y = arena->top_left.y +
			(ARENA_TILE_HEIGHT *
			arena->zoom *
			ARENA_HEIGHT);
	if (max_y >= ARENA_TILE_HEIGHT * arena->zoom)
		arena->top_left.y -=
			ARENA_TILE_HEIGHT * arena->zoom;
}

void	move_down(t_arena *arena)
{
	if (arena->top_left.y <
		SCREEN_HEIGHT - (2 * ARENA_TILE_HEIGHT * arena->zoom))
	{
		arena->top_left.y +=
			ARENA_TILE_HEIGHT * arena->zoom;
	}
}