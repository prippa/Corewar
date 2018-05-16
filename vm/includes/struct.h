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

typedef enum	e_error_numbers
{
	MALLOC = 1
}				t_error_numbers;

typedef struct		s_parse_data
{
	int				num;
	char			*name;
}					t_parse_data;

typedef struct		s_corewar
{
	t_parse_data	pd;
}					t_corewar;

#endif
