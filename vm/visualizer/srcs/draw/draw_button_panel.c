#include "visualizer.h"

void			draw_button_panel(t_arena *arena)
{
	SDL_Point	bp;

	bp.x = 0;
	bp.y = arena->abs_arena_height + 1;
	SDL_Rect clip = get_rectangle(0, 0, arena->abs_arena_width, arena->abs_arena_height - 1);
	t_rposition pos = get_render_position(0, &bp, NULL, &clip);
	render(&pos, arena->infopanel, arena->renderer, SDL_FLIP_NONE);
}