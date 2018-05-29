# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

DIR_LIB		=	../libft/
LIBFT		=	$(DIR_LIB)libft.a
DIR_LIB_INC	=	$(DIR_LIB)includes/
DIR_CW_INC	=	../includes/
DIR_VM_INC	=	./includes/
DIR_VM		=	./source/
DIR_PARSER	=	./source/parser/
DIR_LIST_MP	=	./source/list_manipulations/
DIR_OBJ		= 	./obj/

HEAD_VM		=	corewar.h define.h function.h struct.h
HEAD_CW		=	op.h

C_VM		=	main.c cw_init.c cw_free.c cw_exit.c

C_PARSER	=	cw_parser.c cw_parse_args.c cw_get_basic_data.c cw_helpers.c\
				cw_get_command.c

C_LIST_MP	=	t_champ.c t_command.c


OBJ_VM 		= 	$(C_VM:.c=.o)
OBJ_PARSER	= 	$(C_PARSER:.c=.o)
OBJ_LIST_MP	= 	$(C_LIST_MP:.c=.o)

OBJ 		= 	$(addprefix $(DIR_OBJ), $(OBJ_VM) $(OBJ_PARSER) $(OBJ_LIST_MP))
INC 		= 	$(addprefix -I, $(DIR_VM_INC) $(DIR_LIB_INC) $(DIR_CW_INC))
INC_VM 		= 	$(addprefix $(DIR_VM_INC), $(HEAD_VM))
INC_VM 		+= 	$(addprefix $(DIR_CW_INC), $(HEAD_CW))


all: lib obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

lib:
	@make -C $(DIR_LIB)

#-------------------------COMPILE BLOCK-------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

#---source---
$(DIR_OBJ)%.o: $(DIR_VM)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---parser---
$(DIR_OBJ)%.o: $(DIR_PARSER)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

#---list_manipulations---
$(DIR_OBJ)%.o: $(DIR_LIST_MP)%.c $(INC_VM)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]
#---------------------------------------------------------------
clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files VM ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re 