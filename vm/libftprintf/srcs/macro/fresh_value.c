/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:51:58 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/09 12:00:07 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_value		fresh_value(t_type t, void *data, size_t count)
{
	t_value	sp;

	sp.spec.type = t;
	if (!data)
		sp.value = NULL;
	else
	{
		sp.value = ft_strnew(count);
		ft_memmove(sp.value, data, count);
	}
	sp.spec.asterisk_width = FALSE;
	sp.spec.asterisk_precision = FALSE;
	sp.spec.asterisk_color = FALSE;
	sp.spec.asterisk_background = FALSE;
	sp.spec.width = 0;
	sp.spec.precision = 1;
	return (sp);
}
