/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:21:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/25 15:51:59 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "../../includes/op.h"

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
	char				cmd;
	int					codage;
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
	t_header			hd;  // done;
	t_label				*lb; // done;
	int					nmcm;
	int					x;
	int					y;
}						t_asm;

void					errors_man(t_asm *am, char *s, int o);
void					check_form(char *s, t_asm *am, int i, int j);
void					write_cod(char *s, t_asm *am, char cmd, t_label *lb);
void					write_cod5(char *s, t_asm *am, char cmd, t_command *tmp);
void					write_cod6(char *s, t_asm *am, char cmd, t_command *tmp);
void					write_cod7(char *s, t_asm *am, char cmd, t_command *tmp);
int						check_cmd(char *s, int j, t_asm *am, int l);
char					*tran_str(char i);
t_command				*find_lb_cmd(t_label *lb, char *s, t_asm *am, int cmd);
void					bef_error(char *s, t_asm *am, char cmd, int i);
void					crt_arg(char *s, t_asm *am, t_arg *ar, char cmd);
void					all_clear(t_asm *am, char *s);
void					ch_to_coord(t_asm *am);

// write to the file;

char					*generate_file_name(char *file_string);
char					*ft_to_binary(unsigned int n);
int						bstr_to_dec(char *str);
void					initial(char *argv_name, t_asm *am);

void	command_write(t_label	*label, int fd);

#endif
