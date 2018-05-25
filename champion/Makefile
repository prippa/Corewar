# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 13:38:18 by vgladush          #+#    #+#              #
#    Updated: 2018/04/20 17:23:39 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	superdude

FLGS	=	gcc -Wall -Wextra -Werror
SRCS	=	./srcs/
INCL	=	./includes/ ../libft/includes/
OBJS	=	./obj/
LB_LK	=	-L ../libft -lft

FUNC	=	

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
