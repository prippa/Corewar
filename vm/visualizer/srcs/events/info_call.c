#include "visualizer.h"

void	info(void *arena)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game info", "", ((t_arena *)arena)->window);
}