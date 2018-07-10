#include "visualizer.h"

void	change_screen_mode(t_arena *arena)
{
	if (arena->is_fullscreen == false)
	{
		arena->full_btn->checked = true;
		arena->is_fullscreen = true;
		arena->full_btn->current_sprite = CHECK_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_FULLSCREEN_DESKTOP);
		arena->d_mode.h += 200;
		arena->d_mode.w += 200;
	}
	else
	{
		arena->full_btn->checked = false;
		arena->is_fullscreen = false;
		arena->full_btn->current_sprite = CROSS_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window, 0);
		arena->d_mode.h -= 200;
		arena->d_mode.w -= 200;
	}
	arena->arena_tile_height = ((int)(SCREEN_HEIGHT * 0.95) / 65);
	arena->arena_tile_width = ((int)(SCREEN_WIDTH * 0.8) / 65);
	arena->abs_arena_height = 65 * arena->arena_tile_height;
	arena->abs_arena_width = 65 * arena->arena_tile_width;
	arena->viewport = get_rectangle(0, 0, SCREEN_WIDTH * 0.8, arena->abs_arena_height);
	for (int i = 0; i < BUTTON_TOTAL; ++i)
	{
		arena->start_btns[i]->position.y = SCREEN_HEIGHT - BUTTON_HEIGHT;
		arena->start_btns[i]->txt_position.y = SCREEN_HEIGHT - BUTTON_HEIGHT;
	}
	arena->move_btns[UP_MENU_BTN]->position = (SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - (MOVE_BTN_WIDTH << 1)};
	arena->move_btns[RIGHT_MENU_BTN]->position = (SDL_Point){.x = MOVE_BTN_WIDTH, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH};
	arena->move_btns[DOWN_MENU_BTN]->position = (SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - MOVE_BTN_WIDTH};
	arena->move_btns[LEFT_MENU_BTN]->position = (SDL_Point){.x = 0, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH};
	for (int i = 0; i < MOVE_BUTTON_TOTAL; ++i)
	{
		arena->move_btns[i]->btn_pos.clip->w = MOVE_BTN_WIDTH;
		arena->move_btns[i]->btn_pos.clip->h = MOVE_BTN_WIDTH;
	}
	arena->full_btn->position.y = SCREEN_HEIGHT - CHECKBOX_HEIGHT;
	arena->full_btn->txt_position.y = SCREEN_HEIGHT - CHECKBOX_HEIGHT;
	arena->full_btn->txt_position.x = arena->full_btn->position.x + CHECKBOX_WIDTH + 10;
}