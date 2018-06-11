#ifndef BUTTON_H
# include "base.h"
# include "ltexture.h"

/*
** Sprites for fullscreen checkbox
*/
extern t_ltexture		*g_full_sprites[TOTAL_FULL_SPRITES];

/*
** Sprites for move button states
** wraped in ltexture and prepare for rendering
*/
extern t_ltexture		*g_move_btn_sprites[TOTAL_MOVE_SPRITES];

/*
** Fullscreen checkbox
*/
extern t_checkbox		*g_full_btn;

/*
** Move buttons
*/
extern t_button			*g_move_btns[TOTAL_MOVE_BUTTONS];

/*
** Allocates memory for a new checkbox
** and sets position
*/
t_checkbox				*create_checkbox(SDL_Point position,
										const char *text,
										SDL_Renderer *renderer);

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
										SDL_Renderer *renderer);

/*
** Frees memory
*/
void					free_checkbox(t_checkbox *btn);

/*
** Allocates memory for a new button
** and sets position
*/
t_button				*create_button(SDL_Point position,
									const char *text,
									SDL_Renderer *renderer,
									SDL_Point params);
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
#endif