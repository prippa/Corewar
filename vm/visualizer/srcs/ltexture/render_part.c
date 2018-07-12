#include "visualizer.h"

void	render_part(SDL_Rect clip,
					SDL_Rect target,
					SDL_Point top_left,
					SDL_Texture *texture,
					SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, &clip, &target);
}

