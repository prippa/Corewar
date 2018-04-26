/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:51:03 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/09 12:01:34 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_list(const char *format, t_list **t, char **output)
{
	char	*format_cpy;

	format_cpy = ft_strdup(format);
	*t = NULL;
	*output = ft_strnew(0);
	parse_specs(format_cpy, t);
	ft_strdel(&format_cpy);
	ft_lstrev(t);
}
