/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:22:21 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:44:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				set_asterisk(char **txt_pointer, t_spec *spec)
{
	spec->asterisk_color = TRUE;
	*(txt_pointer) += 3;
}

static void				init_col(t_spec *spec)
{
	spec->color.r = 0;
	spec->color.g = 0;
	spec->color.b = 0;
}

void					set_color(char **txt_pointer, t_spec *spec)
{
	char				*s;

	init_col(spec);
	s = *txt_pointer;
	spec->asterisk_color = FALSE;
	if (s[0] == '{' && ft_strlen(s) > 7 && s[7] == '}')
	{
		if (ft_ishex(s[1]) && ft_ishex(s[2]) && ft_ishex(s[3]) &&
			ft_ishex(s[4]) && ft_ishex(s[5]) && ft_ishex(s[6]))
		{
			spec->color.r = (s[1] <= '9') ?
				(s[1] - '0') * 16 : (s[1] - 87) * 16;
			spec->color.r += (s[2] <= '9') ? (s[2] - '0') : (s[2] - 87);
			spec->color.g = (s[3] <= '9') ?
				(s[3] - '0') * 16 : (s[3] - 87) * 16;
			spec->color.g += (s[4] <= '9') ? (s[4] - '0') : (s[4] - 87);
			spec->color.b = (s[5] <= '9') ?
				(s[5] - '0') * 16 : (s[5] - 87) * 16;
			spec->color.b += (s[6] <= '9') ? (s[6] - '0') : (s[6] - 87);
			(*txt_pointer) += 8;
		}
	}
	else if (s[0] == '{' && ft_strlen(s) > 2 && s[2] == '}' && s[1] == '*')
		set_asterisk(txt_pointer, spec);
}
