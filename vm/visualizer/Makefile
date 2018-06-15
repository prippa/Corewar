# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 15:19:32 by vkovsh            #+#    #+#              #
#    Updated: 2018/05/22 15:19:34 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	visualizer

CC				=	gcc
CC_FLAGS		=	-Wall -Werror -Wextra -g

SRC_PATH		=	./srcs/
ERROR_PATH		=	$(SRC_PATH)error/
INIT_PATH		=	$(SRC_PATH)init/
EVENT_PATH		=	$(SRC_PATH)events/
DRAW_PATH		=	$(SRC_PATH)draw/
LOADER_PATH		=	$(SRC_PATH)loader/
LTEXTURE_PATH	=	$(SRC_PATH)ltexture/
BUTTON_PATH		=	$(SRC_PATH)button/
SDL_PATH		=	./SDL_framework/
MACOS_INC_PATH	=	./includes/ $(SDL_PATH)Headers_macos/
LINUX_INC_PATH	=	./includes/ $(SDL_PATH)Headers_linux/
OBJ_PATH		=	./obj/

OBJ				=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
UNAME			=	$(shell uname)

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

OBJ_NAME		=	$(SRC_NAME:.c=.o)
OBJ_NAME		+=	$(EVENT_NAME:.c=.o)
OBJ_NAME		+=	$(DRAW_NAME:.c=.o)
OBJ_NAME		+=	$(LOADER_NAME:.c=.o)
OBJ_NAME		+=	$(LTEXTURE_NAME:.c=.o)
OBJ_NAME		+=	$(BUTTON_NAME:.c=.o)
OBJ_NAME		+=	$(INIT_NAME:.c=.o)
OBJ_NAME		+=	$(ERROR_NAME:.c=.o)

SRC_NAME		=	visualizer.c				\
					init.c						\
					clear_renderer.c			\
					exit_dialog.c				\
					get_rectangle.c				\
					set_viewport.c				\
					init_start_menu.c			\
					create_figures.c

EVENT_NAME		=	events_manager.c			\
					key_event.c					\
					exit_event.c				\
					wheel_event.c				\
					zoom.c

DRAW_NAME		=	draw_arena.c				\
					draw_fillrect.c				\
					draw_outlinerect.c			\
					draw_arena_split.c

LOADER_NAME		=	load_surface.c				\
					load_texture.c

LTEXTURE_NAME	=	load_from_file.c			\
					free_ltexture.c				\
					render.c					\
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
					render_checkbox_sprite.c	

INIT_NAME		=	init_devices.c

ERROR_NAME		=	force_error.c

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(CC) -o $(NAME) $(OBJ) $(SDL_LIB_LINK)
				@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(EVENT_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(DRAW_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(LOADER_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(LTEXTURE_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(BUTTON_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(INIT_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

$(OBJ_PATH)%.o:	$(ERROR_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
				@echo "Linking" [ $< ]

clean:
				@rm -rf $(OBJ_PATH)
				@echo "Cleaning obj [ $(NAME) ]..."

fclean:			clean
				@rm -f $(NAME)
				@echo "Remove [ $(NAME) ]..."

re: 			fclean all

.PHONY:			all clean fclean re