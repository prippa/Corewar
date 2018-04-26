/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:03:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 18:12:23 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		join_percent(t_pfargs *pf)
{
	char	*to_del;

	to_del = pf->output;
	pf->output = ft_strjoin(pf->output, "\045");
	ft_strdel(&to_del);
}
