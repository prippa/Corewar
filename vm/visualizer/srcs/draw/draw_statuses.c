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
	int				depth;
	t_champ			*tmp;
	
	tmp = g_cw.pd.champs;
	while (index--)
		tmp = tmp->next;
	return (tmp->lives_number);
}

static inline int	get_max(void)
{
	int				max;
	t_champ			*tmp;
	
	tmp = g_cw.pd.champs;
	max = 0;
	while (tmp)
	{
		if (tmp->lives_number > max)
			max = tmp->lives_number;
		tmp = tmp->next;
	}
	return (max);
}

void			draw_statuses(t_arena *arena)
{
	int			i;
	t_rposition	name_pos;

	i = -1;
	name_pos = get_render_position(0, (SDL_Point){.x = INFOPANEL_TOP_LEFT.x, .y = 0.12 * SCREEN_HEIGHT}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH, .y = BUTTON_HEIGHT});
	int max = get_max();
	int sum = get_live_sum();
	while (++i < g_cw.pd.champs_count)
	{
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].wrap_length / (float)64);
		render(name_pos, arena->statuses[i].left_wrapper, arena->renderer, SDL_FLIP_NONE);
		name_pos.left_corner.x += name_pos.width;
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].text_len / (float)64);
		render(name_pos, arena->statuses[i].first_row, arena->renderer, SDL_FLIP_NONE);
		name_pos.left_corner.x += name_pos.width;
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].wrap_length / (float)64);
		render(name_pos, arena->statuses[i].right_wrapper, arena->renderer, SDL_FLIP_NONE);
		name_pos.left_corner.x = INFOPANEL_TOP_LEFT.x;
		name_pos.left_corner.y += BUTTON_HEIGHT;
		name_pos.width = INFOPANEL_WIDTH;
		render(name_pos, arena->statuses[i].second_row, arena->renderer, SDL_FLIP_NONE);
		SDL_Color c;
		int live = get_live(i);
		if (i == RED_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_RED;
			c = RED_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0xff, 0, 0, 0xff);
		}
		else if (i == BLUE_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_BLUE;
			c = BLUE_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0xff, 0xff);
		}
		else if (i == GREEN_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_GREEN;
			c = GREEN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0, 0xff);
		}
		else
		{
			if (max == live && live)
				arena->leader_color = LIGHT_CYAN;
			c = CYAN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0xff, 0xff);
		}
		sdl_putnbr(live, get_rectangle(INFOPANEL_TOP_LEFT.x, name_pos.left_corner.y + BUTTON_HEIGHT, BUTTON_WIDTH >> 1, BUTTON_HEIGHT), arena, c, 6);
		SDL_Rect r = get_rectangle(INFOPANEL_TOP_LEFT.x + (BUTTON_WIDTH * (float)2/3), name_pos.left_corner.y + BUTTON_HEIGHT, INFOPANEL_WIDTH - (BUTTON_WIDTH), BUTTON_HEIGHT);
		draw_fillrect(r, (SDL_Color){.r = 100}, arena->renderer);
		float p = live / (float)sum;
		float w = r.w * p;
		SDL_Rect in_rect = get_rectangle(r.x, r.y, w, r.h);
		draw_fillrect(in_rect, c, arena->renderer);
		draw_outlinerect(arena, r);
		
		name_pos.left_corner.y += BUTTON_HEIGHT * 3;


	}
}
	/*
	int top_left_x = arena->abs_arena_width;
	int top_left_y = 0.25 * SCREEN_HEIGHT;
	int area = INFOPANEL_WIDTH >> 2;
	SDL_Rect clip = get_rectangle(0, 0, 3 * area / 4, 0.05 * SCREEN_HEIGHT);
	int sum = get_live_sum();
	int max = get_max();
	for (int i = 0; i < g_cw.pd.champs_count; ++i)
	{
		SDL_Point rp = {.x = top_left_x + (area / 8), .y = top_left_y};
		t_rposition pos = get_render_position(0, rp, rp, (SDL_Point){.x = clip.w, .y = clip.h});
		render(pos, arena->statuses[i].txt, arena->renderer, SDL_FLIP_NONE);
		SDL_SetRenderDrawColor(arena->renderer, 100, 0, 0, 0xff);
		SDL_Rect r = get_rectangle(top_left_x + (area / 4), top_left_y + 0.05 * SCREEN_HEIGHT, area >> 1, 0.25 * SCREEN_HEIGHT);
		SDL_RenderFillRect(arena->renderer, &r);
		int live = get_live(i);
		float p = live / (float)sum;
		float h = r.h * p;
		SDL_Rect in_rect = get_rectangle(r.x, r.y, r.w, (int)h);
		SDL_Color c;
		if (i == RED_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_RED;
			c = RED_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0xff, 0, 0, 0xff);
		}
		else if (i == BLUE_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_BLUE;
			c = BLUE_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0xff, 0xff);
		}
		else if (i == GREEN_CHAMP)
		{
			if (max == live && live)
				arena->leader_color = LIGHT_GREEN;
			c = GREEN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0, 0xff);
		}
		else
		{
			if (max == live && live)
				arena->leader_color = LIGHT_CYAN;
			c = CYAN_COLOR;
			SDL_SetRenderDrawColor(arena->renderer, 0, 0xff, 0xff, 0xff);
		}
		SDL_RenderFillRect(arena->renderer, &in_rect);
		SDL_SetRenderDrawColor(arena->renderer, 0, 0, 0, 0xff);
		SDL_RenderDrawRect(arena->renderer, &r);
		sdl_putnbr(live, get_rectangle(r.x - (area >> 2), r.y - BUTTON_HEIGHT * 3, r.w << 1, BUTTON_HEIGHT * 2), arena, c, 6);
		top_left_x += area;
	}
}*/