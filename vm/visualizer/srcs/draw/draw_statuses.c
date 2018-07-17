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
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
		render(name_pos, arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
		name_pos.left_corner.x += name_pos.width;
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].text_len / (float)64);
		render(name_pos, arena->statuses[i].first_row, arena->renderer, SDL_FLIP_NONE);
		name_pos.left_corner.x += name_pos.width;
		name_pos.width = INFOPANEL_WIDTH * (arena->statuses[i].top_wrap_length / (float)64);
		render(name_pos, arena->statuses[i].top_wrapper, arena->renderer, SDL_FLIP_NONE);
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