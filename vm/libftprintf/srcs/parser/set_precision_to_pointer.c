/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_to_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:09:35 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:04:05 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	set_precision_to_null(char **value, t_spec spec)
{
	char			*zeros;
	char			*to_del;

	if (spec.precision >= 0)
	{
		ft_strdel(value);
		*value = ft_strdup("0x");
		if (spec.precision >= 1)
		{
			zeros = ft_strnew(spec.precision);
			ft_memset(zeros, '0', spec.precision);
			to_del = *value;
			*value = ft_strjoin(*value, zeros);
			ft_strdel(&zeros);
			ft_strdel(&to_del);
		}
	}
}

void				set_precision_to_pointer(char **value, t_spec spec)
{
	char			*zeros;
	char			*to_del;
	int				p_len;

	if (is_null_pointer(*value))
		set_precision_to_null(value, spec);
	else
	{
		p_len = (int)ft_strlen((*value + 2));
		if (p_len < spec.precision)
		{
			zeros = ft_strnew(spec.precision - p_len);
			ft_memset(to_del = zeros, '0', spec.precision - p_len);
			zeros = ft_strjoin("0x", zeros);
			ft_strdel(&to_del);
			to_del = *value;
			*value = ft_strjoin(zeros, *value + 2);
			ft_strdel(&to_del);
		}
	}
}
