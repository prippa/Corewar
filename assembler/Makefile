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

NAME	=	asm

FLGS	=	gcc -g -Wall -Wextra -Werror
SRCS	=	./srcs/
INCL	=	./includes/ ../libft/includes/
OBJS	=	./obj/
LB_LK	=	-L ../libft -lft

FUNC	=	asm.c errors.c validator.c transform.c write_command.c \
			correct_cmd.c write_command2.c free_all_asm.c find_coord.c \
			generate_file_name.c write_to_struct.c binary_and.c binary_or.c \

OBJCS	=	$(FUNC:.c=.o)

OBJC	=	$(addprefix $(OBJS), $(OBJCS))
INC		=	$(addprefix -I, $(INCL))

all: create $(NAME)

create:
	@mkdir -p $(OBJS)

$(NAME): $(OBJC)
	@gcc -o ../$(NAME) $(OBJC) $(LB_LK)
	@echo "\x1B[0;32m"$(NAME) "ready"

$(OBJS)%.o: $(SRCS)%.c
	@$(FLGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@echo "\x1B[1;31mobjects" $(NAME) "deleted"
