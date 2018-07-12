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
	sdl_putnbr(arena->speed, get_rectangle(arena->viewport.w, arena->viewport.h - BUTTON_HEIGHT, BUTTON_HEIGHT, BUTTON_WIDTH), arena, MAGENTA_COLOR);
	bp.x = arena->viewport.w + BUTTON_HEIGHT;
	bp.y = arena->viewport.h - BUTTON_HEIGHT;
	clip = get_rectangle(0, 0, BUTTON_WIDTH << 1, BUTTON_WIDTH);
	t_rposition txt_pos = get_render_position(0, &bp, NULL, &clip);
	set_color(WHITE_COLOR, arena->speed_txt);
	render(&txt_pos, arena->speed_txt, arena->renderer, SDL_FLIP_NONE);
}