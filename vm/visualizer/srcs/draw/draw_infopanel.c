#include "visualizer.h"

void	draw_infopanel(t_arena *arena)
{
	SDL_Point		bp;

	bp.x = SCREEN_WIDTH - (BUTTON_WIDTH << 1) - (SCREEN_WIDTH >> 5);
	bp.y = BUTTON_HEIGHT << 1;
	SDL_Rect clip = get_rectangle(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT * 12);
	t_rposition pos = get_render_position(0, &bp, NULL, &clip);
	render(&pos, arena->infopanel, arena->renderer, SDL_FLIP_NONE);
}