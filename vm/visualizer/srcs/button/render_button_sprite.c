#include "visualizer.h"

t_button		*g_start_btns[TOTAL_BUTTONS];

void				render_button_sprite(t_button *btn,
										t_arena *arena)
{
	t_rposition	btn_pos;
	t_rposition txt_pos;
	SDL_Rect	clip;

	clip = get_rectangle(btn->position.x,
							btn->position.y,
							btn->width,
							btn->height);
	btn_pos = get_render_position(0, &(btn->position), NULL, &clip);
	render(&btn_pos, arena->start_btn_sprites[btn->current_sprite],
			arena->renderer, SDL_FLIP_NONE);
	if (btn->button_txt)
	{
		clip.w /= 2;
		clip.x += (btn->width >> 2);
		txt_pos = get_render_position(0, &(btn->txt_position), NULL, &clip);
		render(&txt_pos, btn->button_txt,
				arena->renderer, SDL_FLIP_NONE);
		
	}
}
