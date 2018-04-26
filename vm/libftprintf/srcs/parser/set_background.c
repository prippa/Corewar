/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:19:55 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:43:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_asterisk(char **txt_pointer, t_spec *spec)
{
	spec->asterisk_background = TRUE;
	*(txt_pointer) += 3;
}

static void		init_back(t_spec *spec)
{
	spec->background.r = 0;
	spec->background.g = 0;
	spec->background.b = 0;
}

void			set_background(char **txt_pointer, t_spec *spec)
{
	char		*s;

	s = *txt_pointer;
	spec->asterisk_background = FALSE;
	init_back(spec);
	if (s[0] == '[' && ft_strlen(s) > 7 && s[7] == ']')
	{
		if (ft_ishex(s[1]) && ft_ishex(s[2]) && ft_ishex(s[3]) &&
			ft_ishex(s[4]) && ft_ishex(s[5]) && ft_ishex(s[6]))
		{
			spec->background.r = (s[1] <= '9') ?
				(s[1] - '0') * 16 : (s[1] - 87) * 16;
			spec->background.r += (s[2] <= '9') ? (s[2] - '0') : (s[2] - 87);
			spec->background.g = (s[3] <= '9') ?
				(s[3] - '0') * 16 : (s[3] - 87) * 16;
			spec->background.g += (s[4] <= '9') ? (s[4] - '0') : (s[4] - 87);
			spec->background.b = (s[5] <= '9') ?
				(s[5] - '0') * 16 : (s[5] - 87) * 16;
			spec->background.b += (s[6] <= '9') ? (s[6] - '0') : (s[6] - 87);
			(*txt_pointer) += 8;
		}
	}
	else if (s[0] == '[' && ft_strlen(s) > 2 && s[2] == ']' && s[1] == '*')
		set_asterisk(txt_pointer, spec);
}
