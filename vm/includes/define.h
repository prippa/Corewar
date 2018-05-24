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

typedef enum	e_error_numbers
{
	MALLOC = 1,
	OPEN_FILE,
	READ_FILE,
	HEADER,
	PROG_NAME
}				t_error_numbers;

typedef enum	e_op_code
{
	LIVE = 1,
	ID,
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

# define FILE_NAME_MAX		4096

#endif
