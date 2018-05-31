/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:54 by prippa            #+#    #+#             */
/*   Updated: 2018/04/26 18:48:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Parsing champions part (data)
*/

typedef struct			s_champ
{
	t_header			head;
	char				file_name[FILE_NAME_MAX + 1];
	int					fd;
	unsigned char		code[CHAMP_MAX_SIZE + 1];
	struct s_champ		*next;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs;
	long long int		tmp;
}						t_parse_data;

/*
** End
*/

/*
** Core part
*/

typedef struct			s_arg
{
	t_arg_type			tp;
	int					av;
}						t_arg;

typedef struct			s_command
{
	char				cmd;
	int					codage;
	t_arg				arg1;
	t_arg				arg2;
	t_arg				arg3;
}						t_command;

typedef struct			s_stack
{
	unsigned char		stack[MEM_SIZE];		// whole stack;
	int					stack_color[MEM_SIZE];	// colors manipulation;
	int					registers[REG_NUMBER]; 	// processor memory;
	int					PC; 					// current position of the stack command line;
	int					carry;					// success id for the certain commands;
}						t_stack;

/*
** End
*/

typedef struct			s_corewar
{
	t_parse_data		pd;
	t_stack	map;
}						t_corewar;

#endif
