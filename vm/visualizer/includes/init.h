#ifndef INIT_H
# define INIT_H
# include "base.h"

bool	init_devices(void);
bool	init_music(t_arena *arena);
bool	init_controls(t_arena *arena);
bool	init_start_buttons(t_arena *arena);
bool	init_figures(t_arena *arena);
bool	init_move_buttons(t_arena *arena);
bool	init_background(t_arena *arena);
bool	init_infopanel(t_arena *arena);
bool	init(t_arena *arena);
bool	init_checkboxes(t_arena *arena);
bool	init_button_panel(t_arena *arena);
bool	init_statuses(t_arena *arena);
#endif