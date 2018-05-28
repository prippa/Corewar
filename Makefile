# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 13:38:18 by vgladush          #+#    #+#              #
#    Updated: 2018/05/26 22:18:38 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CRWR_PH	=	./vm/
CHAM_PH	=	./champion/
ASM_PAT	=	./assembler/
LB_PATH	=	./libft/

all:
	@make -C $(LB_PATH)
	@make -C $(ASM_PAT)
	# @make -C $(CRWR_PH)
	# @make -C $(CHAM_PH)

clean:
	@make -C $(LB_PATH) clean
	@make -C $(ASM_PAT) clean
	# @make -C $(CRWR_PH) clean
	# @make -C $(CHAM_PH) clean

fclean: clean
	@rm -rf $(LB_PATH)libft.a
	@echo "\x1B[0;31mlift.a deleted"
	@rm -f asm corewar superdude
	@echo "asm & corewar & superdude deleted"

re: fclean all
