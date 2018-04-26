/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:38:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 14:39:00 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec			get_spec(char **txt_pointer)
{
	t_spec		spec;

	set_background(txt_pointer, &spec);
	set_color(txt_pointer, &spec);
	set_flag1(txt_pointer, &spec);
	set_width(txt_pointer, &spec);
	set_precision(txt_pointer, &spec);
	set_flag2(txt_pointer, &spec);
	set_type(txt_pointer, &spec);
	return (spec);
}
