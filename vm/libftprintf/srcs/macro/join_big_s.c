/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_big_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:09:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 17:15:19 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_big_s(t_pfargs *pf)
{
	wchar_t	*wc;

	wc = va_arg(pf->argptr, wchar_t *);
	if (wc)
		join_value(&(pf->output), ft_wstr_to_str(wc), pf->spec);
	else
		join_value(&(pf->output), ft_strdup("(null)"), pf->spec);
}
