/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datastructs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:57:32 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 15:03:15 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASTRUCTS_H
# define DATASTRUCTS_H

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef enum		e_flag1
{
	IGNORE1 = 0,
	SHARP = '#',
	ZERO = '0',
	MINUS = '-',
	PLUS = '+',
	SPACE = '\040'
}					t_flag1;

typedef enum		e_flag2
{
	IGNORE2 = 0,
	hh = 'H',
	h = 'h',
	ll = 'L',
	l = 'l',
	j = 'j',
	z = 'z'
}					t_flag2;

typedef enum		e_type
{
	none = 0,
	r = 'r',
	s = 's',
	S = 'S',
	p = 'p',
	d = 'd',
	D = 'D',
	i = 'i',
	o = 'o',
	O = 'O',
	u = 'u',
	U = 'U',
	x = 'x',
	X = 'X',
	c = 'c',
	C = 'C',
	T = 'T',
	b = 'b',
	B = 'B',
	n = 'n',
	PERCENT = '\033'
}					t_type;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_spec
{
	struct s_color	color;
	struct s_color	background;
	enum e_bool		sharp_flag;
	enum e_bool		zero_flag;
	enum e_bool		minus_flag;
	enum e_bool		plus_flag;
	enum e_bool		space_flag;
	enum e_bool		asterisk_width;
	enum e_bool		asterisk_precision;
	enum e_bool		asterisk_color;
	enum e_bool		asterisk_background;
	int				width;
	int				precision;
	enum e_flag2	flag2;
	enum e_type		type;
	char			next_char;
}					t_spec;

typedef struct		s_value
{
	struct s_spec	spec;
	void			*value;
}					t_value;

typedef struct		s_pfargs
{
	va_list			argptr;
	struct s_list	*t;
	char			*output;
	int				length;
	int				fd;
	struct s_spec	spec;
}					t_pfargs;
#endif
