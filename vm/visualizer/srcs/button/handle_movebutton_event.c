#include "visualizer.h"

static inline bool	is_mouse_event_happened(int type)
{
	return (type == SDL_MOUSEMOTION ||
			type == SDL_MOUSEBUTTONDOWN ||
			type == SDL_MOUSEBUTTONUP);
}

static inline bool	is_mouse_outside_movebtn(int x, int y,
											SDL_Point position, t_arena *arena)
{
	return (x < position.x ||
			x > position.x + MOVE_BTN_WIDTH ||
			y < position.y ||
			y > position.y + MOVE_BTN_WIDTH);
}

void				handle_movebutton_event(SDL_Event *e,
										t_button *btn,
										t_arena *arena,
										t_movemenu id)
{
	int				x;
	int				y;
	int				state;

	if (e == NULL)
	{
		state = SDL_GetMouseState(&x, &y);
		if (is_mouse_outside_movebtn(x, y, btn->position, arena))
			btn->current_sprite = MOVE_BUTTON_MOUSE_OUT;
		else if (state)
		{
			btn->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
			if (id == UP_MENU_BTN)
				move_up(arena);
			else if (id == DOWN_MENU_BTN)
				move_down(arena);
			else if (id == LEFT_MENU_BTN)
				move_left(arena);
			else if (id == RIGHT_MENU_BTN)
				move_right(arena);
		}
	}
	else if (is_mouse_event_happened(e->type))
	{
		SDL_GetMouseState(&x, &y);
		if (is_mouse_outside_movebtn(x, y, btn->position, arena))
			btn->current_sprite = MOVE_BUTTON_MOUSE_OUT;
		else if (e->type == SDL_MOUSEMOTION)
		{
			if (btn->current_sprite != BUTTON_MOUSE_OVER_MOTION)
				Mix_PlayChannel(-1, arena->btn_move, 0);
			btn->current_sprite = MOVE_BUTTON_MOUSE_OVER_MOTION;
		}
		else if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			Mix_PlayChannel(-1, arena->btn_press, 0);
			btn->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
		}
		else if (e->type == SDL_MOUSEBUTTONUP)
			btn->current_sprite = MOVE_BUTTON_MOUSE_UP;
	}
}