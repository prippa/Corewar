#ifndef BUTTON_H
# include "base.h"
# include "ltexture.h"

/*
** Allocates memory for a new checkbox
** and sets position
*/
t_checkbox				*create_checkbox(SDL_Point position,
										const char *text,
										t_arena *arena);

/*
** Handles mouse event for checkbox
*/
void					handle_checkbox_event(SDL_Event* e,
										t_checkbox *btn,
										t_arena *arena);

/*
** Shows checkbox sprite
*/
void					render_checkbox_sprite(t_checkbox *btn,
										t_arena *arena);

/*
** Frees memory
*/
void					free_checkbox(t_checkbox *btn);

/*
** Allocates memory for a new button
** and sets position
*/
t_button				*create_button(double angle,
										SDL_Point position,
										const char *text,
										SDL_Renderer *renderer,
										SDL_Point params,
										void *sprites);
/*
** Handles mouse event for button
*/
void					handle_button_event(SDL_Event *e,
										t_button *btn,
										t_arena *arena,
											t_startmenu id);

/*
** Shows button sprite
*/
void					render_button_sprite(t_button *btn,
											t_arena *arena);

/*
** Frees memory
*/
void					free_button(t_button *btn);

void					handle_movebutton_event(SDL_Event *e,
											t_button *btn,
											t_arena *arena,
											t_movemenu id);
#endif