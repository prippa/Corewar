#include "visualizer.h"

bool		init_button_panel(t_arena *arena)
{
	if (!(arena->btn_panel = load_from_file(INFO_PANEL, arena->renderer, BLACK_COLOR)))
		return (false);
	return (true);
}