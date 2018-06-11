/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:18:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/05/24 16:18:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include <stdio.h>
# define IMG_FOLDER "./vm/visualizer/images/"
# define BTN_FOLDER "./vm/visualizer/images/buttons"
# define ARROW_IMG "./vm/visualizer/images/buttons/arrow.png"
# define CHECK_IMG "./vm/visualizer/images/buttons/red_check.png"
# define CROSS_IMG "./vm/visualizer/images/buttons/red_cross.png"
# define MENU_DOWN_IMG "./vm/visualizer/images/buttons/red_down.png"
# define MENU_ON_IMG "./vm/visualizer/images/buttons/red_on.png"
# define MENU_OUT_IMG "./vm/visualizer/images/buttons/red_out.png"
# define MENU_UP_IMG "./vm/visualizer/images/buttons/red_up.png"
# define TILEBLOCK_IMG "./vm/visualizer/images/tileblock.jpg"
# define BACK_IMG "vm/visualizer/images/colosseum.jpg"
# define GET_DMODE_SUCCESS 0
# define SCREEN_WIDTH 2560
# define SCREEN_HEIGHT 1440
# define MAP_SIZE 4096
# define MIN_ZOOM 0.5
# define MAX_ZOOM 10
# define FIGURES_COUNT 16
# define BUTTON_H
# define BUTTON_WIDTH (SCREEN_WIDTH / 5)
# define BUTTON_HEIGHT (SCREEN_HEIGHT / 10)
# define CHECKBOX_WIDTH 50
# define CHECKBOX_HEIGHT 50
# define TOTAL_BUTTONS 4
# define TOTAL_SPRITES 4
# define TOTAL_FULL_SPRITES 4
# define TOTAL_MOVE_BUTTONS 4
# define TOTAL_MOVE_SPRITES 4
# define NO_BUTTON_ID 0
# define YES_BUTTON_ID 1
# define CANSEL_BUTTON_ID 2
# define NO_KEY 0
# define RETURN_KEY SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT
# define ESCAPE_KEY SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT
# define NO_BUTTON {NO_KEY, NO_BUTTON_ID, "No"}
# define YES_BUTTON	{RETURN_KEY, YES_BUTTON_ID, "Yes"}
# define CANSEL_BUTTON {ESCAPE_KEY, CANSEL_BUTTON_ID, "Cansel"}

/*
** Number of message box buttons
*/
# define MESSAGE_BOX_BUTTON_NBR 3

/*
** Defined color for standard color scheme
*/
# define WIN_BACK {0xff, 0x0, 0x0}
# define TXT {0x0, 0xff, 0x0}
# define BTN {0xff, 0x0, 0x0}
# define BTN_BACK {0x0, 0x0, 0xff}
# define BTN_SEL {0xff, 0x0, 0xff}
# define MESSAGE_BOX_COLOR_SCHEME {{WIN_BACK, TXT, BTN, BTN_BACK, BTN_SEL}}

/*
** End
*/

/*
** Wrapper for SDL texture
*/
typedef struct					s_ltexture
{
	SDL_Texture					*texture;
	int							width;
	int							height;
}								t_ltexture;

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
** Position for renderer
*/
typedef struct					s_rposition
{
	double						angle;
	SDL_Point					*left_corner;
	SDL_Point					*center;
	SDL_Rect					*clip;
}								t_rposition;

/*
** Text for rendering
*/
typedef struct					s_text
{
	const char					*font_name;
	const char					*txt;
	int							font_weight;
	SDL_Color					txt_color;
}								t_text;

/*
** Structure with information about
** graphical representation for Corewar Arena
*/
typedef struct					s_arena
{
	/*
	** Start menu buttons
	*/
	t_button					*start_btns[TOTAL_BUTTONS];
	/*
	** Sprites for start menu button states
	** wraped in ltexture and prepare for rendering
	*/
	t_ltexture					*start_btn_sprites[TOTAL_SPRITES];
	/*
	** Dialog buttons Yes, No, Cansel
	*/
	SDL_MessageBoxButtonData	msgbox_buttons[MESSAGE_BOX_BUTTON_NBR];
	/*
	** If false quit state inits
	*/
	bool						quit;
	bool						inited;
	bool						is_rendered;
	bool						is_fullscreen;
	bool						pause;
	t_ltexture					*tile_block;
	float						zoom;
	int							thread_count;
	int							start_for_thread;
	int							end_for_thread;
	SDL_Rect					viewport;
	SDL_Point					top_left;
	SDL_Window					*window;
	SDL_Surface					*screen_surface;
	SDL_Renderer				*renderer;
	SDL_Event					e;
	SDL_DisplayMode				d_mode;
	t_ltexture					*figures[FIGURES_COUNT];
	Uint8						bytes[MAP_SIZE];
	SDL_Color					colors[MAP_SIZE];
	Uint8						new_bytes[MAP_SIZE];
	SDL_Color					new_colors[MAP_SIZE];
}								t_arena;
#endif
