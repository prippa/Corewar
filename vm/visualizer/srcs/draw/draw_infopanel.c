#include "visualizer.h"

void	draw_infopanel(t_arena *arena)
{
	SDL_Point		bp;

	bp.x = arena->abs_arena_width + 1;
	bp.y = 0;
	SDL_Rect clip = get_rectangle(0, 0, SCREEN_WIDTH - arena->abs_arena_width - 1, SCREEN_HEIGHT);
	t_rposition pos = get_render_position(0, &bp, NULL, &clip);
	render(&pos, arena->infopanel, arena->renderer, SDL_FLIP_NONE);
	clip = get_rectangle(bp.x, bp.y, SCREEN_WIDTH - arena->abs_arena_width - 1, 0.1 * SCREEN_WIDTH);
	pos = get_render_position(0, &bp, NULL, &clip);
	SDL_RenderFillRect(arena->renderer, &clip);
	render(&pos, arena->infopanel_title, arena->renderer, SDL_FLIP_NONE);
}