#include "visualizer.h"

static inline int	get_live_sum(void)
{
	int						sum;
	t_champ					*tmp;
	
	tmp = g_cw.pd.champs;
	sum = 0;
	while (tmp)
	{
		sum += tmp->lives_number;
		tmp = tmp->next;
	}
	return ((sum == 0) ? 1 : sum);
}

static inline int	get_live(int index)
{
	int						depth;
	t_champ					*tmp;
	
	tmp = g_cw.pd.champs;
	depth = g_cw.pd.champs_count - index - 1;
	while (depth--)
	{
		tmp = tmp->next;
	}
	return (tmp->lives_number);
}

void	draw_statuses(t_arena *arena)
{
	int top_left_x = arena->abs_arena_width;
	int top_left_y = 0.22 * SCREEN_HEIGHT;
	int area = (SCREEN_WIDTH - arena->abs_arena_width) / 4;
	SDL_Rect clip = get_rectangle(0, 0, 3 * area / 4, 0.05 * SCREEN_HEIGHT);
	int sum = get_live_sum();
	for (int i = 0; i < g_cw.pd.champs_count; ++i)
	{
		SDL_Point rp = {.x = top_left_x + (area / 8), .y = top_left_y};
		t_rposition pos = get_render_position(0, &rp, NULL, &clip);
		render(&pos, arena->statuses[i].txt, arena->renderer, SDL_FLIP_NONE);
		SDL_SetRenderDrawColor(arena->renderer, 100, 0, 0, 0xff);
		SDL_Rect r = get_rectangle(top_left_x + (area / 4), top_left_y + 0.05 * SCREEN_HEIGHT, area >> 1, 0.4 * SCREEN_HEIGHT);
		SDL_RenderFillRect(arena->renderer, &r);
		int live = get_live(i);
		float p = live / (float)sum;
		float h = r.h * p;
		SDL_Rect in_rect = get_rectangle(r.x, r.y, r.w, (int)h);
		SDL_Color c;
		if (i == RED_CHAMP)
		{
			c = RED_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0xff, 0, 0, 0xff);
		}
		else if (i == BLUE_CHAMP)
		{
			c = BLUE_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0xff, 0xff);
		}
		else if (i == GREEN_CHAMP)
		{
			c = GREEN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0, 0xff);
		}
		else
		{
			c = CYAN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0xff, 0xff);
		}
		SDL_RenderFillRect(arena->renderer, &in_rect);
		SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0, 0xff);
		SDL_RenderDrawRect(arena->renderer, &r);
		
		sdl_putnbr(live, get_rectangle(r.x - (area >> 2), r.y - BUTTON_HEIGHT * 3, r.w << 1, BUTTON_HEIGHT * 2), arena, c);
		top_left_x += area;
	}
}