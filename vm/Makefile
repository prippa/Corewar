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

#FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc -g

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

HEAD_VM		=	corewar.h define.h function.h struct.h
HEAD_CW		=	op.h

C_VM		=	main.c cw_init.c cw_free.c cw_exit.c cw_helpers.c

C_PARSER	=	cw_parser.c cw_parse_args.c cw_get_basic_data.c\
				cw_parse_flags.c

C_SRUC_MP	=	t_champ.c t_processes.c

C_CORE		=	cw_get_command.c cw_load_map.c cw_game_loop.c\
				cw_display_map.c

C_FUNC		=	cw_binary_and.c cw_binary_or.c cw_binary_xor.c\
				cw_add.c cw_sub.c cw_sti.c cw_ld.c cw_live.c\
				cw_lld.c cw_ldi.c cw_zjmp.c cw_lldi.c cw_aff.c

OBJ_VM 		= 	$(C_VM:.c=.o)
OBJ_PARSER	= 	$(C_PARSER:.c=.o)
OBJ_SRUC_MP	= 	$(C_SRUC_MP:.c=.o)
OBJ_CORE	= 	$(C_CORE:.c=.o)
OBJ_FUNC	=	$(C_FUNC:.c=.o)

OBJ 		= 	$(addprefix $(DIR_OBJ), $(OBJ_VM) $(OBJ_PARSER) $(OBJ_SRUC_MP) $(OBJ_CORE) $(OBJ_FUNC))
INC 		= 	$(addprefix -I, $(DIR_VM_INC) $(DIR_LIB_INC) $(DIR_CW_INC))
INC_VM 		= 	$(addprefix $(DIR_VM_INC), $(HEAD_VM))
INC_VM 		+= 	$(addprefix $(DIR_CW_INC), $(HEAD_CW))

all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

#-------------------------COMPILE BLOCK-------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(VIS_NAME) ]

#---source---
$(DIR_OBJ)%.o: $(DIR_VM)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---parser---
$(DIR_OBJ)%.o: $(DIR_PARSER)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---struct_manipulations---
$(DIR_OBJ)%.o: $(DIR_SRUC_MP)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---core---
$(DIR_OBJ)%.o: $(DIR_CORE)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---functions---
$(DIR_OBJ)%.o: $(DIR_FUNC)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]
#---------------------------------------------------------------
clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(VIS_NAME) ]

re: fclean all

.PHONY: all clean fclean re 