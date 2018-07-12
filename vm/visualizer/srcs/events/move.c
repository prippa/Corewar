#include "visualizer.h"

void	move_up(t_arena *arena)
{
	int	max_y;
	int	i;

	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		arena->move_btns[i]->current_sprite = MOVE_BUTTON_MOUSE_OUT;
	arena->move_btns[UP_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	max_y = arena->top_left.y + (ARENA_TILE_HEIGHT * arena->zoom * ARENA_HEIGHT);
	if (max_y >= ARENA_TILE_HEIGHT * arena->zoom)
		arena->top_left.y -= ARENA_TILE_HEIGHT * arena->zoom;
}

void	move_down(t_arena *arena)
{
	int	i;

	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		arena->move_btns[i]->current_sprite = MOVE_BUTTON_MOUSE_OUT;
	arena->move_btns[DOWN_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	if (arena->top_left.y < SCREEN_HEIGHT - (2 * ARENA_TILE_HEIGHT * arena->zoom))
		arena->top_left.y += ARENA_TILE_HEIGHT * arena->zoom;
}

void	move_left(t_arena *arena)
{
	int	i;
	int	max_x;

	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		arena->move_btns[i]->current_sprite = MOVE_BUTTON_MOUSE_OUT;
	arena->move_btns[LEFT_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	max_x = arena->top_left.x + (ARENA_TILE_WIDTH * arena->zoom * ARENA_WIDTH);
	if (max_x >= ARENA_TILE_WIDTH * arena->zoom)
		arena->top_left.x -= ARENA_TILE_WIDTH * arena->zoom;
}

void	move_right(t_arena *arena)
{
	int	i;

	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		arena->move_btns[i]->current_sprite = MOVE_BUTTON_MOUSE_OUT;
	arena->move_btns[RIGHT_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	if (arena->top_left.x < SCREEN_WIDTH - (2 * ARENA_TILE_WIDTH * arena->zoom))
		arena->top_left.x += ARENA_TILE_WIDTH * arena->zoom;
}