/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:02:44 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 18:01:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				join_r(t_pfargs *pf)
{
	unsigned char	*np;
	char			*octal;
	char			*a;
	char			*nbr;

	np = va_arg(pf->argptr, unsigned char *);
	octal = ft_strnew(0);
	while (*np)
	{
		a = ft_ulltoa_base(*np, 8);
		if (ft_strlen(a) == 2)
			a = ft_strjoin_free("0", a, FALSE, TRUE);
		else if (ft_strlen(a) == 1)
			a = ft_strjoin_free("00", a, FALSE, TRUE);
		nbr = ft_strjoin_free("\134", a, FALSE, TRUE);
		octal = ft_strjoin_free(octal, nbr, TRUE, TRUE);
		np++;
	}
	octal = ft_strjoin_free(octal, "\134000", TRUE, FALSE);
	join_value(&(pf->output), octal, pf->spec);
}
