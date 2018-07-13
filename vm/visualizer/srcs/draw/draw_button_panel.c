#include "visualizer.h"

void			draw_button_panel(t_arena *arena)
{
	SDL_Rect clip = get_rectangle(0, arena->abs_arena_height + 1, arena->abs_arena_width, arena->abs_arena_height - 1);
	SDL_SetRenderDrawColor(arena->renderer, 0x8b, 0, 0, 0);
	SDL_RenderFillRect(arena->renderer, &clip);
}