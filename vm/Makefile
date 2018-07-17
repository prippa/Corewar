# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/06/06 17:10:34 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../corewar
VIS_NAME	=	corewar

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc -g

#-------------------VM---------------------
DIR_LIB		=	../libft/
LIBFT		=	$(DIR_LIB)libft.a
DIR_LIB_INC	=	$(DIR_LIB)includes/
DIR_CW_INC	=	../includes/
DIR_VM_INC	=	./includes/
DIR_VM		=	./source/
DIR_PARSER	=	./source/parser/
DIR_SRUC_MP	=	./source/struct_manipulations/
DIR_CORE	=	./source/core/
DIR_OBJ		= 	./obj/
DIR_FUNC	=	./source/functions/
DIR_CONV	=	./source/conversions/
DIR_COLOR	=	./source/color_manipulations/
DIR_VIS		=	./visualizer/
#------------------------------------------

#-------------------Visualizer-------------
DIR_VIS_INC		=	$(DIR_VIS)includes/
SRC_PATH		=	$(DIR_VIS)srcs/
ERROR_PATH		=	$(SRC_PATH)error/
INIT_PATH		=	$(SRC_PATH)init/
EVENT_PATH		=	$(SRC_PATH)events/
DRAW_PATH		=	$(SRC_PATH)draw/
LOADER_PATH		=	$(SRC_PATH)loader/
LTEXTURE_PATH	=	$(SRC_PATH)ltexture/
BUTTON_PATH		=	$(SRC_PATH)button/
UTIL_PATH		=	$(SRC_PATH)utilities/
SDL_PATH		=	$(DIR_VIS)SDL_framework/
MACOS_INC_PATH	=	$(DIR_VIS)includes/ $(SDL_PATH)Headers_macos/
LINUX_INC_PATH	=	$(DIR_VIS)includes/ $(SDL_PATH)Headers_linux/
OBJ_PATH		=	$(DIR_VIS)obj/
#------------------------------------------

UNAME		=	$(shell uname)

ifeq ($(UNAME),Linux)
	INC	:= $(addprefix -I, $(LINUX_INC_PATH))
	SDL_LIB_LINK := -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf		\
						-lSDL2_mixer -lpthread
else ifeq ($(UNAME),Darwin)
	INC := $(addprefix -I, $(MACOS_INC_PATH))
	SDL_LIB_LINK := -lm $(SDL_PATH)SDL2 $(SDL_PATH)SDL2_image		\
						$(SDL_PATH)SDL2_ttf $(SDL_PATH)SDL2_mixer	\
						-lpthread
endif

HEAD_VM		=	corewar.h define.h function.h struct.h
HEAD_CW		=	op.h

#-------------------------------VM----------------------------------
C_VM		=	main.c cw_init.c cw_free.c cw_exit.c\
				cw_end.c

C_PARSER	=	cw_parser.c cw_parse_args.c cw_get_basic_data.c\
				cw_parse_flags.c

C_SRUC_MP	=	t_champ_op.c t_champ_add_free_rev.c t_proc_free.c\
				t_proc_add_cpy.c

C_CORE		=	cw_load_map.c cw_game_loop.c cw_get_codage_tp_av.c\
				cw_move_pc.c

C_FUNC		=	cw_binary_and.c cw_binary_or.c cw_binary_xor.c\
				cw_add.c cw_sub.c cw_sti.c cw_ld.c cw_live.c\
				cw_lld.c cw_ldi.c cw_zjmp.c cw_lldi.c cw_aff.c\
				cw_st.c cw_fork.c cw_lfork.c

C_CONV		=	cw_helpers.c cw_helpers_2.c

C_COLOR		=	cw_vis_refresh_colors.c cw_vis_update_map.c
#-------------------------------------------------------------------

#------------------------------Visualizer---------------------------
SRC_NAME		=	entry_point.c

UTIL_NAME		=	clear_renderer.c			\
					exit_dialog.c				\
					get_rectangle.c				\
					get_digits.c				\
					change_screen_mode.c		\
					reset.c						\
					sdl_putnbr.c				\
					duration_change.c			\
					cycles_change.c

EVENT_NAME		=	events_manager.c			\
					key_event.c					\
					exit_event.c				\
					wheel_event.c				\
					zoom.c						\
					move.c						\
					start_stop.c				\
					info_call.c

DRAW_NAME		=	draw_arena.c				\
					draw_arena_cell.c			\
					draw_fillrect.c				\
					draw_outlinerect.c			\
					draw_controls.c				\
					draw_infopanel.c			\
					draw_button_panel.c			\
					draw_statuses.c				\
					draw_framerate.c

