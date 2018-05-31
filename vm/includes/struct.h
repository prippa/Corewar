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
	t_header			head; 							// nope;
	char				file_name[FILE_NAME_MAX + 1];	// nope;
	int					fd;								// nope;
	unsigned char		code[CHAMP_MAX_SIZE + 1];		// yeap;
	struct s_champ		*next;							// yeap;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs;
	long long int		tmp;
	int					champs_count;
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

typedef	struct			s_processes					// fork will create a process and will change the map;
{
	unsigned char		code[CHAMP_MAX_SIZE + 1];	// copy from champs;
	int					color;						// iteratively {1 - 4};
	int					PC;							// current position of the stack command line (iteratively according to the quantity of champs);
	int					carry;						// initially has zero value because this var will be modified after execution of the command;
	unsigned int		registers[16];				// inherited processes have to have the same player register ?
}						t_processes;

typedef struct			s_stack
{
	unsigned char		stack[MEM_SIZE];			// whole stack;
	int					stack_color[MEM_SIZE];		// colors manipulation;
}						t_stack;					

/*
** End
*/

typedef struct			s_corewar
{
	t_parse_data		pd;
	t_stack				map;
	t_processes			processes;
}						t_corewar;

#endif
