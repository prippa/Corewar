/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plus_and_space_to_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:02:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:03:08 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	set_plus_flag(char **value, t_spec spec)
{
	char			*to_del;

	to_del = NULL;
	if (**value != '-')
	{
		if (is_unsigned(spec.type) == FALSE)
		{
			to_del = *value;
			*value = ft_strjoin("+", *value);
			ft_strdel(&to_del);
		}
	}
}

static inline void	set_space_flag(char **value, t_spec spec)
{
	char			*to_del;

	to_del = NULL;
	if (**value != '-')
	{
		if (spec.type == d || spec.type == i)
		{
			to_del = *value;
			*value = ft_strjoin("\40", *value);
			ft_strdel(&to_del);
		}
	}
}

void				set_plus_and_space_to_value(char **value,
	t_spec spec)
{
	if (is_numeric_type(spec.type))
	{
		if (spec.plus_flag)
			set_plus_flag(value, spec);
		else if (spec.space_flag)
			set_space_flag(value, spec);
	}
}
