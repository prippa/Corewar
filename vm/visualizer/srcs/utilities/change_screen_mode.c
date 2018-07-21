/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_screen_mode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:23:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/07/21 16:23:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	reset_flags(t_arena *arena)
{
	if (arena->is_fullscreen == false)
	{
		arena->checkboxes[FULLSCREEN_CBX]->checked = true;
		arena->is_fullscreen = true;
		arena->checkboxes[FULLSCREEN_CBX]->current_sprite = CHECK_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window,
		SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_FULLSCREEN_DESKTOP);
		arena->d_mode.h += 200;
		arena->d_mode.w += 200;
	}
	else
	{
		arena->checkboxes[FULLSCREEN_CBX]->checked = false;
		arena->is_fullscreen = false;
		arena->checkboxes[FULLSCREEN_CBX]->current_sprite = CROSS_MOUSE_OUT;
		SDL_SetWindowFullscreen(arena->window, 0);
		arena->d_mode.h -= 200;
		arena->d_mode.w -= 200;
	}
}

void	reset_arena_const(t_arena *arena)
{
	arena->arena_tile_height = (((float)SCREEN_HEIGHT * 0.95) / 65);
	arena->arena_tile_width = (((float)SCREEN_WIDTH * 0.8) / 65);
	arena->abs_arena_height = 65 * arena->arena_tile_height;
	arena->abs_arena_width = 65 * arena->arena_tile_width;
	arena->viewport =
	get_rectangle(0,
	0,
	arena->abs_arena_width + 1,
	arena->abs_arena_height + 1);
}

void	reset_start_btns(t_arena *arena)
{
	int	i;

	i = -1;
	while (++i < TOTAL_START_BUTTONS)
	{
		arena->start_btns[i]->btn_pos.height =
		BUTTON_HEIGHT;
		arena->start_btns[i]->btn_pos.width =
		BUTTON_WIDTH;
		arena->start_btns[i]->btn_pos.left_corner.y =
		SCREEN_HEIGHT - BUTTON_HEIGHT;
		arena->start_btns[i]->txt_pos.left_corner.y =
		SCREEN_HEIGHT - BUTTON_HEIGHT;
		arena->start_btns[i]->btn_pos.left_corner.x =
		(i + 1) * BUTTON_WIDTH;
		arena->start_btns[i]->txt_pos.left_corner.x =
		arena->start_btns[i]->btn_pos.left_corner.x + (BUTTON_WIDTH >> 3);
		arena->start_btns[i]->txt_pos.width =
		BUTTON_WIDTH - (BUTTON_WIDTH >> 2);
		arena->start_btns[i]->txt_pos.height =
		BUTTON_HEIGHT;
	}
}

void	reset_move_btns(t_arena *arena)
{
	int	i;

	i = -1;
	arena->move_btns[UP_MENU_BTN]->btn_pos.left_corner =
	(SDL_Point){.x = MOVE_BTN_WIDTH >> 1,
	.y = SCREEN_HEIGHT - (MOVE_BTN_WIDTH << 1)};
	arena->move_btns[RIGHT_MENU_BTN]->btn_pos.left_corner =
	(SDL_Point){.x = MOVE_BTN_WIDTH, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH};
	arena->move_btns[DOWN_MENU_BTN]->btn_pos.left_corner =
	(SDL_Point){.x = MOVE_BTN_WIDTH >> 1, .y = SCREEN_HEIGHT - MOVE_BTN_WIDTH};
	arena->move_btns[LEFT_MENU_BTN]->btn_pos.left_corner =
	(SDL_Point){.x = 0, .y = SCREEN_HEIGHT - 1.5 * MOVE_BTN_WIDTH};
	while (++i < MOVE_BUTTON_TOTAL)
	{
		arena->move_btns[i]->btn_pos.width = MOVE_BTN_WIDTH;
		arena->move_btns[i]->btn_pos.height = MOVE_BTN_WIDTH;
	}
}

void	change_screen_mode(t_arena *arena)
{
	int	i;

	reset_flags(arena);
	reset_arena_const(arena);
	reset_start_btns(arena);
	reset_move_btns(arena);
	i = -1;
	while (++i < TOTAL_CHECKBOXES)
	{
		arena->checkboxes[i]->position.x =
		(10.5 + i) * BUTTON_WIDTH;
		arena->checkboxes[i]->position.y =
		SCREEN_HEIGHT - CHECKBOX_HEIGHT;
		arena->checkboxes[i]->txt_position.y =
		SCREEN_HEIGHT - CHECKBOX_HEIGHT;
		arena->checkboxes[i]->txt_position.x =
		arena->checkboxes[i]->position.x + CHECKBOX_WIDTH;
	}
}
