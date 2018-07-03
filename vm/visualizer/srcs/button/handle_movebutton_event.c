#include "visualizer.h"

static inline bool	is_mouse_event_happened(int type)
{
	return (type == SDL_MOUSEMOTION ||
			type == SDL_MOUSEBUTTONDOWN ||
			type == SDL_MOUSEBUTTONUP);
}

static inline bool	is_mouse_outside_movebtn(int x, int y,
											SDL_Point position)
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

	if (is_mouse_event_happened(e->type))
	{
		SDL_GetMouseState(&x, &y);
		if (is_mouse_outside_movebtn(x, y, btn->position))
			btn->current_sprite = MOVE_BUTTON_MOUSE_OUT;
		else if (e->type == SDL_MOUSEMOTION)
			btn->current_sprite = MOVE_BUTTON_MOUSE_OVER_MOTION;
		else if (e->type == SDL_MOUSEBUTTONDOWN)
			btn->current_sprite = MOVE_BUTTON_MOUSE_DOWN;
		else if (e->type == SDL_MOUSEBUTTONUP)
			btn->current_sprite = MOVE_BUTTON_MOUSE_UP;
	}
}