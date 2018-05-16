/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:21:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/04/23 19:17:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "op.h"

typedef struct			s_command
{
	int					cmd;
	char				*cod;
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char				*name;
	int					bit;
	t_command			*cmd;
	struct s_label		*next;
}						t_label;

typedef struct			s_asm
{
	int					x;
	int					y;
	header_t			hd;
	t_label				*lb;
}						t_asm;

void					errors_man(t_asm *am, char *s, int o);
void					check_form(char *s, t_asm *am, int i, int j);

#endif
