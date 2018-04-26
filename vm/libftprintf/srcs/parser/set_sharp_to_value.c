/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sharp_to_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:23:18 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 19:19:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_sharp_to_value(char **value, t_spec spec)
{
	if (**value == '\000')
		return ;
	if (**value == 48 && !(*(*value + 1)))
		return ;
	if (spec.sharp_flag == TRUE)
	{
		if (spec.type == x || spec.type == X ||
				spec.type == b || spec.type == B ||
				spec.type == o || spec.type == O)
		{
			if (spec.type == x)
				*value = ft_strjoin_free("0x", *value, FALSE, TRUE);
			else if (spec.type == X)
				*value = ft_strjoin_free("0X", *value, FALSE, TRUE);
			else if (spec.precision < (int)ft_strlen(*value) && **value != 48)
				*value = ft_strjoin_free("0", *value, FALSE, TRUE);
		}
	}
}
