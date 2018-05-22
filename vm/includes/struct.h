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

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct		s_champ
{
	header_t		header;
	char			file_name[FILE_NAME_MAX + 1];
	int				fd;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_parse_data
{
	t_champ			*champs;
}					t_parse_data;

/*
**
*/

typedef struct		s_corewar
{
	t_parse_data	pd;
}					t_corewar;

#endif
