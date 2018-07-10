#include "visualizer.h"

void	draw_statuses(t_arena *arena)
{
	int top_left_x = arena->abs_arena_width;
	int top_left_y = 0.2 * SCREEN_HEIGHT;
	int area = (SCREEN_WIDTH - arena->abs_arena_width) >> 2;
	SDL_Rect clip = get_rectangle(0, 0, area >> 1, 0.05 * SCREEN_HEIGHT);
	for (int i = 0; i < TOTAL_CHAMP; ++i)
	{
		SDL_Point rp = {.x = top_left_x + (area >> 2), .y = top_left_y};
		t_rposition pos = get_render_position(0, &rp, NULL, &clip);
		render(&pos, arena->statuses[i].txt, arena->renderer, SDL_FLIP_NONE);
		SDL_SetRenderDrawColor(arena->renderer, 100, 0, 0, 0xff);
		SDL_Rect r = get_rectangle(top_left_x + (area >> 2), top_left_y + 0.05 * SCREEN_HEIGHT, area >> 1, 0.4 * SCREEN_HEIGHT);
		SDL_RenderFillRect(arena->renderer, &r);
		float p = (arena->territory[i] / (float)4096);
		float h = r.h * p;
		SDL_Rect in_rect = get_rectangle(r.x, r.y, r.w, (int)h);
		if (i == RED_CHAMP)
			SDL_SetRenderDrawColor(arena->renderer, 0xff, 0, 0, 0xff);
		else if (i == BLUE_CHAMP)
			SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0xff, 0xff);
		else if (i == GREEN_CHAMP)
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0, 0xff);
		else
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0xff, 0xff);
		SDL_RenderFillRect(arena->renderer, &in_rect);
		SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0, 0xff);
		SDL_RenderDrawRect(arena->renderer, &r);
		top_left_x += area;
	}
}