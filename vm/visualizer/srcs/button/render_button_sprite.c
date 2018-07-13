#include "visualizer.h"

void				render_button_sprite(t_button *btn, t_arena *arena)
{
	if (btn->button_txt)
	{
		render(btn->btn_pos, ((t_ltexture **)(btn->sprites))[btn->current_sprite],
			arena->renderer, SDL_FLIP_NONE);
		render(btn->txt_pos, btn->button_txt, arena->renderer, SDL_FLIP_NONE);
		
	}
	else
	{
		render(btn->btn_pos, arena->move_btn_sprites[btn->current_sprite],
			arena->renderer, SDL_FLIP_NONE);
	}
}
