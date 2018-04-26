/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_unsigned_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:42:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:19:34 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool				is_flag2(t_flag2 f2)
{
	if (f2 == hh || f2 == h || f2 == l ||
			f2 == ll || f2 == j || f2 == z)
		return (TRUE);
	return (FALSE);
}

static inline void			short_cast_join(t_pfargs *pf,
	t_flag2 f2, t_type t,
	unsigned long long int uv)
{
	char					*to_del;

	if (f2 == hh)
		uv = (unsigned char)uv;
	else if (f2 == h)
		uv = (unsigned short int)uv;
	else if (f2 == l)
		uv = (unsigned long int)uv;
	if (t == u || t == U)
		join_value(&(pf->output), ft_ulltoa(uv), pf->spec);
	else if (t == o || t == O)
		join_value(&(pf->output), ft_ulltoa_base(uv, 8), pf->spec);
	else if (t == b || t == B)
		join_value(&(pf->output), ft_ulltoa_base(uv, 2), pf->spec);
	else if (t == X)
		join_value(&(pf->output), ft_ulltoa_base(uv, 16), pf->spec);
	else if (t == x)
	{
		to_del = ft_ulltoa_base(uv, 16);
		join_value(&(pf->output), ft_strtolower(to_del), pf->spec);
		ft_strdel(&to_del);
	}
}

static inline void			long_cast_join(t_pfargs *pf,
	t_type t,
	unsigned long long int uv)
{
	char					*to_del;

	if (t == u)
		join_value(&(pf->output), ft_ulltoa((unsigned int)uv), pf->spec);
	else if (t == U)
		join_value(&(pf->output), ft_ulltoa(uv), pf->spec);
	else if (t == o)
		join_value(&(pf->output),
				ft_ulltoa_base((unsigned int)uv, 8), pf->spec);
	else if (t == O)
		join_value(&(pf->output), ft_ulltoa_base(uv, 8), pf->spec);
	else if (t == b)
		join_value(&(pf->output),
				ft_ulltoa_base((unsigned int)uv, 2), pf->spec);
	else if (t == B)
		join_value(&(pf->output), ft_ulltoa_base(uv, 2), pf->spec);
	else if (t == X)
		join_value(&(pf->output),
				ft_ulltoa_base((unsigned int)uv, 16), pf->spec);
	else if (t == x)
	{
		to_del = ft_ulltoa_base((unsigned int)uv, 16);
		join_value(&(pf->output), ft_strtolower(to_del), pf->spec);
		ft_strdel(&to_del);
	}
}

void						join_unsigned_value(t_pfargs *pf)
{
	unsigned long long int	uv;
	t_flag2					f2;
	t_type					t;

	uv = va_arg(pf->argptr, unsigned long long int);
	f2 = pf->spec.flag2;
	t = pf->spec.type;
	if (t != O && t != U && is_flag2(f2))
		short_cast_join(pf, f2, t, uv);
	else
		long_cast_join(pf, t, uv);
}
