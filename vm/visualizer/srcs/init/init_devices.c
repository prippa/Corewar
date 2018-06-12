#include "visualizer.h"

bool	init_devices(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		force_error(SDL_GetError());
	else if (IMG_Init(IMG_INIT_PNG) == 0)
		force_error(IMG_GetError());
	else if (TTF_Init() < 0)
		force_error(TTF_GetError());
	else
		return (true);
	return (false);
}