#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 18:18:58 by vgladush          #+#    #+#              #
#    Updated: 2017/10/28 22:57:41 by vgladush         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

FUN		=	ft_atoi.c ft_bzero.c ft_factorialnb.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
			ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_qstr.c \
			ft_putstr_fd.c ft_putstr.c ft_rotnb.c ft_sqrtrd.c ft_strcat.c \
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_putnbri.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
			ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
			ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
			ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
			ft_tolower.c ft_toupper.c ft_calc.c ft_replchar.c ft_putarstr.c \
			ft_nbrlen.c get_next_line.c ft_dblhex.c ft_itoabase.c ft_strdel.c \
			ft_prfdbl.c ft_prfnbr.c ft_prfoper.c ft_printf.c ft_joinfree.c \
			ft_unicode.c

FUNDIR	=	./srcs/

GFLG	=	gcc -Wall -Werror -Wextra -c

HD		=	$(addprefix -I, ./includes/)

OBJDIR	=	./obj/

OBJS	=	$(FUN:.c=.o)

OBJ		=	$(addprefix $(OBJDIR), $(OBJS))

BLK = '\x1B[0;30m'
RED = '\x1B[0;31m'
GRN = '\x1B[0;32m'
BRW = '\x1B[0;33m'
BLE = '\x1B[0;34m'
PUR = '\x1B[0;35m'
CYN = '\x1B[0;36m'
LGY = '\x1B[0;37m'
DGY = '\x1B[1;30m'
LRD = '\x1B[1;31m'
LGR = '\x1B[1;32m'
YEL = '\x1B[1;33m'
LBL = '\x1B[1;34m'
FIL = '\x1B[1;35m'
LCN = '\x1B[1;36m'
WHT = '\x1B[1;37m'
WCR = '\x1B[0m'

all: $(NAME)

$(NAME): ./Includes/libft.h $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GRN)$(NAME) "ready"

$(OBJDIR)%.o: $(FUNDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(GFLG) $(HD) -o $@ $<

clean:
	@rm -rf $(OBJDIR)
	@echo $(LRD)"objects" $(NAME) "deleted"

fclean: clean
	@rm -f $(NAME)
	@echo $(RED)$(NAME) "deleted"

re: fclean all

.PHONY: clean fclean re all
