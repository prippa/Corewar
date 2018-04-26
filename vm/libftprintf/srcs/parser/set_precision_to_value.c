/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_to_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:33:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/16 15:34:01 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				set_precision_to_value(char **value, t_spec spec)
{
	if (spec.type == p)
		set_precision_to_pointer(value, spec);
	if (is_numeric_type(spec.type))
		set_precision_to_numeric(value, spec);
	else if (spec.type == s || spec.type == S)
		set_precision_to_string(value, spec);
}
