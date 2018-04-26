/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:54:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 17:48:08 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_s(t_pfargs *pf)
{
	char	*res;

	res = va_arg(pf->argptr, char *);
	if (!res)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	join_value(&(pf->output), res, pf->spec);
}
