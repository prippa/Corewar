/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:47:12 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 14:54:36 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	null_flags(t_spec *spec)
{
	spec->sharp_flag = FALSE;
	spec->zero_flag = FALSE;
	spec->minus_flag = FALSE;
	spec->plus_flag = FALSE;
	spec->space_flag = FALSE;
	spec->asterisk_width = FALSE;
	spec->asterisk_precision = FALSE;
}

void		set_flag1(char **txt_pointer, t_spec *spec)
{
	char	flag;

	null_flags(spec);
	while (is_flag1(**txt_pointer))
	{
		flag = **txt_pointer;
		if (flag == SHARP)
			spec->sharp_flag = TRUE;
		else if (flag == ZERO)
			spec->zero_flag = TRUE;
		else if (flag == MINUS)
			spec->minus_flag = TRUE;
		else if (flag == PLUS)
			spec->plus_flag = TRUE;
		else if (flag == SPACE)
			spec->space_flag = TRUE;
		(*txt_pointer)++;
	}
}
