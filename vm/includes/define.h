/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:39 by prippa            #+#    #+#             */
/*   Updated: 2018/04/26 18:48:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

extern struct s_corewar	*g_cw;

# define FILE_NAME_MAX		4096
# define CW_F_SIZE			1

typedef enum	e_flags
{
	DUMP = 0
}				t_flags;

/*
** Error management
*/

typedef enum	e_error_numbers
{
	MALLOC = 1,
	LSEEK,
	OPEN_FILE,
	READ_FILE,
	MANY_CHAMPS,
	USAGE,
	NO_CHAMPS,
	INV_N_FLAG,
	INV_DUMP_FLAG,
	HEADER,
	PROG_NAME,
	PROG_SIZE_TO_BIG,
	COMMENT,
	PROG_SIZE_INVALID,
	NOT_EXIST_CODE,
	NOT_CORRECT_CODAGE
}				t_error_numbers;

# define ERR_MALLOC_MESSAGE		"malloc is failed"
# define ERR_LSEEK_CUR_MESSAGE	"lseek to current position failed"

# define CW_USAGE	"Usage: ./corewar [-dump nbr_cycles] \
[[-n number] champion1.cor] ..."

/*
******************************* map ****************************************
*/

# define NEWLINE_QUANTITY 63
# define SPACES_BYTES 2

/*
** End
*/

typedef enum	e_op_code
{
	LIVE = 1,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}				t_op_code;

#endif
