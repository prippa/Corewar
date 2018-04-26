/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:05:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:01:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_asterisk(char **str, t_spec *spec)
{
	(*str)++;
	spec->precision = 1;
	spec->asterisk_precision = TRUE;
}

void			set_precision(char **txt_pointer, t_spec *spec)
{
	char		*str;
	int			check;
	char		*precision;

	str = *txt_pointer;
	spec->precision = -1;
	if (str[0] == '.')
	{
		if (ft_isdigit((++str)[0]))
		{
			check = 0;
			while (ft_isdigit(str[check]))
				check++;
			precision = ft_strnew(check);
			ft_memmove(precision, str, check);
			spec->precision = ft_atoi(precision);
			str += check;
			ft_strdel(&precision);
		}
		else if (str[0] == '*')
			set_asterisk(&str, spec);
		else
			spec->precision = 0;
		*txt_pointer = str;
	}
}
