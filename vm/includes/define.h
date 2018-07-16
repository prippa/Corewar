/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:48:39 by prippa            #+#    #+#             */
/*   Updated: 2018/06/05 16:25:37 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
************************************ Basics ************************************
*/

extern struct s_corewar	g_cw;

# define FILE_NAME_MAX		4096
# define CW_F_SIZE			3
# define CW_BIT				64
# define CW_FUNC_NUMBER		16
# define ALIVE				1
# define DEAD				0

typedef enum	e_flags
{
	DUMP = 0,
	VISU,
	AFF_F
}				t_flags;

/*
******************************* Functions **************************************
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

# define IS_COMMAND(x) (x > 0 && x < 17)
# define IS_INVALID_REG(x) (x < 1 || x > REG_NUMBER)
# define RRR	84
# define RDR	100
# define RIR	116
# define RDD	104
# define RID	120
# define RRD	88
# define DRR	148
# define DDR	164
# define DIR	180
# define IRR	212
# define IDR	228
# define IIR 	244
# define DR		144
# define IR		208
# define RR		80
# define RI		112
# define R 		64

# define TP_REG	1
# define TP_IND	2

# define CODAGE_SKIP 2
# define SINGLE_COMB 1
# define DOUBLE_COMB 2
# define TRIPLE_COMB 3

/*
******************************* Error management *******************************
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
	NOT_CORRECT_CODAGE,
	INVALID_REG_AV
}				t_error_numbers;

# define ERR_MALLOC_MESSAGE		"malloc is failed"
# define ERR_LSEEK_CUR_MESSAGE	"lseek to current position failed"

/*
************************************* Map **************************************
*/

# define IS_BASE_COLOR(x) ((x) > 0 && (x) < 5)
# define CYCLES_LIGHT 49

#endif
