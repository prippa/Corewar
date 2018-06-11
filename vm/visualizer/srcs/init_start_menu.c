#include "visualizer.h"

t_ltexture		*g_start_btn_sprites[TOTAL_SPRITES];
t_button		*g_start_btns[TOTAL_BUTTONS];
t_ltexture		*g_full_sprites[TOTAL_FULL_SPRITES];
t_checkbox		*g_full_btn;
t_ltexture		*g_tile_block;
t_ltexture		*g_text_block;
t_button		*g_move_btns[TOTAL_MOVE_BUTTONS];
t_ltexture		*g_move_btn_sprites[TOTAL_MOVE_SPRITES];

bool			init_start_menu(SDL_Renderer *renderer)
{
	bool		success;

	success = true;
	bzero(g_start_btn_sprites, sizeof(g_start_btn_sprites));
	bzero(g_full_sprites, sizeof(g_full_sprites));
	bzero(g_move_btn_sprites, sizeof(g_move_btn_sprites));
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_OUT] = load_from_file("buttons/arrow.png",
																renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION] = load_from_file("buttons/arrow.png",
																renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.g=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION]);
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN] = load_from_file("buttons/arrow.png",
																renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.r=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN]);
	g_move_btn_sprites[MOVE_BUTTON_MOUSE_UP] = load_from_file("buttons/arrow.png",
																renderer,
																(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff});
	set_color((SDL_Color){.r=0xff,.b=0xff},
				g_move_btn_sprites[MOVE_BUTTON_MOUSE_UP]);
	if (!(g_text_block = load_from_rendered_text(get_text_info(KENVECTOR_THIN,
															ARENA_TILE_HEIGHT * MAX_ZOOM,
															"2a",
															(SDL_Color){.r = 0xff, .g = 0xff, .b = 0, .a = 0}),
															renderer)))
	{
		success = false;
	}
	if (!(g_tile_block =
			load_from_file("tileblock.jpg",
							renderer,
							(SDL_Color){.r = 0x0, .g = 0x0, .b = 0x0, .a = 0xff})))
		success = false;
	if (!(g_full_sprites[CHECK_MOUSE_OUT] =
			load_from_file("buttons/red_check.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CHECK_MOUSE_IN] =
			load_from_file("buttons/red_check.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CROSS_MOUSE_OUT] =
			load_from_file("buttons/red_cross.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_full_sprites[CROSS_MOUSE_IN] =
			load_from_file("buttons/red_cross.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})))
	{
		success = false;
	}
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, g_full_sprites[CHECK_MOUSE_IN]);
	set_color((SDL_Color){.r = 0, .g = 0xff, .b = 0}, g_full_sprites[CROSS_MOUSE_IN]);
	if (!(g_start_btn_sprites[BUTTON_MOUSE_OUT] =
			load_from_file("buttons/red_out.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_start_btn_sprites[BUTTON_MOUSE_OVER_MOTION] =
			load_from_file("buttons/red_on.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_start_btn_sprites[BUTTON_MOUSE_DOWN] =
			load_from_file("buttons/red_down.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})) ||
		!(g_start_btn_sprites[BUTTON_MOUSE_UP] =
			load_from_file("buttons/red_up.png",
							renderer,
							(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})))
		success = false;
	int wd = SCREEN_WIDTH - BUTTON_WIDTH - (SCREEN_WIDTH / 15);
	if (!(g_start_btns[START_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 150},
							"START", renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(g_start_btns[STOP_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 250},
							"STOP", renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(g_start_btns[INFO_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 350},
							"INFO", renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})) ||
		!(g_start_btns[EXIT_MENU_BTN] =
			create_button((SDL_Point){.x = wd, .y = 450},
							"EXIT", renderer,
							(SDL_Point){.x=BUTTON_WIDTH, .y=BUTTON_HEIGHT})))
		success = false;
	if (!(g_full_btn = create_checkbox((SDL_Point){.x = wd, .y = 50},
									"FULLSCREEN",
									renderer)))
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