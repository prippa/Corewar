#include "visualizer.h"

static inline void	reset_move_sprites(t_arena *arena)
{
	int				i;

	i = -1;
	while (++i < MOVE_BUTTON_TOTAL)
		arena->move_btns[i]->current_sprite = MOVE_BUTTON_MOUSE_OUT;
}

void				move_up(void *data)
{
	int				max_y;
	t_arena			*arena;

	arena = (t_arena *)data;
	reset_move_sprites(arena);
	arena->move_btns[UP_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	max_y = arena->top_left.y + (ARENA_TILE_HEIGHT * arena->zoom * ARENA_HEIGHT);
	if (max_y >= ARENA_TILE_HEIGHT * arena->zoom)
		arena->top_left.y -= ARENA_TILE_HEIGHT * arena->zoom;
}

void				move_down(void *data)
{
	t_arena			*arena;

	arena = (t_arena *)data;
	reset_move_sprites(arena);
	arena->move_btns[DOWN_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	if (arena->top_left.y < SCREEN_HEIGHT - (2 * ARENA_TILE_HEIGHT * arena->zoom))
		arena->top_left.y += ARENA_TILE_HEIGHT * arena->zoom;
}

void				move_left(void *data)
{
	int				max_x;
	t_arena			*arena;

	arena = (t_arena *)data;
	reset_move_sprites(arena);
	arena->move_btns[LEFT_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	max_x = arena->top_left.x + (ARENA_TILE_WIDTH * arena->zoom * ARENA_WIDTH);
	if (max_x >= ARENA_TILE_WIDTH * arena->zoom)
		arena->top_left.x -= ARENA_TILE_WIDTH * arena->zoom;
}

void				move_right(void *data)
{
	t_arena			*arena;

	arena = (t_arena *)data;
	reset_move_sprites(arena);
	arena->move_btns[RIGHT_MENU_BTN]->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
	if (arena->top_left.x < SCREEN_WIDTH - (2 * ARENA_TILE_WIDTH * arena->zoom))
		arena->top_left.x += ARENA_TILE_WIDTH * arena->zoom;
}