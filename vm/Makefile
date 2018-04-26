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

DIR_LIB		=	./libftprintf/
LIBFT		=	$(DIR_LIB)libftprintf.a
DIR_LIB_INC	=	$(DIR_LIB)libft/includes/
DIR_FPF_INC	=	$(DIR_LIB)includes/
DIR_VM_INC	=	./includes/
DIR_VM		=	./source/
DIR_OBJ		= 	./obj/

HEAD_VM		=	corewar.h define.h function.h struct.h

C_VM		=	test.c


OBJ_VM 		= 	$(C_VM:.c=.o)
OBJ 		= 	$(addprefix $(DIR_OBJ), $(OBJ_VM))
INC 		= 	$(addprefix -I, $(DIR_VM_INC) $(DIR_LIB_INC) $(DIR_FPF_INC))
INC_VM 		= 	$(addprefix $(DIR_VM_INC), $(HEAD_VM))


all: lib obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

lib:
	@make -C $(DIR_LIB)

#-------------------------COMPILE BLOCK-------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_VM)%.c $(INC_VM)
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