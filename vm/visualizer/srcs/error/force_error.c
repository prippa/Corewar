#include "visualizer.h"

void	force_error(const char *error)
{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
							"Error!",
							error,
							NULL);
}