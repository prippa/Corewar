#include "visualizer.h"

void	draw_infopanel(t_arena *arena)
{
	SDL_Point		bp;

	bp.x = arena->abs_arena_width + 1;
	bp.y = 0;
	SDL_Rect clip = get_rectangle(bp.x, bp.y, SCREEN_WIDTH - arena->abs_arena_width - 1, SCREEN_HEIGHT);
	t_rposition pos = get_render_position(0, bp, bp, (SDL_Point){.x = clip.w, .y = clip.h});
	SDL_SetRenderDrawColor(arena->renderer, 0x8b, 0, 0, 0);
	SDL_RenderFillRect(arena->renderer, &clip);
	clip = get_rectangle(bp.x, bp.y, SCREEN_WIDTH - arena->abs_arena_width - 1, 0.1 * SCREEN_WIDTH);
	pos = get_render_position(0, bp, bp, (SDL_Point){.x = clip.w, .y = clip.h});
	render(pos, arena->infopanel_title, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(arena->cycles_per_tact, get_rectangle(arena->viewport.w, arena->viewport.h - BUTTON_HEIGHT, BUTTON_HEIGHT, BUTTON_WIDTH), arena, MAGENTA_COLOR);
	bp.x = arena->viewport.w + BUTTON_HEIGHT;
	bp.y = arena->viewport.h - BUTTON_HEIGHT;
	clip = get_rectangle(0, 0, BUTTON_WIDTH << 1, BUTTON_WIDTH);
	t_rposition txt_pos = get_render_position(0, bp, bp, (SDL_Point){.x = clip.w, .y = clip.h});
	render(txt_pos, arena->speed_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(arena->tact_duration / 1000, get_rectangle(arena->viewport.w, arena->viewport.h - (BUTTON_HEIGHT << 2), BUTTON_HEIGHT, BUTTON_WIDTH), arena, MAGENTA_COLOR);
	bp.x = arena->viewport.w + BUTTON_HEIGHT;
	bp.y = arena->viewport.h - (BUTTON_HEIGHT << 2);
	clip = get_rectangle(0, 0, BUTTON_WIDTH << 1, BUTTON_WIDTH);
	txt_pos = get_render_position(0, bp, bp, (SDL_Point){.x = clip.w, .y = clip.h});
	render(txt_pos, arena->duration_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(g_cw.cycle, get_rectangle(arena->viewport.w, arena->viewport.h - (BUTTON_HEIGHT << 3), BUTTON_WIDTH, BUTTON_WIDTH), arena, MAGENTA_COLOR);
	sdl_putnbr(g_cw.cycle_to_die, get_rectangle(arena->viewport.w + BUTTON_WIDTH * 1.5, arena->viewport.h - (BUTTON_HEIGHT << 3), BUTTON_WIDTH, BUTTON_WIDTH), arena, MAGENTA_COLOR);
}