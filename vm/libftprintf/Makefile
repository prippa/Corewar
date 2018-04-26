# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 19:36:03 by vkovsh            #+#    #+#              #
#    Updated: 2018/03/17 17:31:42 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

CC 			=	gcc
CC_FLAGS 	=	-Wall -Werror -Wextra

SRC_PATH 	=	./srcs/

INC_PATH	=	./includes/ $(LIBFT_PATH)includes/
OBJ_PATH	=	./obj/
LIBFT_PATH	=	./libft/
MACRO_PATH  =   ./srcs/macro/
PARSER_PATH =   ./srcs/parser/

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC			=	$(addprefix -I, $(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)

OBJ_NAME	+=	$(LIBFT_NAME:.c=.o)

OBJ_NAME    +=  $(MACRO_NAME:.c=.o)

OBJ_NAME    +=  $(PARSER_NAME:.c=.o)

PARSER_NAME =   parse_specs.c						\
				get_spec.c							\
				set_flag1.c							\
				set_width.c							\
				set_precision.c						\
				set_flag2.c							\
				set_type.c							\
				set_background.c					\
				set_color.c							\
				set_plus_and_space_to_value.c		\
				set_sharp_to_value.c				\
				set_precision_to_value.c			\
				set_precision_to_pointer.c			\
				set_precision_to_numeric.c			\
				set_precision_to_string.c			\
				set_width_to_value.c				\
				set_color_and_background_to_value.c

MACRO_NAME  =   check_double_percent.c  \
                fresh_value.c           \
                ft_output.c             \
                init_min_str.c          \
                init_list.c 			\
                set_spec.c				\
				is_unsigned.c			\
				is_flag1.c				\
				is_type.c				\
				join_none.c				\
				join_n.c				\
				join_t.c				\
				join_r.c				\
				join_big_s.c			\
				join_big_c.c			\
				join_signed_decimal.c	\
				join_unsigned_value.c	\
				join_c.c				\
				join_s.c				\
				join_percent.c			\
				join_p.c				\
				del_one.c				\
				is_numeric_type.c		\
				is_null_pointer.c

SRC_NAME	=	ft_printf.c 		\
				format_value.c 		\
				ft_dprintf.c		\
				check_asterisk.c	\
				set_value.c	

LIBFT_NAME	=	ft_islow.c 		    \
				ft_lstrev.c		    \
				ft_memalloc.c 	    \
				ft_putendl.c 	    \
				ft_strcpy.c 	    \
				ft_strmapi.c 	    \
				ft_strsub.c		    \
				ft_isprint.c	    \
				ft_memccpy.c	    \
	   			ft_putendl_fd.c	    \
				ft_strdel.c		    \
				ft_strncat.c	    \
	   			ft_strtolower.c	    \
				ft_arealpha.c	    \
				ft_isupper.c	    \
	   			ft_memchr.c		    \
				ft_putnbr.c		    \
				ft_strdup.c		    \
	   			ft_strncmp.c	    \
				ft_strtoupper.c	    \
				ft_aredigits.c	    \
				ft_itoa.c		    \
				ft_memcmp.c		    \
				ft_putnbr_fd.c	    \
				ft_strequ.c		    \
				ft_strncpy.c	    \
				ft_strtrim.c	    \
				ft_atoi.c		    \
				ft_lstadd.c		    \
				ft_memcpy.c		    \
				ft_putstr.c		    \
				ft_striter.c	    \
				ft_strnequ.c	    \
				ft_tolower.c	    \
				ft_bzero.c		    \
				ft_lstdel.c		    \
				ft_memdel.c		    \
				ft_putstr_fd.c	    \
				ft_striteri.c	    \
				ft_strnew.c		    \
				ft_toupper.c	    \
				ft_isalnum.c	    \
				ft_lstdelone.c	    \
				ft_memmove.c	    \
				ft_strcat.c		    \
				ft_strjoin.c	    \
				ft_strnstr.c	    \
				ft_isalpha.c	    \
				ft_lstiter.c	    \
				ft_memset.c		    \
				ft_strchr.c		    \
				ft_strlcat.c	    \
				ft_strrchr.c	    \
				ft_isascii.c	    \
				ft_lstmap.c		    \
				ft_putchar.c	    \
				ft_strclr.c		    \
				ft_strlen.c		    \
				ft_strsplit.c	    \
				ft_isdigit.c	    \
				ft_lstnew.c		    \
				ft_putchar_fd.c	    \
				ft_strcmp.c		    \
				ft_strmap.c		    \
				ft_strstr.c		    \
				ft_lstcount.c	    \
				get_next_line.c	    \
				ft_ishex.c		    \
				ft_arehex.c 	    \
				ft_lltoa.c 		    \
				ft_ulltoa_base.c	\
				ft_ulltoa.c			\
				ft_wstr_to_str.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(MACRO_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(PARSER_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove..." [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re 