LOADER_NAME		=	load_surface.c				\
					load_texture.c

LTEXTURE_NAME	=	load_from_file.c			\
					free_ltexture.c				\
					render.c					\
					render_part.c				\
					set_color.c					\
					set_blend_mode.c			\
					set_alpha_mode.c			\
					get_render_position.c		\
					load_from_rendered_text.c

BUTTON_NAME		=	create_button.c				\
					handle_button_event.c		\
					render_button_sprite.c		\
					create_checkbox.c			\
					handle_checkbox_event.c		\
					render_checkbox_sprite.c	\
					handle_movebutton_event.c

INIT_NAME		=	init_devices.c				\
					init.c 						\
					init_controls.c				\
					init_start_buttons.c		\
					init_figures.c				\
					init_move_buttons.c			\
					init_music.c				\
					init_infopanel.c			\
					init_checkboxes.c			\
					init_statuses.c	

ERROR_NAME		=	force_error.c
#-------------------------------------------------------------------

#-----------------------------VM--------------------------------
OBJ_VM 		= 	$(C_VM:.c=.o)
OBJ_PARSER	= 	$(C_PARSER:.c=.o)
OBJ_SRUC_MP	= 	$(C_SRUC_MP:.c=.o)
OBJ_CORE	= 	$(C_CORE:.c=.o)
OBJ_FUNC	=	$(C_FUNC:.c=.o)
OBJ_CONV	=	$(C_CONV:.c=.o)
OBJ_COLOR	=	$(C_COLOR:.c=.o)
#---------------------------------------------------------------

#-----------------------------Visualizer------------------------
OBJ_NAME		=	$(SRC_NAME:.c=.o)
OBJ_NAME		+=	$(EVENT_NAME:.c=.o)
OBJ_NAME		+=	$(DRAW_NAME:.c=.o)
OBJ_NAME		+=	$(LOADER_NAME:.c=.o)
OBJ_NAME		+=	$(LTEXTURE_NAME:.c=.o)
OBJ_NAME		+=	$(BUTTON_NAME:.c=.o)
OBJ_NAME		+=	$(INIT_NAME:.c=.o)
OBJ_NAME		+=	$(ERROR_NAME:.c=.o)
OBJ_NAME		+=	$(UTIL_NAME:.c=.o)
#---------------------------------------------------------------

#---------------------Visualizer---------------------
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
#----------------------------------------------------
OBJ 		+= 	$(addprefix $(DIR_OBJ), $(OBJ_VM) $(OBJ_PARSER) $(OBJ_SRUC_MP) $(OBJ_CORE) $(OBJ_FUNC) $(OBJ_CONV) $(OBJ_COLOR))
INC_CW 		= 	$(addprefix -I, $(DIR_VM_INC) $(DIR_LIB_INC) $(DIR_CW_INC))
INC_VM 		= 	$(addprefix $(DIR_VM_INC), $(HEAD_VM))
INC_VM 		+= 	$(addprefix $(DIR_CW_INC), $(HEAD_CW))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------COMPILE BLOCK-------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(SDL_LIB_LINK)
	@echo "Compiling" [ $(VIS_NAME) ]
#-----------------------------VM--------------------------------
#---source---
$(DIR_OBJ)%.o: $(DIR_VM)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---parser---
$(DIR_OBJ)%.o: $(DIR_PARSER)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---struct_manipulations---
$(DIR_OBJ)%.o: $(DIR_SRUC_MP)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---core---
$(DIR_OBJ)%.o: $(DIR_CORE)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---functions---
$(DIR_OBJ)%.o: $(DIR_FUNC)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---conversions---
$(DIR_OBJ)%.o: $(DIR_CONV)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]

#---color_manipulations---
$(DIR_OBJ)%.o: $(DIR_COLOR)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) $(INC_CW) -c -o $@ $<
	@echo "Linking" [ $< ]
#-----------------------------Visualizer------------------------
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(EVENT_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(DRAW_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(LOADER_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(LTEXTURE_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(BUTTON_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(INIT_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(ERROR_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]
				
$(OBJ_PATH)%.o:	$(UTIL_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(FLAGS) -o $@ -c $< $(INC) $(INC_CW)
				@echo "Linking" [ $< ]
#---------------------------------------------------------------
#---------------------------------------------------------------
clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ Visualizer ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ Visualizer ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(VIS_NAME) ]

re: fclean all

.PHONY: all clean fclean re