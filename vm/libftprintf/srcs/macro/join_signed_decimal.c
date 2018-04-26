/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signed_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:57:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:03:41 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					join_signed_decimal(t_pfargs *pf)
{
	long long int		v;
	t_flag2				f2;
	t_type				t;

	v = va_arg(pf->argptr, long long int);
	f2 = pf->spec.flag2;
	t = pf->spec.type;
	if (t != D && (f2 == h || f2 == l || f2 == ll ||
				f2 == j || f2 == z || f2 == hh))
	{
		if (f2 == hh)
			v = (signed char)v;
		else if (f2 == h)
			v = (short int)v;
		else if (f2 == l)
			v = (long int)v;
		join_value(&(pf->output), ft_lltoa(v), pf->spec);
	}
	else
	{
		if (t == i || t == d)
			join_value(&(pf->output), ft_lltoa((int)v), pf->spec);
		else if (t == D)
			join_value(&(pf->output), ft_lltoa(v), pf->spec);
	}
}
