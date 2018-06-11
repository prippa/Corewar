#include "visualizer.h"
# define MAX(x, y) ((x > y) ? x : y)
void		create_figures(t_arena *arena)
{
	int		font_weight;
	int		i;
	char	buf[2];

	buf[1] = 0;
	font_weight = MAX(ARENA_TILE_HEIGHT, ARENA_TILE_WIDTH) *
						MAX_ZOOM;
	i = -1;
	while (++i < 0x10)
	{
		if (i < 0xa)
			buf[0] = i + 48;
		else
			buf[0] = 'f' - (0xf - i);
		arena->figures[i] =
			load_from_rendered_text(get_text_info(
									FUTURICA,
									font_weight,
									buf,
									(SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff, .a = 0xff}),
									arena->renderer);
	}
}