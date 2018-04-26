/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:15:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 17:17:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_value(char **output, char *value, t_spec spec)
{
	char	*to_del;
	char	*first_space;

	first_space = NULL;
	if (spec.type != T)
	{
		set_plus_and_space_to_value(&value, spec);
		set_precision_to_value(&value, spec);
		set_sharp_to_value(&value, spec);
		set_color_and_background_to_value(&value, spec);
		set_width_to_value(&value, spec);
		if (spec.zero_flag && spec.space_flag)
		{
			first_space = ft_strchr(value, ' ');
			if (first_space)
			{
				*first_space = '0';
				*value = ' ';
			}
		}
	}
	to_del = *output;
	*output = ft_strjoin(*output, value);
	ft_strdel(&to_del);
	ft_strdel(&value);
}
