# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 13:38:18 by vgladush          #+#    #+#              #
#    Updated: 2018/05/26 15:56:04 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../asm
VIS_NAME	=	asm

DIR_LIB		=	../libft
LIBFT		=	$(DIR_LIB)/libft.a
FLGS		=	gcc -Wall -Wextra -Werror
SRCS		=	./srcs/
INCL		=	./includes/ $(DIR_LIB)/includes/
OBJS		=	./obj/
LB_LK		=	-L $(DIR_LIB) -lft

FUNC		=	asm.c errors.c validator.c transform.c write_command.c \
			correct_cmd.c write_command2.c free_all_asm.c find_coord.c \
			generate_file_name.c write_to_struct.c

OBJCS		=	$(FUNC:.c=.o)

OBJC		=	$(addprefix $(OBJS), $(OBJCS))
INC			=	$(addprefix -I, $(INCL))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJS)

$(NAME): $(OBJC) $(LIBFT)
	@gcc -o $(NAME) $(OBJC) $(LB_LK)
	@echo "\x1B[0;32m$(VIS_NAME) ready\x1B[0m"

$(OBJS)%.o: $(SRCS)%.c
	@$(FLGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@echo "\x1B[1;31mobjects $(VIS_NAME) deleted\x1B[0m"

fclean:
	@rm -rf $(OBJS)
	@echo "\x1B[1;31mobjects$(VIS_NAME) deleted\x1B[0m"
	@rm -f $(NAME)
	@echo "\x1B[1;31m$(VIS_NAME) deleted\x1B[0m"

re: fclean all
