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
//g_cw.pd.champs
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
# include "corewar.h"
# include "ft_printf.h"
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
# define GREY_PANEL_IMG "vm/visualizer/images/grey_panel.png"
# define MAIN_THEME "music/10 Route 666.mp3"
# define INFO_PANEL "vm/visualizer/images/panel2.jpg"
# define GET_DMODE_SUCCESS 0
# define SCREEN_WIDTH (arena->d_mode.w - 200)
# define SCREEN_HEIGHT (arena->d_mode.h - 200)
# define MAP_SIZE 4096
# define MIN_ZOOM 0.5
# define MAX_ZOOM 10
# define FIGURES_COUNT 16
# define BUTTON_H
# define BUTTON_WIDTH (SCREEN_WIDTH >> 4)
# define BUTTON_HEIGHT (SCREEN_HEIGHT >> 5)
# define CHECKBOX_WIDTH (BUTTON_WIDTH >> 1)
# define CHECKBOX_HEIGHT (BUTTON_HEIGHT)
# define TOTAL_BUTTONS 4
# define TOTAL_SPRITES 4
# define INFOPANEL_WIDTH (SCREEN_WIDTH - arena->abs_arena_width)
# define TOTAL_FULL_SPRITES 4
# define TOTAL_MOVE_BUTTONS 4
# define TOTAL_MOVE_SPRITES 4
# define NO_BUTTON_ID 0
# define YES_BUTTON_ID 1
# define CANSEL_BUTTON_ID 2
# define NO_KEY 0
# define FULL_SPRITES 4
# define RETURN_KEY SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT
# define ESCAPE_KEY SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT
# define NO_BUTTON {NO_KEY, NO_BUTTON_ID, "No"}
# define YES_BUTTON	{RETURN_KEY, YES_BUTTON_ID, "Yes"}
# define CANSEL_BUTTON {ESCAPE_KEY, CANSEL_BUTTON_ID, "Cansel"}
# define MOVE_BTN_WIDTH ((SCREEN_HEIGHT - arena->abs_arena_height) >> 1)
# define RED_COLOR ((SDL_Color){.r = 0xff})
# define YELLOW_COLOR ((SDL_Color){.r = 0xff, .g = 0xff})
# define MAGENTA_COLOR ((SDL_Color){.r = 0xff, .b = 0xff})
# define GREEN_COLOR ((SDL_Color){.g = 0xff})
# define BLUE_COLOR ((SDL_Color){.b = 0xff})
# define CYAN_COLOR ((SDL_Color){.g = 0xff, .b = 0xff})
# define WHITE_COLOR ((SDL_Color){.r = 0xff, .g = 0xff, .b = 0xff})
# define BLACK_COLOR ((SDL_Color){0})
# define GRAY_COLOR ((SDL_Color){.r = 0xa9, .g = 0xa9, .b = 0xa9})
# define BUTTON_MOVE_SOUND "music/background_button.wav"
# define BUTTON_PRESS_SOUND "music/button_main.wav"
# define EXIT_SOUND "music/exit.wav"
# define INFOPANEL_RECTANGLE (SDL_Rect){.x = arena->abs_arena_width, .y = 0, .w = INFOPANEL_WIDTH, .h = SCREEN_HEIGHT}
# define INFOPANEL_TOP_LEFT (SDL_Point){.x = arena->abs_arena_width, .y = 0}
# define INFOPANEL_LABEL_PARAMS (SDL_Point){.x = INFOPANEL_WIDTH, SCREEN_HEIGHT >> 2}
# define LIGHT_RED (SDL_Color){.r=0x8b}
# define LIGHT_BLUE (SDL_Color){.r=0x46, .g=0x82, .b=0xB4}
# define LIGHT_GREEN (SDL_Color){.r=0x3c, .g=0xb3, .b=0x71}
# define LIGHT_CYAN (SDL_Color){.g=0x8b, .b=0x8b}
# define METALLIC_GOLD (SDL_Color){.r=0xD4, .g=0xAF, .b=0x37}
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
# define SPEED_TXT "(cycles per tact)"
# define DURATION_TXT "(duration msec)"

extern const bool		bold_states[25];
extern const SDL_Color	back_colors[25];
extern const SDL_Color	font_colors[25];

/*
** Wrapper for SDL texture
*/
typedef struct					s_ltexture
{
	SDL_Texture					*texture;
	int							width;
	int							height;
	double						angle;
	SDL_Point					left_corner;
	SDL_Point					center;
	SDL_Rect					clip;
}								t_ltexture;

typedef enum					e_btnsprite
{
	BUTTON_MOUSE_OUT,
	BUTTON_MOUSE_OVER_MOTION,
	BUTTON_MOUSE_DOWN,
	BUTTON_MOUSE_UP,
	BUTTON_TOTAL
}								t_btnsprite;

