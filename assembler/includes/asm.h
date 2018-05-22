/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:21:21 by vgladush          #+#    #+#             */
/*   Updated: 2018/05/22 16:43:48 by vgladush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "op.h"

// typedef struct			s_two
// {
// 	char				cmd;
// 	short int			i;
// }						t_two;

// typedef struct			s_four
// {
// 	char				cmd;
// 	int					i;
// }						t_four;

typedef struct			s_command
{
	int					bit;
	// t_two				tw;
	// t_four				fr;
	char				cmd;
	char				on;
	short int			tw;
	int					fr;
	char				*cod;
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
	int					x;
	int					y;
	int					bit;
	header_t			hd;
	t_label				*lb;
}						t_asm;

void					errors_man(t_asm *am, char *s, int o);
void					check_form(char *s, t_asm *am, int i, int j);
void					write_cod(char *s, t_asm *am, char *cmd, t_label *lb);
void					write_cod6(char *s, t_asm *am, char *cmd, t_label *lb);
int						check_cmd(char *s, int j, int i);
char					*tran_str(int i);

#endif
