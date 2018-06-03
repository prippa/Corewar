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
	int					champ_number;
	struct s_champ		*next;							// yeap;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs; 						// to add champ name/counter;
	long long int		tmp;
	int					champs_count;
	int					nbr_cycles;						// -dump flag
	char				flags[CW_F_SIZE];
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
	unsigned int		id;
	int					color;						// R: {1 - 4};
	int					process_PC;					// current position of the stack command line (iteratively according to the quantity of champs);
	int					carry;						// initially has zero value because this var will be modified after execution of the command;
	int					champ_size;					// var for init procedure;
	int					registers[REG_NUMBER];		// r1 -> player_name register;
	struct s_processes	*next;						// pointer to the next element;
	struct s_processes	*prev;						// pointer to the next element;
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
	t_processes			*proc_start;
	t_processes			*proc_end;
	int					loop;
	unsigned int		i;
	unsigned int		proc_counter;				// size of active processes
	unsigned int		id_counter;					// counter of id in processes
}						t_corewar;

#endif