typedef enum					e_movebtnsprite
{
	MOVE_BUTTON_MOUSE_OUT,
	MOVE_BUTTON_MOUSE_OVER_MOTION,
	MOVE_BUTTON_MOUSE_DOWN,
	MOVE_BUTTON_MOUSE_UP,
	MOVE_BUTTON_TOTAL
}								t_movebtnsprite;				

typedef enum					e_cbxsprite
{
	CHECK_MOUSE_OUT,
	CHECK_MOUSE_IN,
	CROSS_MOUSE_OUT,
	CROSS_MOUSE_IN
}								t_cbxsprite;

typedef enum					e_startmenu
{
	START_MENU_BTN,
	STOP_MENU_BTN,
	INFO_MENU_BTN,
	EXIT_MENU_BTN,
	DUR_PLUS_BTN,
	DUR_MIN_BTN,
	CYCLE_PLUS_BTN,
	CYCLE_MIN_BTN,
	BACK_BTN,
	TOTAL_START_BUTTONS
}								t_startmenu;

typedef enum					e_movemenu
{
	UP_MENU_BTN,
	RIGHT_MENU_BTN,
	DOWN_MENU_BTN,
	LEFT_MENU_BTN
}								t_movemenu;

typedef enum					e_checkboxid
{
	FULLSCREEN_CBX,
	SOUND_CBX,
	TOTAL_CHECKBOXES
}								t_checkboxid;

typedef struct					s_checkbox
{
	SDL_Point					position;
	t_cbxsprite					current_sprite;
	t_ltexture					*checkbox_txt;
	SDL_Point					txt_position;
	bool						checked;
}								t_checkbox;

/*
** Position for renderer
*/
typedef struct					s_rposition
{
	double						angle;
	SDL_Point					left_corner;
	SDL_Point					center;
	int							width;
	int							height;
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

typedef struct					s_button
{
	void						(*action)(void *arena);
	t_rposition					btn_pos;
	t_rposition					txt_pos;
	t_btnsprite					current_sprite;
	t_ltexture					*button_txt;
	void						*sprites;
}								t_button;

typedef struct					s_statusbar
{
	t_ltexture					*txt;
	double						k;
}								t_statusbar;

typedef enum					e_champcolor
{
	GREEN_CHAMP,
	BLUE_CHAMP,
	RED_CHAMP,
	CYAN_CHAMP,
	TOTAL_CHAMP
}								t_champcolor;

/*
** Structure with information about
** graphical representation for Corewar Arena
*/
typedef struct					s_arena
{
	SDL_Color					leader_color;
	t_ltexture					*speed_txt;
	t_ltexture					*duration_txt;
	int							cycles_per_tact;
	int							tact_duration;
	Mix_Chunk					*exit_sound;
	Mix_Chunk					*btn_move;
	Mix_Chunk					*btn_press;
	int							fps;
	int							old_fps;
	t_statusbar					statuses[TOTAL_CHAMP];
	int							arena_tile_width;
	int							arena_tile_height;
	int							abs_arena_height;
	int							abs_arena_width;
	/*
	** Infopanel texture
	*/
	t_ltexture					*infopanel_title;
	/*
	** The music that will be played
	*/
	Mix_Music					*theme;
	/*
	** Sprites for move button states
	** wraped in ltexture and prepare for rendering
	*/
	t_ltexture					*move_btn_sprites[TOTAL_MOVE_SPRITES];
	/*
	** Move buttons
	*/
	t_button					*move_btns[TOTAL_MOVE_BUTTONS];
	/*
	** Sprites for fullscreen checkbox
	*/
	t_ltexture					*full_sprites[TOTAL_FULL_SPRITES];
	/*
	** Checkboxes
	*/
	t_checkbox					*checkboxes[TOTAL_CHECKBOXES];
	/*
	** Start menu buttons
	*/
	t_button					*start_btns[TOTAL_START_BUTTONS];
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
	/*
	** Panel for move arrows
	*/
	t_ltexture					*move_panel;
	bool						is_fullscreen;
	bool						pause;
	float						zoom;
	SDL_Event					e;
	SDL_Rect					viewport;
	SDL_Point					top_left;
	SDL_Window					*window;
	SDL_Surface					*screen_surface;
	SDL_Renderer				*renderer;
	SDL_DisplayMode				d_mode;
	/*
	** regular figures
	*/
	t_ltexture					*figures[FIGURES_COUNT];
	/*
	** bold figures
	*/
	t_ltexture					*bold_figures[FIGURES_COUNT];
}								t_arena;
#endif
