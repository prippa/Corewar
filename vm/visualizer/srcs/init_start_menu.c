#include "visualizer.h"

t_ltexture		*g_full_sprites[TOTAL_FULL_SPRITES];
t_checkbox		*g_full_btn;
t_button		*g_move_btns[TOTAL_MOVE_BUTTONS];
t_ltexture		*g_move_btn_sprites[TOTAL_MOVE_SPRITES];

bool			init_start_menu(t_arena *arena)
{
	bool		success;

	success = true;
	bzero(arena->start_btn_sprites, sizeof(arena->start_btn_sprites));
	bzero(g_full_sprites, sizeof(g_full_sprites));
	bzero(g_move_btn_sprites, sizeof(g_move_btn_sprites));
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_OUT] = load_from_file(ARROW_IMG,
																arena->renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION] = load_from_file(ARROW_IMG,
																arena->renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.g=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION]);
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN] = load_from_file(ARROW_IMG,
																arena->renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.r=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN]);
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_UP] = load_from_file(ARROW_IMG,
																arena->renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.r=0xff,.b=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_UP]);
	if (!(g_full_sprites[CHECK_MOUSE_OUT] =
			load_from_file(CHECK_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CHECK_MOUSE_IN] =
			load_from_file(CHECK_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CROSS_MOUSE_OUT] =
			load_from_file(CROSS_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CROSS_MOUSE_IN] =
			load_from_file(CROSS_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})))
	{
		success = false;
	}
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, g_full_sprites[CHECK_MOUSE_IN]);
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, g_full_sprites[CROSS_MOUSE_IN]);
	if (!(arena->start_btn_sprites[BUTTON_MOUSE_OUT] =
			load_from_file(MENU_OUT_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_OVER_MOTION] =
			load_from_file(MENU_ON_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_DOWN] =
			load_from_file(MENU_DOWN_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(arena->start_btn_sprites[BUTTON_MOUSE_UP] =
			load_from_file(MENU_UP_IMG,
							arena->renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})))
		success = false;
	int wd = SCREEN_WIDTH - BUTTON_WIDTH - (SCREEN_WIDTH / 15);
	if (!(arena->start_btns[START_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 150},
							"START", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(arena->start_btns[STOP_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 250},
							"STOP", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(arena->start_btns[INFO_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 350},
							"INFO", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(arena->start_btns[EXIT_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 450},
							"EXIT", arena->renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})))
		success = false;
	if (!(g_full_btn = create_checkbox((SDL_Point){.x = wd, .y = 50},
									"FULLSCREEN",
									arena->renderer)))
		success = false;
	if (!success)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
								"Error!",
								SDL_GetError(),
								NULL);
	}
	return (success);
}