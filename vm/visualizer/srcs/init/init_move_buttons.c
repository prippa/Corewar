/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_move_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:43:41 by vkovsh            #+#    #+#             */
/*   Updated: 2018/06/12 17:43:44 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static inline void	init_move_btn_sprites(t_arena *arena)
{
	bzero(arena->move_btn_sprites, sizeof(arena->move_btn_sprites));
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OUT] = load_from_file(ARROW_IMG,
																arena->renderer,
																WHITE_COLOR);
	set_alpha_mode(100, arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OUT]);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_OVER_MOTION] = load_from_file(ARROW_IMG,
																arena->renderer,
																WHITE_COLOR);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN] = load_from_file(ARROW_IMG,
																arena->renderer,
																WHITE_COLOR);
	set_color((SDL_Color){.g=0xff},
				arena->move_btn_sprites[MOVE_BUTTON_MOUSE_DOWN]);
	arena->move_btn_sprites[MOVE_BUTTON_MOUSE_UP] = load_from_file(ARROW_IMG,
																arena->renderer,
																WHITE_COLOR);
}

bool	init_move_buttons(t_arena *arena)
{
	arena->move_panel = load_from_file(GREY_PANEL_IMG, arena->renderer, (SDL_Color){0});
	init_move_btn_sprites(arena);
	arena->move_btns[UP_MENU_BTN] = create_button(get_render_position(-90,
									(SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - (MOVE_BTN_WIDTH << 1)},
									(SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - (MOVE_BTN_WIDTH << 1)},
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = MOVE_BTN_WIDTH}),
									NULL, arena->renderer, arena->move_btn_sprites);
	arena->move_btns[RIGHT_MENU_BTN] = create_button(get_render_position(0,
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH},
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH},
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = MOVE_BTN_WIDTH}),
									NULL, arena->renderer, arena->move_btn_sprites);
	arena->move_btns[DOWN_MENU_BTN] = create_button(get_render_position(90,
									(SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - MOVE_BTN_WIDTH},
									(SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - MOVE_BTN_WIDTH},
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = MOVE_BTN_WIDTH}),
									NULL, arena->renderer, arena->move_btn_sprites);
	arena->move_btns[LEFT_MENU_BTN] = create_button(get_render_position(180,
									(SDL_Point){.x = 0, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH},
									(SDL_Point){.x = 0, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH},
									(SDL_Point){.x = MOVE_BTN_WIDTH, .y = MOVE_BTN_WIDTH}),
									NULL, arena->renderer, arena->move_btn_sprites);
	arena->move_btns[UP_MENU_BTN]->action = &move_up;
	arena->move_btns[RIGHT_MENU_BTN]->action = &move_right;
	arena->move_btns[DOWN_MENU_BTN]->action = &move_down;
	arena->move_btns[LEFT_MENU_BTN]->action = &move_left;
	return (true);
}