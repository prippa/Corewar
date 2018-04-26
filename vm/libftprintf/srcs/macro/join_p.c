/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:16:23 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 17:47:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_p(t_pfargs *pf)
{
	char	*to_del;
	char	*element;

	to_del = ft_ulltoa_base(va_arg(pf->argptr, unsigned long long), 16);
	element = ft_strtolower(to_del);
	ft_strdel(&to_del);
	to_del = element;
	element = ft_strjoin("0x", to_del);
	ft_strdel(&to_del);
	join_value(&(pf->output), element, pf->spec);
}
