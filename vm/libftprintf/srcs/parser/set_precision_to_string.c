/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_to_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:03:38 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:24:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	set_not_null_precision(char **value, t_spec spec)
{
	char			*tmp;
	int				k;

	if (spec.type == s)
	{
		if (spec.precision < (int)ft_strlen(*value))
		{
			tmp = ft_strnew(spec.precision);
			ft_memmove(tmp, *value, spec.precision);
			ft_strdel(&(*value));
			*value = tmp;
		}
	}
	else
	{
		if (spec.precision < (int)ft_strlen(*value))
		{
			if (!(k = (spec.precision / 3) * 3))
				k = 1;
			tmp = ft_strnew(k);
			ft_memmove(tmp, *value, k);
			ft_strdel(&(*value));
			*value = tmp;
		}
	}
}

void				set_precision_to_string(char **value, t_spec spec)
{
	char			*tmp;

	if (spec.precision > 0)
		set_not_null_precision(value, spec);
	else if (spec.precision == 0 && spec.asterisk_precision)
	{
		ft_strdel(&(*value));
		*value = ft_strnew(0);
	}
	else if (spec.precision == 0)
	{
		if (spec.type == s)
		{
			tmp = *value;
			if (tmp)
				while (*tmp)
					*tmp++ = ' ';
		}
		else
		{
			ft_strdel(&(*value));
			*value = ft_strnew(0);
		}
	}
}
