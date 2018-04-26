/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:30:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 20:06:05 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	big_s(t_pfargs *pf)
{
	pf->spec.type = S;
	join_big_s(pf);
}

static inline void	big_c(t_pfargs *pf)
{
	pf->spec.type = C;
	join_big_c(pf);
}

void				set_value(t_pfargs *pf)
{
	if (pf->spec.type == none)
		join_none(pf);
	else if (pf->spec.type == n)
		join_n(pf);
	else if (pf->spec.type == T)
		join_t(pf);
	else if (pf->spec.type == r)
		join_r(pf);
	else if (pf->spec.type == S || (pf->spec.type == s && pf->spec.flag2 == l))
		big_s(pf);
	else if (pf->spec.type == C || (pf->spec.type == c && pf->spec.flag2 == l))
		big_c(pf);
	else if (pf->spec.type == d || pf->spec.type == i || pf->spec.type == D)
		join_signed_decimal(pf);
	else if (is_unsigned(pf->spec.type))
		join_unsigned_value(pf);
	else if (pf->spec.type == c)
		join_c(pf);
	else if (pf->spec.type == s)
		join_s(pf);
	else if (pf->spec.type == PERCENT)
		join_percent(pf);
	else if (pf->spec.type == p)
		join_p(pf);
}
