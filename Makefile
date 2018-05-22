# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 11:59:13 by otimofie          #+#    #+#              #
#    Updated: 2018/05/03 19:23:57 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS =  ./srcs/write_to_file.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)
	
all: $(NAME)

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	@echo "\033[0;36mCompilation started => [ $(NAME) ]\033[0m"
	@make -C libft
	@gcc $(CFLAGS) -I. $(SRCS) -L ./libft -lftprintf -o $(NAME)
	@echo "\033[93mCompilation finished => [ $(NAME) ]\033[0m"

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C libft
	@echo "\033[0;31mDeleted => [ $(NAME) ]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) $(LIB)
	@make fclean -C libft
	@echo "\033[0;31mFull Deleted => [ $(NAME) ]\033[0m"

re: fclean all
	@echo "\033[94mRedone => [ $(NAME) ]\033[0m"

.PHONY: all clean fclean re