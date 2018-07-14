#include "visualizer.h"

static inline void	create_button_text(t_button *btn,
										SDL_Renderer *renderer,
										const char *text)
{
	SDL_Point		top_left;
	SDL_Point		params;

	if (text != NULL)
	{
		btn->button_txt = load_from_rendered_text(get_text_info(FUTURICA, btn->btn_pos.width, text, BLACK_COLOR), renderer);
		top_left.x = btn->btn_pos.left_corner.x + (btn->btn_pos.width >> 3);
		top_left.y = btn->btn_pos.left_corner.y;
		params.x = btn->btn_pos.width - (btn->btn_pos.width >> 2);
		params.y = btn->btn_pos.height;
		btn->txt_pos = get_render_position(btn->btn_pos.angle, top_left, top_left, params);
	}
	else
		btn->button_txt = NULL;
}

t_button		*create_button(t_rposition btn_position,
								const char *text,
								SDL_Renderer *renderer,
								void *sprites)
{
	t_button	*new_btn;

	new_btn = (t_button *)malloc(sizeof(t_button));
	new_btn->sprites = sprites;
	new_btn->current_sprite = 0;
	new_btn->btn_pos = btn_position;
	create_button_text(new_btn, renderer, text);
	return (new_btn);
}