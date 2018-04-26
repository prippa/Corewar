/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width_to_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:01:04 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 20:02:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	set_width_to_null_string(char **value, t_spec spec)
{
	char			*spaces;
	int				length;

	length = spec.width;
	spaces = ft_strnew(length);
	ft_strdel(&(*value));
	if (spec.zero_flag)
	{
		ft_memset(spaces, '0', length);
		*value = spaces;
	}
	else
	{
		ft_memset(spaces, ' ', length);
		*value = spaces;
	}
}

static inline void	set_width_to_zero_pointer(char **value, t_spec spec)
{
	char			*spaces;
	int				length;
	char			*to_del;

	length = (int)ft_strlen(*value);
	spaces = ft_strnew(spec.width - length);
	to_del = spaces;
	ft_memset(spaces, '0', spec.width - length);
	spaces = ft_strjoin("0x", spaces);
	ft_strdel(&to_del);
	to_del = *value;
	*value = ft_strjoin(spaces, *value + 2);
	ft_strdel(&to_del);
	ft_strdel(&spaces);
}

static void			partitial(t_spec spec,
		char **value,
		char *spaces,
		int length)
{
	char			*double_str;

	if (spec.minus_flag == TRUE)
		*value = ft_strjoin_free(*value, spaces, FALSE, TRUE);
	else if ((spec.plus_flag || **value == '-') && spec.zero_flag)
	{
		if (**value != '-')
			spaces = ft_strjoin_free("+", spaces, FALSE, TRUE);
		else
			spaces = ft_strjoin_free("-", spaces, FALSE, TRUE);
		*value = ft_strjoin_free(spaces, (*value) + 1, TRUE, FALSE);
	}
	else if (spec.sharp_flag == TRUE && spec.zero_flag == TRUE)
	{
		ft_memset(spaces, '0', spec.width - length);
		double_str = ft_strnew(2);
		double_str[0] = (*value)[0];
		double_str[1] = (*value)[1];
		spaces = ft_strjoin_free(double_str, spaces, TRUE, TRUE);
		*value = ft_strjoin_free(spaces, (*value) + 2, TRUE, FALSE);
	}
	else
		*value = ft_strjoin_free(spaces, *value, TRUE, FALSE);
}

static void			set_spaces(char **spaces, t_spec spec, int length)
{
	*spaces = ft_strnew(spec.width - length);
	if (spec.minus_flag == FALSE &&
			spec.zero_flag == TRUE &&
			spec.precision < length)
		ft_memset(*spaces, '0', spec.width - length);
	else
		ft_memset(*spaces, ' ', spec.width - length);
}

void				set_width_to_value(char **value, t_spec spec)
{
	char			*spaces;
	int				length;
	char			*to_del;

	if ((spec.type == s || spec.type == S) && spec.width && spec.precision == 0)
		set_width_to_null_string(value, spec);
	else if (spec.width)
	{
		length = (int)ft_strlen(*value);
		if (spec.width > length)
		{
			if (spec.type == p && spec.zero_flag)
				set_width_to_zero_pointer(value, spec);
			else
			{
				set_spaces(&spaces, spec, length);
				to_del = *value;
				partitial(spec, value, spaces, length);
				ft_strdel(&to_del);
			}
		}
	}
}
