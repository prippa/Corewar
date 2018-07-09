#include "visualizer.h"

void				render_button_sprite(t_button *btn,
										t_arena *arena)
{
	t_rposition	btn_pos = btn->btn_pos;
	t_rposition txt_pos = btn->txt_pos;
	SDL_Rect	clip = btn->clip;

	if (btn->button_txt)
	{
		render(&btn_pos,
			((t_ltexture **)(btn->sprites))[btn->current_sprite],
			arena->renderer,
			SDL_FLIP_NONE);
		clip.w >>= 1;
		clip.x += (btn->width >> 2);
		txt_pos = get_render_position(0, &(btn->txt_position), NULL, &clip);
		//txt_pos = btn->txt_pos;
		render(&txt_pos, btn->button_txt,
				arena->renderer, SDL_FLIP_NONE);
		
	}
	else
	{
		render(&btn_pos, arena->move_btn_sprites[btn->current_sprite],
			arena->renderer, SDL_FLIP_NONE);
	}
}
