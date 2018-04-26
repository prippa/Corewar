/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asterisk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:19:52 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 17:19:54 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	background_set(t_pfargs *pf)
{
	int				color_nbr;
	t_color			color;

	color_nbr = va_arg(pf->argptr, int);
	color.r = (unsigned char)(color_nbr >> 16);
	color.g = (unsigned char)((color_nbr << 16) >> 24);
	color.b = (unsigned char)color_nbr;
	pf->spec.background = color;
}

static inline void	color_set(t_pfargs *pf)
{
	int				color_nbr;
	t_color			color;

	color_nbr = va_arg(pf->argptr, int);
	color.r = (unsigned char)(color_nbr >> 16);
	color.g = (unsigned char)((color_nbr << 16) >> 24);
	color.b = (unsigned char)color_nbr;
	pf->spec.color = color;
}

void				check_asterisk(t_pfargs *pf)
{
	if (pf->spec.width && pf->spec.asterisk_width)
		va_arg(pf->argptr, void *);
	else if (pf->spec.asterisk_width)
		pf->spec.width = va_arg(pf->argptr, int);
	if (pf->spec.width < 0)
	{
		pf->spec.width *= -1;
		pf->spec.minus_flag = TRUE;
	}
	if (pf->spec.asterisk_precision)
		pf->spec.precision = va_arg(pf->argptr, int);
	if (pf->spec.asterisk_background)
		background_set(pf);
	if (pf->spec.asterisk_color)
		color_set(pf);
}
