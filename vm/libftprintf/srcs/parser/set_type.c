/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:16:50 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/15 15:17:18 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			set_type(char **txt_pointer, t_spec *spec)
{
	if (!(**txt_pointer))
	{
		spec->type = none;
		spec->next_char = '%';
		return ;
	}
	if (is_type(**txt_pointer))
	{
		spec->type = **txt_pointer;
		(*txt_pointer)++;
	}
	else
	{
		spec->type = none;
		spec->next_char = **txt_pointer;
		(*txt_pointer)++;
	}
}
