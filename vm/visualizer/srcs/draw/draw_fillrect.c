#include "visualizer.h"

void	draw_fillrect(SDL_Rect rect, SDL_Color rgb, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, rgb.r, rgb.g, rgb.b, rgb.a);
	SDL_RenderFillRect(renderer, &rect);
}
