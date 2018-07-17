#include "visualizer.h"

static inline void	draw_cycles_count_duration(t_arena *arena)
{
	t_rposition		txt_pos;
	
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.6, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), WHITE_COLOR, arena->renderer);
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.65, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), BLACK_COLOR, arena->renderer);
	sdl_putnbr(arena->cycles_per_tact, get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.65, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
	txt_pos = get_render_position(0, (SDL_Point){.x = arena->viewport.w, .y = SCREEN_HEIGHT * 0.6}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH / 3, .y = BUTTON_HEIGHT << 1});
	render(txt_pos, arena->speed_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7; 
	render(txt_pos, arena->duration_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(arena->tact_duration / 1000, get_rectangle(txt_pos.left_corner.x, SCREEN_HEIGHT * 0.65, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
}

static inline void	draw_cycles(t_arena *arena)
{
	t_rposition		txt_pos;

	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.7, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), WHITE_COLOR, arena->renderer);
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.75, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), BLACK_COLOR, arena->renderer);
	sdl_putnbr(g_cw.cycle, get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.75, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
	txt_pos = get_render_position(0, (SDL_Point){.x = arena->viewport.w, .y = SCREEN_HEIGHT * 0.7}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH / 3, .y = BUTTON_HEIGHT << 1});
	render(txt_pos, arena->cycles_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7; 
	render(txt_pos, arena->cycles_to_die_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(g_cw.cycle_to_die, get_rectangle(txt_pos.left_corner.x, SCREEN_HEIGHT * 0.75, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
}

static inline void	draw_constants(t_arena *arena)
{
	t_rposition		txt_pos;
	
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.8, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), WHITE_COLOR, arena->renderer);
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.85, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), BLACK_COLOR, arena->renderer);
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.9, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), WHITE_COLOR, arena->renderer);
	draw_fillrect(get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.95, INFOPANEL_WIDTH, BUTTON_HEIGHT << 1), BLACK_COLOR, arena->renderer);
	sdl_putnbr(NBR_LIVE, get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.85, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
	txt_pos = get_render_position(0, (SDL_Point){.x = arena->viewport.w, .y = SCREEN_HEIGHT * 0.8}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH / 3, .y = BUTTON_HEIGHT << 1});
	render(txt_pos, arena->nbr_txt, arena->renderer, SDL_FLIP_NONE);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7; 
	render(txt_pos, arena->checks_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(MAX_CHECKS, get_rectangle(txt_pos.left_corner.x, SCREEN_HEIGHT * 0.85, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
	txt_pos = get_render_position(0, (SDL_Point){.x = arena->viewport.w, .y = SCREEN_HEIGHT * 0.9}, (SDL_Point){0}, (SDL_Point){.x = INFOPANEL_WIDTH / 3, .y = BUTTON_HEIGHT << 1});
	render(txt_pos, arena->delta_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(CYCLE_DELTA, get_rectangle(arena->viewport.w, SCREEN_HEIGHT * 0.95, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
	txt_pos.left_corner.x += INFOPANEL_WIDTH / 3 + BUTTON_HEIGHT;
	txt_pos.width *= 1.7; 
	render(txt_pos, arena->processes_txt, arena->renderer, SDL_FLIP_NONE);
	sdl_putnbr(g_cw.proc_counter, get_rectangle(txt_pos.left_corner.x, SCREEN_HEIGHT * 0.95, BUTTON_WIDTH, BUTTON_HEIGHT << 1), arena, WHITE_COLOR, 4);
}

void	draw_infopanel(t_arena *arena)
{
	draw_fillrect(INFOPANEL_RECTANGLE, arena->leader_color, arena->renderer);
	render(get_render_position(0, INFOPANEL_TOP_LEFT, INFOPANEL_TOP_LEFT, INFOPANEL_LABEL_PARAMS),
			arena->infopanel_title, arena->renderer, SDL_FLIP_NONE);
	draw_cycles_count_duration(arena);
	draw_cycles(arena);
	draw_constants(arena);
}