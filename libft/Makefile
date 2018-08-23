# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/05/29 01:21:57 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc -g

DIR_INC		=	./includes/
DIR_LIBC	=	./libc/
DIR_FPF		=	./printf/
DIR_OBJ		= 	./obj/

HEAD_LIBC	=	libft.h
HEAD_FPF	=	ft_printf.h

C_LIBC		= 	ft_atoi.c ft_bzero.c ft_isascii.c ft_isspace.c\
			ft_isdigit.c ft_str_is_digit.c ft_memcpy.c\
			ft_putchar.c ft_putstr.c ft_strcat.c\
			ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c\
			ft_strnew.c ft_strjoin.c ft_itoa_base.c get_next_line.c\
			ft_bin_to_int.c ft_strsub.c ft_strncpy.c ft_strjoin_free.c\
			ft_itoa_max.c ft_itoabase.c ft_numlen.c ft_joinfree.c ft_pow.c

C_FPF		= 	ft_printf.c ft_dprintf.c\
				ft_pf_strjoin.c ft_charjoin.c\
				ft_unicode.c ft_conv_sig_int.c ft_conv_unsig_int.c\
				ft_get_flags.c ft_get_type.c\
				ft_get_oux.c ft_get_di.c ft_get_c.c ft_get_s.c\
				ft_output_c_modul.c ft_output_s_modul.c ft_output_d_modul.c\
				ft_output_u_modul.c ft_output_ox_modul.c\
				ft_output_p_modul.c\
				ft_fpf_color.c



OBJ_LIBC 	= 	$(C_LIBC:.c=.o)
OBJ_FPF 	= 	$(C_FPF:.c=.o)

OBJ 		= 	$(addprefix $(DIR_OBJ),$(OBJ_LIBC))
OBJ 		+= 	$(addprefix $(DIR_OBJ),$(OBJ_FPF))

INC 		= 	$(addprefix -I,$(DIR_INC))
INC_LIBC 	= 	$(addprefix $(DIR_INC),$(HEAD_LIBC))
INC_FPF 	= 	$(addprefix $(DIR_INC),$(HEAD_FPF))



all: obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_LIBC)%.c $(INC_LIBC)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

$(DIR_OBJ)%.o: $(DIR_FPF)%.c $(INC_FPF)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files libft ]"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
