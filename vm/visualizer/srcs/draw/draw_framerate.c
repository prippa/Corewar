#include "visualizer.h"

void	draw_framerate(t_arena *arena)
{
	int	ff;
	int	sf;
	int tf;
	int fps;

	fps = arena->old_fps;
	ff = fps % 10;
	fps /= 10;
	sf = fps % 10;
	fps /= 10;
	tf = fps % 10;
	SDL_Rect clip = get_rectangle(0, 0, 30, 60);
	SDL_Point p = {.x = SCREEN_WIDTH - 90, .y = SCREEN_HEIGHT - 60};
	t_rposition pos = get_render_position(0, &p, NULL, &clip);
	set_color(WHITE_COLOR, arena->bold_figures[tf]);
	set_color(WHITE_COLOR, arena->bold_figures[ff]);
	set_color(WHITE_COLOR, arena->bold_figures[sf]);
	render(&pos, arena->bold_figures[tf], arena->renderer, SDL_FLIP_NONE);
	pos.left_corner->x += 30;
	render(&pos, arena->bold_figures[sf], arena->renderer, SDL_FLIP_NONE);
	pos.left_corner->x += 30;
	render(&pos, arena->bold_figures[ff], arena->renderer, SDL_FLIP_NONE);
}