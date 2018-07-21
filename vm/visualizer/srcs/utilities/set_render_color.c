#include "visualizer.h"

void    set_render_color(SDL_Renderer *renderer, SDL_Color c)
{
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
}