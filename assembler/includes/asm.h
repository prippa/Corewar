/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:21:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/23 23:54:31 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "op.h"

typedef struct			s_arg
{
	t_arg_type			tp;
	char				dn;
	void				*av;
	int					x;
	int					y;
}						t_arg;

typedef struct			s_command
{
	int					bit;
	int					codage;
	char				cmd;
	t_arg				arg1;
	t_arg				arg2;
	t_arg				arg3;
	struct s_command	*next;
}						t_command;

typedef struct			s_label
{
	char				*name;
	t_command			*cmd;
	int					bit;
	struct s_label		*next;
}						t_label;

typedef struct			s_asm
{
	header_t			hd;
	t_label				*lb;
	int					nmcm;
	int					x;
	int					y;
}						t_asm;

void					errors_man(t_asm *am, char *s, int o);
void					check_form(char *s, t_asm *am, int i, int j);
void					write_cod(char *s, t_asm *am, char *cmd, t_label *lb);
void					write_cod6(char *s, t_asm *am, char *cmd, t_label *lb);
int						check_cmd(char *s, int j, int i);
char					*tran_str(char i);
t_label					*find_lb_cmd(t_label *lb, int i);
void					bef_error(char *s, t_asm *am, char cmd, int i);
void					crt_arg(char *s, t_asm *am, t_arg *ar, char cmd);
#endif
