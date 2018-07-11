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
# define CW_F_SIZE			2
# define CW_BIT				64
# define ALIVE				1
# define DEAD				0

typedef enum	e_flags
{
	DUMP = 0,
	VISU
}				t_flags;

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

# define REG	1
# define IND	2

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

# define CW_USAGE	"Usage: ./corewar [-visu] [-dump nbr_cycles] \
[[-n number] champion1.cor] ...\n\
######################## Flags Manual ########################\n\
-d N		: Dumps memory after N cycles then exits\n\
-n N		: Sets the number of the next player\n\
-visu		: Big ass visualization\n\
##############################################################"

/*
************************************* Map **************************************
*/

#define IS_BASE_COLOR(x) ((x) > 0 && (x) < 5)

#endif
