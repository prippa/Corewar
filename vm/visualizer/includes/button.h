#ifndef BUTTON_H
# include "base.h"
# include "ltexture.h"

/*
** Sprites for start menu button states
** wraped in ltexture and prepare for rendering
*/
extern t_ltexture		*g_start_btn_sprites[TOTAL_SPRITES];

/*
** Sprites for fullscreen checkbox
*/
extern t_ltexture		*g_full_sprites[TOTAL_FULL_SPRITES];

/*
** Sprites for move button states
** wraped in ltexture and prepare for rendering
*/
extern t_ltexture		*g_move_btn_sprites[TOTAL_MOVE_SPRITES];

typedef enum	e_btnsprite
{
	BUTTON_MOUSE_OUT,
	BUTTON_MOUSE_OVER_MOTION,
	BUTTON_MOUSE_DOWN,
	BUTTON_MOUSE_UP,
	BUTTON_TOTAL
}				t_btnsprite;

typedef enum	e_movebtnsprite
{
	MOVE_BUTTON_MOUSE_OUT,
	MOVE_BUTTON_MOUSE_OVER_MOTION,
	MOVE_BUTTON_MOUSE_DOWN,
	MOVE_BUTTON_MOUSE_UP,
	MOVE_BUTTON_TOTAL
}				t_movebtnsprite;				

typedef enum	e_cbxsprite
{
	CHECK_MOUSE_OUT,
	CHECK_MOUSE_IN,
	CROSS_MOUSE_OUT,
	CROSS_MOUSE_IN
}				t_cbxsprite;

typedef enum	e_startmenu
{
	START_MENU_BTN,
	STOP_MENU_BTN,
	INFO_MENU_BTN,
	EXIT_MENU_BTN,
}				t_startmenu;

typedef enum	e_movemenu
{
	UP_MENU_BTN,
	RIGHT_MENU_BTN,
	DOWN_MENU_BTN,
	LEFT_MENU_BTN
}				t_movemenu;

typedef struct	s_button
{
	SDL_Point	position;
	t_btnsprite	current_sprite;
	t_ltexture	*button_txt;
	SDL_Point	txt_position;
	int			width;
	int			height;
}				t_button;

typedef struct	s_checkbox
{
	SDL_Point	position;
	t_cbxsprite	current_sprite;
	t_ltexture	*checkbox_txt;
	SDL_Point	txt_position;
	bool		checked;
}				t_checkbox;

/*
** Start menu buttons
*/
extern t_button	*g_start_btns[TOTAL_BUTTONS];

/*
** Fullscreen checkbox
*/
extern t_checkbox *g_full_btn;

/*
** Move buttons
*/
extern t_button *g_move_btns[TOTAL_MOVE_BUTTONS];

/*
** Allocates memory for a new checkbox
** and sets position
*/
t_checkbox		*create_checkbox(SDL_Point position,
									const char *text,
									SDL_Renderer *renderer);

/*
** Handles mouse event for checkbox
*/
void			handle_checkbox_event(SDL_Event* e,
										t_checkbox *btn,
										t_arena *arena);

/*
** Shows checkbox sprite
*/
void			render_checkbox_sprite(t_checkbox *btn,
										SDL_Renderer *renderer);

/*
** Frees memory
*/
void			free_checkbox(t_checkbox *btn);

/*
** Allocates memory for a new button
** and sets position
*/
t_button		*create_button(SDL_Point position,
								const char *text,
								SDL_Renderer *renderer,
								SDL_Point params);
/*
** Handles mouse event for button
*/
void			handle_button_event(SDL_Event *e,
									t_button *btn,
									t_arena *arena,
									t_startmenu id);

/*
** Shows button sprite
*/
void			render_button_sprite(t_button *btn,
										SDL_Renderer *renderer);

/*
** Frees memory
*/
void			free_button(t_button *btn);
#endif