#include "visualizer.h"

void		set_viewport(SDL_Renderer *renderer,
							SDL_Rect *viewport)
{
	SDL_RenderSetViewport(renderer, viewport);
}
