#include "visualizer.h"

void			draw_button_panel(t_arena *arena)
{
	SDL_Rect	clip;
	
	clip = get_rectangle(0, arena->abs_arena_height, arena->abs_arena_width, arena->abs_arena_height);
	draw_fillrect(clip, arena->leader_color, arena->renderer);
}