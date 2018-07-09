/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:54 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 16:36:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
********************************** Core Part ***********************************
*/

typedef struct			s_arg
{
	t_arg_type			tp;
	int					av;
}						t_arg;

typedef struct			s_command
{
	int					codage;
	t_arg				arg1;
	t_arg				arg2;
	t_arg				arg3;
}						t_command;

typedef	struct			s_processes
{
	unsigned int		id;
	int					pc;
	char				carry;
	int					registers[REG_NUMBER];
	char 				is_alive;
	short				champ_number;
	short				exec_cycles;
	unsigned char		cmd;
	struct s_processes	*next;
	struct s_processes	*prev;
}						t_processes;

/*
************************ Parsing champions part (data) *************************
*/

typedef struct			s_champ
{
	t_header			head;
	char				file_name[FILE_NAME_MAX + 1];
	int					fd;
	unsigned char		code[CHAMP_MAX_SIZE];
	short				champ_number;
	short				order;
	unsigned int        lives_number;
	unsigned int        last_live;
	unsigned char		color;
	t_processes			*proc_start;
	t_processes			*proc_end;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_parse_data
{
	t_champ				*champs;
	long long			tmp;
	unsigned int		champs_count;
	unsigned int		dump_stop;
	char				flags[CW_F_SIZE];
	char				flag_champ_number[MAX_PLAYERS];
}						t_parse_data;

/*
*********************** Implementing a function pointer ************************
*/

typedef struct			s_op
{
	void				(*func)(t_processes *proc);
	short				cycles_price;
	char				label;
}						t_op;

/*
*************************** Global Elite Structure *****************************
*/

typedef struct			s_corewar
{
	t_parse_data		pd;
	unsigned char		map[MEM_SIZE];
	unsigned char		color_map[MEM_SIZE];
	const t_op			*op;
	unsigned int		cycle;
	int					cycle_to_die;
	int					cycle_to_die_check;
	unsigned int		max_checks_check;
	unsigned int		proc_counter;
	unsigned int		id_counter;
}						t_corewar;

#endif
