/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_big_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:18:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 17:28:20 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	join_null_big_c(t_pfargs *pf)
{
	join_value(&(pf->output), ft_strdup("*"), pf->spec);
	(pf->output)[(int)ft_strlen(pf->output) - 1] = '\000';
	ft_output(pf->fd, pf->output, &(pf->length));
	ft_strdel(&(pf->output));
	pf->output = ft_strnew(0);
	(pf->length)++;
	write(pf->fd, "\000", 1);
}

void				join_big_c(t_pfargs *pf)
{
	wchar_t			wc;
	wchar_t			*wstr;
	char			*str;

	wc = va_arg(pf->argptr, wchar_t);
	if (!wc)
		join_null_big_c(pf);
	else
	{
		wstr = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		wstr[0] = wc;
		wstr[1] = 0;
		str = ft_wstr_to_str(wstr);
		join_value(&(pf->output), str, pf->spec);
		free(wstr);
	}
}
