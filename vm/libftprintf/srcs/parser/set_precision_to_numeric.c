/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_to_numeric.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:13:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:25:32 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	partitial(char **to_del1,
		char **zeros, char **value)
{
	if (**value == '-')
	{
		*to_del1 = *zeros;
		*zeros = ft_strjoin("-0", *zeros);
		*value = ft_strjoin(*zeros, *value + 1);
	}
	else if (**value == '+')
	{
		*to_del1 = *zeros;
		*zeros = ft_strjoin("+0", *zeros);
		*value = ft_strjoin(*zeros, *value + 1);
	}
	else
		*value = ft_strjoin(*zeros, *value);
}

static inline void	set_not_null_bigger_precision(char **value,
	t_spec spec, int length)
{
	char			*zeros;
	char			*to_del1;
	char			*to_del2;

	to_del1 = NULL;
	to_del2 = NULL;
	zeros = ft_strnew(spec.precision - length);
	ft_memset(zeros, '0', spec.precision - length);
	to_del2 = *value;
	if (spec.space_flag == FALSE || (spec.type != i && spec.type != d))
		partitial(&to_del1, &zeros, value);
	else
	{
		to_del1 = zeros;
		zeros = ft_strjoin("\040", zeros);
		*value = ft_strjoin(zeros, *value + 1);
	}
	ft_strdel(&zeros);
	if (to_del1)
		ft_strdel(&to_del1);
	if (to_del2)
		ft_strdel(&to_del2);
}

static inline void	set_not_null_precision(char **value, t_spec spec)
{
	int				length;
	char			*to_del;

	to_del = NULL;
	length = (int)ft_strlen(*value);
	if (spec.space_flag)
		length--;
	if (spec.precision > length)
		set_not_null_bigger_precision(value, spec, length);
	else if (spec.precision == length && **value == '+')
	{
		to_del = *value;
		*value = ft_strjoin("+0", *value + 1);
	}
	else if (spec.precision == length && **value == '-')
	{
		to_del = *value;
		*value = ft_strjoin("-0", *value + 1);
	}
	if (to_del)
		ft_strdel(&to_del);
}

static inline void	set_null_precision(char **value, t_spec spec)
{
	int				len;

	len = (int)ft_strlen(*value);
	if (spec.sharp_flag == FALSE)
	{
		if ((*value)[len - 1] == 48)
			(*value)[len - 1] = '\000';
	}
	else if (spec.sharp_flag == TRUE &&
		(spec.type == x || spec.type == X))
	{
		if ((*value)[len - 1] == 48)
		{
			ft_strdel(value);
			(*value) = ft_strnew(0);
			spec.sharp_flag = FALSE;
		}
	}
}

void				set_precision_to_numeric(char **value, t_spec spec)
{
	if (spec.precision)
		set_not_null_precision(value, spec);
	else
		set_null_precision(value, spec);
}
